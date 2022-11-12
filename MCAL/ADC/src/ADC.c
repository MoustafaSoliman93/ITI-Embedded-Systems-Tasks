/*
 * ADC.c
 *
 * Created: 11/4/2022 10:34:28 AM
 *  Author: Moustafa
 */ 

#include "ADC_interface.h"

ADC_Chain* Chain_global;
static ADC_State State = IDLE;
u16* ADC_Result = NULL;
void (*ADC_END)(void);
static u8 local;

void ADC_init()
{
	/***********     SET ADC REF   ************/
	local = ADMUX;
	local &= CLR_ADC_REF;
	local |= (ADC_REF << REFS0);
	ADMUX = local;
	/********** SET DATA ADJUSTMENT ***********/
	local = ADMUX;
	local &= CLR_LeftAdjustResult;
	local |= (LeftAdjustResult << ADLAR);
	ADMUX |= local;
	/*********** SET ADC PRESCALER ************/
	local = ADCSRA;
	local &= CLR_PRESCALER;
	local |= (ADC_Prescaler << ADPS0);
	ADCSRA = local;
	/******** SET ADC AUTO TRIGGERING *********/
	#if ADCAutoTriggercfg
	    /***** Enable Auto Triggering*****/
	local = ADCSRA;
	local &= ~(1 << ADATE);
	local |= (ADCAutoTriggercfg << ADATE);
	ADCSRA = local;
	    /*** Set Auto Triggering Source ***/
	local = SFIOR;
	local &= CLR_ADC_AUTO_TRIGGER_SOURCE;
	local |= (ADCAutoTriggerSource << ADTS0); 
	SFIOR = local;
	#endif
	/***********    ENABLE ADC     ************/
	ADCSRA |= (1 << ADEN);
}
Error_Status ADC_StartConvSync(u8 channel,u16*result)
{
	Error_Status ADC_Error_Status = OK;
	if(State == IDLE)
	{
		State = SYNC_BUSY;
		u16 TimeOutCounter = 0;
		/***********  SET ADC CHANNEL  ************/
		DIO_cfg CHANNEL = {PORTA,channel,INPUT};
		DIO_SetPinDirection (&CHANNEL);
		u8 Local = ADMUX;
		Local &= CLR_CHANNEL;
		Local |= (channel << MUX0);
		ADMUX = Local;
		/***********  START CONVERSION ************/
		ADCSRA |= (StartConv << ADSC);
		while((((1 << ADIF)& ADCSRA) == 0) && (TimeOutCounter < 1000))
		{
			TimeOutCounter++;
		}
		if (TimeOutCounter == 1000)
		{
			ADC_Error_Status = NOK;
		}
		else
		{
			#if Adjust_Result == LeftAdjustResult
			*result = (u16)(ADCH << 8);
			*result |= ADCL;
			#elif Adjust_Result == RightAdjustResult
			*result = (u16)(ADCL >> 6);
			*result |= (u16)(ADCH << 2);
			#endif
		}
	}else
	{
		ADC_Error_Status = NOK;
	}
	State = IDLE;
	return ADC_Error_Status;
}
/*
Error_Status ADC_StartConvAsync(u8 channel,u16*result,void(*ptrFun)(void))
{
	u8 ADC_Error_Status = OK;
	if(channel > channel_7 || channel < channel_0)
	{
		ADC_Error_Status = NOK;
	}
	ADC_Result = result;
	ADC_END = ptrFun;
	/ ***********  SET ADC CHANNEL  ************ /
	u8 Local = ADMUX;
	Local &= CLR_CHANNEL;
	Local |= (channel << MUX0);
	ADMUX = Local;
	/ ********** ENABLE ADC INTERRUPT ********** /
	ADCSRA |= (1 << ADEN);
	/ ***********  START CONVERSION ************ /
	ADCSRA |= (StartConv << ADSC);
	return ADC_Error_Status;
}*/


Error_Status ADC_StartConvAsync_chain(ADC_Chain* chain)
{
	Error_Status ADC_Error_Status = OK;
	if (State == SYNC_BUSY)
	{
		ADC_Error_Status = NOK;
	}
	else
	{
		State = CHAIN_BUSY;
		static u8 count = 0;
		Chain_global = chain;
		if (count < chain->length)
		{
			if(chain->channel[count] > channel_7)
			{
				ADC_Error_Status = NOK;
			}
			else
			{
				ADC_Result = &(chain->result[count]);
				ADC_END = chain->ptrToPtrToFun[count];
				/***********  SET ADC CHANNEL  ************/
				//HDIO_SetPinDirection_vid(A,chain->channel[count],INPUT);
				u8 Local = ADMUX;
				Local &= CLR_CHANNEL;
				Local |= (chain->channel[count] << MUX0);
				ADMUX = Local;
				/********** ENABLE ADC INTERRUPT **********/
				ADCSRA |= (1 << ADIE);
				/***********  START CONVERSION ************/
				ADCSRA |= (1 << ADSC);
				count++;
			}
		}
		else
		{
			ADC_Error_Status = FINISH;
			State = IDLE;
		}
	}
	return ADC_Error_Status;
}

ISR(ADC_vect)
{
	#if Adjust_Result == LeftAdjustResult
	*ADC_Result = (u16)(ADCL >> 6);
	*ADC_Result |= (u16)(ADCH << 2);
	#elif Adjust_Result == RightAdjustResult
	*ADC_Result = (u16)(ADCH << 8);
	*ADC_Result |= ADCL;
	#endif
	ADC_END();
	ADC_StartConvAsync_chain(Chain_global);
}