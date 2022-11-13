/*
 * Registers.h
 *
 * Created: 11/12/2022 5:53:42 PM
 *  Author: Moustafa
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#define PORT_Ptr(PORT)   ((volatile uint8 *)PORT)

#define PORTA_ID       (0x39)
#define PORTB_ID       (0x36)
#define PORTC_ID       (0x33)
#define PORTD_ID       (0x30)

#define PORT_RegOffset   2
#define PIN_RegOffset    0



#endif /* REGISTERS_H_ */