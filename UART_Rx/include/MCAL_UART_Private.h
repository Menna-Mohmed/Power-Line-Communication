////////////////// Author:Khaled Montaser //////////////////
////////////////// Date:4/7/23 ////////////////////////////
////////////////// Version: 0 ///////////////////////////////


#ifndef UART_PRIVATE
#define UART_PRIVATE
#include "LIB_BIT_MATH.h"
#include "LIB_STD.h"


#define UDR     *((volatile U8*)0x2C)             /////////// 16 bit read write UART  
#define UCSRA   *((volatile U8*)0x2B)            /////////// UART flagssss
#define UCSRB   *((U8*) 0x2A)           /////////// UART interrupts 
#define UBRRL   *((U8*)0x29)          /////////// 16 bit baud rate   

#define UCSRC   *((U8*) 0x40)        /////////// UART control 
#define UBRRH   UCSRC         ////////// 0,1,2,3 ubrr

typedef enum ucsra
{
    mpcm,
    u2x,
    pe,
    dor,
    fe,
    udre,
    txc,
    rxc

}ucsra;

typedef enum ucsrb
{
    txb8,
    rxb8,
    ucsz2,
    txen,
    rxen,
    udrie,
    txcie,
    rxcie

}ucsrb;

typedef enum ucsrc
{
    ucpol,
    ucsz0,
    ucsz1,
    usbs,
    upm0,
    upm1,
    umsel,
    ursel

}ucsrc;



#endif