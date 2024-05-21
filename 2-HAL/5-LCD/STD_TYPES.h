/*
 * kk.h
 *
 *  Created on: Nov 18, 2023
 *      Author: Ahmed Elshazly
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*for character only */
typedef unsigned char u8 ;
typedef signed char   s8 ;

/*for integer only */
typedef unsigned short int      u16 ;
typedef signed short int        s16 ;
typedef unsigned long int       u32 ;
typedef signed long int         s32 ;
typedef unsigned long long int  u64 ;
typedef signed long long int    s64 ;

/*for float only */
typedef float f32;

/*for double only */
typedef double f64;
typedef long double f128;

/*Null char for check that the pointer is comming or not*/
#define NULL 0

typedef enum
{
	E_NOT_OK,
	E_OK,
} StdReturnType;

#endif /* STD_TYPES_H_ */
