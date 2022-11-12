/*
 * cfg.h
 *
 * Created: 11/4/2022 10:33:55 AM
 *  Author: Moustafa
 */ 


#ifndef CFG_H_
#define CFG_H_
/*
	ADC_REF ---> AREF / AVCC / INTERNAL
	
	Adjust_Result ---> LeftAdjustResult / RightAdjustResult
	
	ADC_Prescaler ---> Devby2 / Devby4 / Devby8 / Devby16 / Devby32 / Devby64 / Devby128
	
	ADCAutoTriggercfg ---> Enabled / Disabled
	
	ADCAutoTriggerSource ---> FreeRunningMode / AnalogComparator / ExternalInterruptRequest /
						 ---> Timer_Counter0CompareMatch / Timer_Counter0Overflow / Timer_CounterCompareMatch /
						 --->  Timer_Counter1Overflow / Timer_Counter1CaptureEvent
*/

#define ADC_REF			AVCC
#define Adjust_Result	RightAdjustResult
#define ADC_Prescaler	Devby2

#define ADCAutoTriggercfg	  Disabled
#define ADCAutoTriggerSource  

#endif /* CFG_H_ */