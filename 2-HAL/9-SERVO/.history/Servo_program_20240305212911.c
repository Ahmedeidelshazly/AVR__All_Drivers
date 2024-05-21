#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PWM_interface.h"
#include "Servo_config.h"
#include "Servo_interface.h"
#include "Servo_private.h"
#include "map.h"



u8 Servo_u8GetAngle(u8 Coppy_u8Value)
{
    StdReturnType Return_Value =E_OK;
    s32 Local_s32ServoAngle;
    if ((Coppy_u8Value >=0) && (Coppy_u8Value <=180))
    {
        Local_s32ServoAngle = map(0,180,0,255,Coppy_u8Value);
        PWM_voidTimer1Init();
        PWM_voidSetICR1(20000);
        PWM_voidSetOCR(Local_s32ServoAngle);
    }
    else
    {
        Return_Value = E_NOT_OK;
    }
    return Return_Value;
}