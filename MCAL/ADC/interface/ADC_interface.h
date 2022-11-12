/*
 * interface.h
 *
 * Created: 11/4/2022 10:34:16 AM
 *  Author: Moustafa
 */ 



#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "ADC_cfg.h"
#include "ADC_private.h"
#include "std_types.h"
#include "DIO_interface.h"

typedef enum {
	OK,
	NOK,
	FINISH
} Error_Status;
typedef enum{
	IDLE,
	SYNC_BUSY,
	CHAIN_BUSY
} ADC_State;

typedef struct
{
	u8 length;
	u16* result;
	u8* channel;
	void(*(*ptrToPtrToFun))(void);
}ADC_Chain;

void ADC_init();
Error_Status ADC_StartConvSync(u8 channel,u16* result); // channel ---> channel_0 : channel_7
Error_Status ADC_StartConvAsync_chain(ADC_Chain* chain);
//Error_Status ADC_StartConvAsync(u8 channel,u16* result,void(*ptrFun)(void)); // channel ---> channel_0 : channel_7
#endif /* INTERFACE_H_ */