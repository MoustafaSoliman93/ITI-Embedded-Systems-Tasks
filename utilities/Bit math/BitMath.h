/*
 * BitMath.h
 *
 *  Created on: Oct 8, 2022
 *      Author: moust
 */

#ifndef BITMATH_H_
#define BITMATH_H_

#include "../std types/std_types.h"
#define ADD(IO_ADD) (*((volatile u8*)(IO_ADD)))

#define SET_BIT(PORT, BIT)      (ADD(PORT)) |= (1 << (BIT))
#define CLR_BIT(PORT, BIT)      (ADD(PORT)) &= ~(1 << (BIT))
#define TOGGLE_BIT(PORT, BIT)   (ADD(PORT)) ^= (1 << (BIT))
#define READ_BIT(PORT, BIT)     (((ADD(PORT)) & (1 << (BIT))) >> BIT)


#endif /* BITMATH_H_ */
