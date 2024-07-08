 /*
    title: MEXTI Driver header
    author: a7
    company: amit
    version: 0
    date: 2/12/22
 */

#ifndef _MEXTIE_HEADER_H
#define _MEXTIE_HEADER_H

    #include "LIB_BIT_MATH.h"
    #include "LIB_STD.h"
    #include "MEXTI_private.h"
    
    #define INT0 6
    #define INT1 7
    #define INT2 5

    #define MEXTI_RISING_EDGE 0x77
    #define MEXTI_FALLING_EDGE 0x13
    #define MEXTI_LOW 0x10
    #define MEXTI_ANY 0xff
    #define MEXTI_OFF 0x00

    void SetEXINTTriggState(U8 ARGSetEXINTpinU8,U8 ARGSetEXINTTiggState);
    void SetEXINTFunction(U8 ARGSetEXINTpinU8, void (*ARGSetPtrToFunction)());
    U8 GetEXINTFlags();

#endif