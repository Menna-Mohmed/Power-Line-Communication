////////////////// Author:Khaled Montaser //////////////////
////////////////// Date:4/7/23 ////////////////////////////
////////////////// Version: 2 ///////////////////////////////

#ifndef UART_HEAD
#define UART_HEAD
    #include "MCAL_UART_Private.h"


    //////////// Transmission Mode Select///////////
    #define UART_Transmitter_Mode 1
    #define UART_Receiver_Mode 2
    #define UART_Transceiver_Mode 3
    ////////////////////////////////////////////////


    ///////////// BaudRate Select///////////////
    #define UART_BR_2400BPS 832 //d
    #define UART_BR_4800BPS 416 //d
    #define UART_BR_9600BPS 103
    #define UART_BR_14400BPS 138 //d
    #define UART_BR_19200BPS 51
    #define UART_BR_115200BPS 16 //d
    #define UART_BR_250000BPS 3
    /*For Any Other Baud Rates Write UBRR Value For U2X=0 */



    /////////// Synchronization ////////////////
    #define UART_ASYNCHRONOUS 0
    #define UART_SYNCHRONOUS 1

    ///////////Data Bits Number ///////////////
    #define UART_5BIT_MODE 0
    #define UART_6BIT_MODE 1
    #define UART_7BIT_MODE 2
    #define UART_8BIT_MODE 3
    #define UART_9BIT_MODE 4

    /////////// stop bit config /////////////
    #define UART_ONE_STOP_BIT 0
    #define UART_TWO_STOP_BITS 1

    ////////// Parity Mode //////////////////
    #define UART_NO_PARITY 0
    #define UART_ODD_PARITY 1
    #define UART_EVEN_PARITY 2


    void Void_UARTSetMode(U8 U8_UARTTransmissionMode);
    void Void_UARTConfig(U16 U16_UARTBaudRate ,U8 U8_selectSynchronization ,U8 U8_DataBitsNumber ,U8 U8_StopBitsNumber ,U8 U8_ParityMode);
    U16 U16_UARTReadFrame();
    void Void_UARTWriteFrame(U16 U16_DataBits);
    void Void_UARTFlushBuffer(void);








#endif