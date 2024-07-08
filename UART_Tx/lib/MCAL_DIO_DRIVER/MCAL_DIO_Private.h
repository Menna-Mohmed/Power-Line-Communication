////////////////// Author:Khaled Montaser //////////////////
////////////////// Date:22/6/23 ////////////////////////////
////////////////// Version:0 ///////////////////////////////

#ifndef MCAL_DIO_PRIVATE
#define MCAL_DIO_PRIVATE

#include "LIB_STD.h"
#include "LIB_BIT_MATH.h"


typedef enum Pins
{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
}Pins;

typedef struct PortConf
{
    U8 PIN;
    U8 DDR;
    U8 PORT;

}PortConf;

#define PA ((volatile PortConf*)0x39)
#define PB ((volatile PortConf*)0x36)
#define PC ((volatile PortConf*)0x33)
#define PD ((volatile PortConf*)0x30)


#endif