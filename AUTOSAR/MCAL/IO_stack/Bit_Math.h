/*
 * Bit_Math.h
 *
 * Created: 11/12/2022 6:19:07 PM
 *  Author: Moustafa
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(PORT,PIN)		(*(PORT_Ptr(PORT)) |= (1 << (PIN)))
#define CLR_BIT(PORT,PIN)		(*(PORT_Ptr(PORT)) &= ~(1 << (PIN)))
#define READ_BIT(PORT,PIN)		((*(PORT_Ptr(PORT)) & (1<<PIN)) >> (PIN))
#define TOGGLE_BIT(PORT,PIN)	(*(PORT_Ptr(PORT)) ^= (1 << (PIN)))



#endif /* BIT_MATH_H_ */