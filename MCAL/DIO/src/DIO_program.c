/*
 * DIO.c
 *
 *  Created on: Oct 8, 2022
 *      Author: moust
 */
#include "../header/DIO_interface.h"

typedef struct
{
	volatile u8 PIN;
	volatile u8 DDR;
	volatile u8 PORT;
}PORTx;

void DIO_SetPinDirection (DIO_cfg * DioConfig)
{
	PORTx * PORT_t = (PORTx *)(DioConfig->port);

	if (DioConfig->direction == INPUT)
	{
		CLR_BIT(&(PORT_t->DDR), DioConfig->pin);
		DioConfig->error = NO_ERR;
	}
	else if(DioConfig->direction == OUTPUT)
	{
		SET_BIT(&(PORT_t->DDR), DioConfig->pin);
		DioConfig->error = NO_ERR;
	}
	else
	{
		DioConfig->error = FAILED;
	}
}
u8 DIO_ReadPinValue (DIO_cfg * DioConfig)
{
	PORTx * PORT_t = (PORTx *)(DioConfig->port);
	return READ_BIT(&(PORT_t->PIN), DioConfig->pin);
}

void DIO_SetPinValue (DIO_cfg * DioConfig,u8 state)
{
	PORTx * PORT_t = (PORTx *)(DioConfig->port);
	if (state == HIGH)
	{
		SET_BIT(&(PORT_t->PORT), DioConfig->pin);
		DioConfig->error = NO_ERR;
	}
	else if(state == LOW)
	{
		CLR_BIT(&(PORT_t->PORT), DioConfig->pin);
		DioConfig->error = NO_ERR;
	}
	else
	{
		DioConfig->error = FAILED;
	}
}
void DIO_PinToggle (DIO_cfg* DioConfig)
{
	PORTx * PORT_t = (PORTx *)(DioConfig->port);
	TOGGLE_BIT(&(PORT_t->PORT),DioConfig->pin);
}
void DIO_PinPullUp (DIO_cfg* DioConfig)
{
	PORTx * PORT_t = (PORTx *)(DioConfig->port);
	SET_BIT(&(PORT_t->PORT), DioConfig->pin);
}
