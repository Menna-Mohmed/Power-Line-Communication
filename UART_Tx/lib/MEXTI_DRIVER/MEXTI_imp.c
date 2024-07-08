 /*
    title: MEXTI Driver imp
    author: a7
    company: amit
    version: 0
    date: 2/12/22
 */

#include "MEXTI_header.h"
#include "MEXTI_private.h"

void (*PtrToFunVec1)() = (void*)0;
void (*PtrToFunVec2)() = (void*)0;
void (*PtrToFunVec3)() = (void*)0;

void SetEXINTTriggState(U8 ARGSetEXINTpinU8,U8 ARGSetEXINTTiggState)
{
    SET_BIT(*GICR, ARGSetEXINTpinU8);

    switch (ARGSetEXINTTiggState)
    {
        case MEXTI_RISING_EDGE:
            switch (ARGSetEXINTpinU8)
            {
                case INT0:
                    SET_BIT(*MCUCR, ISC00);
                    SET_BIT(*MCUCR, ISC01);
                break;

                case INT1:
                    SET_BIT(*MCUCR, ISC10);
                    SET_BIT(*MCUCR, ISC11);
                break;

                case INT2:
                    SET_BIT(*MCUCSR, ISC2);
                break;
            
                default:
                break;
            }
        break;

        case MEXTI_FALLING_EDGE:
            switch (ARGSetEXINTpinU8)
            {
                case INT0:
                    CLEAR_BIT(*MCUCR, ISC00);
                    SET_BIT(*MCUCR, ISC01);
                break;

                case INT1:
                    CLEAR_BIT(*MCUCR, ISC10);
                    SET_BIT(*MCUCR, ISC11);
                break;

                case INT2:
                    CLEAR_BIT(*MCUCSR, ISC2);
                break;
            
                default:
                break;
            }
        break;

        case MEXTI_ANY:
            switch (ARGSetEXINTpinU8)
            {
                case INT0:
                    SET_BIT(*MCUCR, ISC00);
                    CLEAR_BIT(*MCUCR, ISC01);
                break;

                case INT1:
                    SET_BIT(*MCUCR, ISC10);
                    CLEAR_BIT(*MCUCR, ISC11);
                break;

                case INT2:
                    SET_BIT(*MCUCSR, ISC2);
                break;
            
                default:
                break;
            }
        break;

        case MEXTI_LOW:
            switch (ARGSetEXINTpinU8)
            {
                case INT0:
                    CLEAR_BIT(*MCUCR, ISC00);
                    CLEAR_BIT(*MCUCR, ISC01);
                break;

                case INT1:
                    CLEAR_BIT(*MCUCR, ISC10);
                    CLEAR_BIT(*MCUCR, ISC11);
                break;

                case INT2:
                    CLEAR_BIT(*MCUCSR, ISC2);
                break;
            
                default:
                break;
            }
        break;

        case MEXTI_OFF:
            CLEAR_BIT(*GICR, ARGSetEXINTpinU8);
        break;
    
        default:
            CLEAR_BIT(*GICR, ARGSetEXINTpinU8);
        break;
    }
    return;
}

void SetEXINTFunction(U8 ARGSetEXINTpinU8, void (*ARGSetPtrToFunction)())
{

    switch (ARGSetEXINTpinU8)
    {
        case INT0:
            PtrToFunVec1 = ARGSetPtrToFunction;
        break;

        case INT1:
            PtrToFunVec2 = ARGSetPtrToFunction;
        break;

        case INT2:
            PtrToFunVec3 = ARGSetPtrToFunction;
        break;
    
        default:
            PtrToFunVec1 = ARGSetPtrToFunction;
        break;
    }

}

U8 GetEXINTFlags();
 
void __vector_1(void)__attribute__((signal,used));
void __vector_1(void)
{
    PtrToFunVec1();
}

void __vector_2(void)__attribute__((signal,used));
void __vector_2(void)
{
    PtrToFunVec2();
}

void __vector_3(void)__attribute__((signal,used));
void __vector_3(void)
{
    PtrToFunVec3();
}
