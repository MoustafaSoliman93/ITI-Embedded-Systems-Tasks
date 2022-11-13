/*
 * DIO.c
 *
 * Created: 11/12/2022 6:15:17 PM
 *  Author: Moustafa
 */ 

#include "DIO.h"

Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId){
	Dio_LevelType Channel_Level;
	
	uint8* PORT = (uint8 *)((ChannelId >> 8) + PIN_RegOffset);
	uint8 PIN_Num = (uint8)(0x00ff & ChannelId);
	
	if (READ_BIT(PORT,PIN_Num) == 0){
		Channel_Level = STD_LOW;
	}
	else{
		Channel_Level = STD_HIGH;
	}
	return Channel_Level;
}
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level){
	uint8* PORT = (uint8 *)((ChannelId >> 8) + PORT_RegOffset);
	uint8 PIN_Num = (uint8)(0x00ff & ChannelId);
	switch (Level){
		case STD_LOW:
			CLR_BIT(PORT,PIN_Num);
			break;
		case STD_HIGH:
			SET_BIT(PORT,PIN_Num);
			break;
	}
}
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId){
	Dio_PortLevelType PortLevelType = *((uint8*)(PortId + PIN_RegOffset));
	return PortLevelType;
}
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level){
	*((uint8 *)(PortId + PORT_RegOffset)) = Level;
}
Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr){
	Dio_PortLevelType ChannelGroupLevel;
	uint8 * PIN_REG = (uint8*)(ChannelGroupIdPtr->port + PIN_RegOffset);
	ChannelGroupLevel = (*PIN_REG & ChannelGroupIdPtr->mask) >> ChannelGroupIdPtr->offset;
	return ChannelGroupLevel;
}
void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level){
	Dio_PortLevelType ChannelGroupLevel;
	ChannelGroupLevel = *PORT_Ptr(ChannelGroupIdPtr->port + PORT_RegOffset);
	ChannelGroupLevel &= ~(ChannelGroupIdPtr->mask);
	ChannelGroupLevel |= (Level << ChannelGroupIdPtr->offset);
	*PORT_Ptr(ChannelGroupIdPtr->port + PORT_RegOffset) = ChannelGroupLevel;
}
Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId){
	Dio_LevelType ChannelLevel;
	uint8* PIN = (uint8 *)((ChannelId >> 8) + PIN_RegOffset);
	uint8* PORT = (uint8 *)((ChannelId >> 8) + PORT_RegOffset);
	uint8 PIN_Num = (uint8)(0x00ff & ChannelId);
	TOGGLE_BIT(PORT,PIN_Num);
	if (READ_BIT(PIN,PIN_Num) == 0){
		ChannelLevel = STD_LOW;		
	}
	else{
		ChannelLevel = STD_HIGH;
	}
	return ChannelLevel;
}