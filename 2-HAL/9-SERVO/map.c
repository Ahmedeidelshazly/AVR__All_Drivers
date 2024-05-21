#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "map.h"

s32 map(s32 input_min,s32 input_max,s32 outmin,s32 outmax,s32  input)
{
	s32 output=0;
	output= ((input-input_min)*(outmax-outmin))/(input_max-input_min)+outmin;
	return output;
}
