////////////////// Author:Khaled Montaser //////////////////
////////////////// Date:23/6/23 ////////////////////////////
////////////////// Version:1 ///////////////////////////////


#ifndef MCAL_TIMER1_PRIVATE
#define MCAL_TIMER1_PRIVATE

#include "LIB_BIT_MATH.h"
#include "LIB_STD.h"
#include "LIB_MimMap.h"

typedef struct Timer1Reg
{
    U16 ICR1;
    U16 OCR1B;
    U16 OCR1A;
    U16 TCNT1;

}Timer1Reg;


#define TIMER1 ((volatile Timer1Reg*)0x46)
#define TCCR1B *((U8*)0x4E)
#define TCCR1A *((U8*)0x4F)
#define TIFR   *((volatile U8*)0x58)
#define TIMSK  *((volatile U8*)0x59)
#define SREG   *((volatile U8*)0x5F)

typedef enum tccr1b
{
    cs10,
    cs11,
    cs12,
    wgm12,
    wgm13,

}tccr1b;

typedef enum tccr1a
{
    wgm10,
    wgm11,
    com1b0=4,
    com1b1,
    com1a0,
    com1a1,
    
}tccr1a;

typedef enum tifr
{
    tov1=2,
    ocf1b,
    ocf1a,
    icf1
    
}tifr;

typedef enum timsk
{
    toie1=2,
    ocie1b,
    ocie1a,
    ticie1,
}timsk;

#endif