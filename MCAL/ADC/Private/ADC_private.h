/*
 * private.h
 *
 * Created: 11/4/2022 10:34:46 AM
 *  Author: Moustafa
 */ 


#ifndef PRIVATE_H_
#define PRIVATE_H_

#include <avr/interrupt.h>
#include "std_types.h"


#define AREF	 0
#define AVCC	 1
#define INTERNAL 3

#define LeftAdjustResult  1
#define RightAdjustResult 0

#define channel_0	0
#define channel_1	1
#define channel_2	2
#define channel_3	3
#define channel_4	4
#define channel_5	5
#define channel_6	6
#define channel_7	7

#define Devby2		1
#define Devby4		2
#define Devby8		3
#define Devby16		4
#define Devby32		5
#define Devby64		6
#define Devby128	7

#define FreeRunningMode				0
#define AnalogComparator			1
#define ExternalInterruptRequest	2
#define Timer_Counter0CompareMatch	3
#define Timer_Counter0Overflow		4
#define Timer_CounterCompareMatch	5
#define Timer_Counter1Overflow		6
#define Timer_Counter1CaptureEvent	7

#define NULL		((void*)0)
#define Enabled		1
#define Disabled	0
#define StartConv	1

#define CLR_CHANNEL                   0xE0
#define CLR_ADC_REF                   0x3F
#define CLR_LeftAdjustResult          0xDF
#define CLR_PRESCALER                 0xF8
#define CLR_ADC_AUTO_TRIGGER_SOURCE   0x1F

#endif /* PRIVATE_H_ */