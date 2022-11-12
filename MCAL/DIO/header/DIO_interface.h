/*
 * DIO_interface.h
 *
 *  Created on: Oct 8, 2022
 *      Author: moust
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#include "../../../utilities/Bit math/BitMath.h"
#include "../../../utilities/std types/std_types.h"
#include "../registers/DIO_register.h"


#define INPUT  0
#define OUTPUT 1
#define HIGH   1
#define LOW    0

typedef enum
{
	NO_ERR , FAILED
}ERR_DIO;

typedef struct
{
	u8 port;
	u8 pin;
	u8 direction;
	u8 error;
}DIO_cfg;


void DIO_SetPinDirection (DIO_cfg * DioConfig);
u8 DIO_ReadPinValue (DIO_cfg * DioConfig);
void DIO_SetPinValue (DIO_cfg * DioConfig,u8 state);
void DIO_PinToggle (DIO_cfg * DioConfig);
void DIO_PinPullUp (DIO_cfg * DioConfig);


#endif /* DIO_INTERFACE_H_ */
