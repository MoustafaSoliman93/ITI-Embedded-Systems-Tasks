/*
 * DIO.h
 *
 * Created: 11/12/2022 4:27:31 PM
 *  Author: Moustafa
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "Std_Types.h"
#include "stdTypes.h"
#include "DIO_Reg.h"
#include "Bit_Math.h"


#define CHANNEL_0      0x3900
#define CHANNEL_1      0x3901
#define CHANNEL_2      0x3902
#define CHANNEL_3      0x3903
#define CHANNEL_4      0x3904
#define CHANNEL_5      0x3905
#define CHANNEL_6      0x3906
#define CHANNEL_7      0x3907
#define CHANNEL_8      0x3600
#define CHANNEL_9      0x3601
#define CHANNEL_10     0x3602
#define CHANNEL_11     0x3603
#define CHANNEL_12     0x3604
#define CHANNEL_13     0x3605
#define CHANNEL_14     0x3606
#define CHANNEL_15     0x3607
#define CHANNEL_16     0x3300
#define CHANNEL_17     0x3301
#define CHANNEL_18     0x3302
#define CHANNEL_19     0x3303
#define CHANNEL_20     0x3304
#define CHANNEL_21     0x3305
#define CHANNEL_22     0x3306
#define CHANNEL_23     0x3307
#define CHANNEL_24     0x3000
#define CHANNEL_25     0x3001
#define CHANNEL_26     0x3002
#define CHANNEL_27     0x3003
#define CHANNEL_28     0x3004
#define CHANNEL_29     0x3005
#define CHANNEL_30     0x3006
#define CHANNEL_31     0x3007

Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level);
Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr);
void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);
Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId);

#endif /* DIO_H_ */