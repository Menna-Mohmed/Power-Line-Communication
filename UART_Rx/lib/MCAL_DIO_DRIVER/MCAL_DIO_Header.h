////////////////// Author:Khaled Montaser //////////////////
////////////////// Date:22/6/23 ////////////////////////////
////////////////// Version:0 ///////////////////////////////

#ifndef MCAL_DIO_HEAD
#define MCAL_DIO_HEAD

#include "MCAL_DIO_Private.h"
    
#define LOW 0x00
#define HIGH 0x01
#define INPUT 0x00
#define OUTPUT 0x01

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

    //////////////////PIN FUNCs////////////////
    void Void_SetPinDir(U8 U8_PortName ,U8 U8_PinNumber , U8 U8_PinDirection);
    void Void_SetPinValue(U8 U8_PortName ,U8 U8_PinNumber , U8 U8_PinValue);
    U8 U8_ReadPinValue(U8 U8_PortName ,U8 U8_PinNumber );
    


    //////////////////PORT FUNCs////////////////
    void Void_SetPortDir(U8 U8_PortName , U8 U8_PortDirection);
    void Void_SetPortValue(U8 U8_PortName  , U8 U8_PortValue);
    U8 U8_ReadPortValue(U8 U8_PortName );
    







#endif