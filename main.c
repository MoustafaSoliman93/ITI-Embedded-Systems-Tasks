/*
 * main.c
 *
 *  Created on: Oct 9, 2022
 *      Author: moust
 */
#define F_CPU 8000000u
#include "util/delay.h"
#include <stdio.h>
#include "HDIO.h"
#include "ADC_interface.h"

#define SREG *((volatile u8*)0x5F)
#define I 7

int x;


void func1(void)
{
	x = 1;
}

void func2(void)
{
	x = 2;
}

void func3(void)
{
	x = 3;
}

int main ()
{
	SREG |= 1 << I;
	u16 myResult[3] = {0};
	u8 myChannel[3] = {0,1,2};
	void (*(funArr[3]))(void) = {func1,func2,func3};
	
	ADC_Chain myChain = {3,myResult,myChannel,funArr};
	ADC_init();
	ADC_StartConvAsync_chain(&myChain);
	
	while (1)
	{
		while (ADCSRA & (1 << ADIF))
		{
		}
	}
}

