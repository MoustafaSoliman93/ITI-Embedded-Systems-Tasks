/*
 * HDIO.h
 *
 * Created: 10/15/2022 5:45:16 PM
 *  Author: moust
 */ 


#ifndef HDIO_H_
#define HDIO_H_

#include "../../../MCAL/DIO/header/DIO_interface.h"

#define A PORTA
#define B PORTB
#define C PORTC
#define D PORTD

#define IN  INPUT
#define OUT OUTPUT

void HDIO_SetPinDirection_vid (u8 PORT , u8 PIN , u8 direction);
u8   HDIO_ReadPinValue_u8     (u8 PORT , u8 PIN);
void HDIO_SetPinValue_vid     (u8 PORT , u8 PIN , u8 state);
void HDIO_PinToggle_vid       (u8 PORT , u8 PIN);
void HDIO_PinPullUp_vid       (u8 PORT , u8 PIN);

#endif /* HDIO_H_ */