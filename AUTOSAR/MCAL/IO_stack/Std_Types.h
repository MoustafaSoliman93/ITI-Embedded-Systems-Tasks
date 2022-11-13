/*
 * Std_Types.h
 *
 * Created: 11/12/2022 4:08:15 PM
 *  Author: Moustafa
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include "stdTypes.h"

typedef enum {
	E_OK,
	E_NOT_OK
}Std_ReturnType;

typedef enum{
	STD_LOW,
	STD_HIGH
}Dio_LevelType; 

typedef struct{
	uint8 mask;
	uint8 offset;
	uint8 port;
}Dio_ChannelGroupType;

typedef uint32 Dio_ChannelType;
typedef uint8  Dio_PortType;
typedef uint8 Dio_PortLevelType;

#endif /* STD_TYPES_H_ */