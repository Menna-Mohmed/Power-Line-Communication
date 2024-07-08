////////////////// Author:Khaled Montaser //////////////////
////////////////// Date:4/7/23 ////////////////////////////
////////////////// Version: 3 ///////////////////////////////

#include "MCAL_UART_Header.h"

    void Void_UARTFlushBuffer(void)
    {
        CLEAR_BIT(UCSRB,txen);    
        CLEAR_BIT(UCSRB,rxen);
        
        while (UDR)
        {
            asm("NOP");
        }        
    
    return;
    }

    void Void_UARTSetMode(U8 U8_UARTTransmissionMode)
    {
        switch (U8_UARTTransmissionMode)
        {
        case UART_Transmitter_Mode:
            SET_BIT(UCSRB,txen);    
            CLEAR_BIT(UCSRB,rxen);
            break;
        
        case UART_Receiver_Mode:
            CLEAR_BIT(UCSRB,txen);    
            SET_BIT(UCSRB,rxen);
            break;
        
        case UART_Transceiver_Mode:
            SET_BIT(UCSRB,txen);    
            SET_BIT(UCSRB,rxen);
            break;
        
        default:
            SET_BIT(UCSRB,txen);    
            SET_BIT(UCSRB,rxen);
            break;
        }
        return;
    }

    void Void_UARTConfig(U16 U16_UARTBaudRate ,U8 U8_selectSynchronization ,U8 U8_DataBitsNumber ,U8 U8_StopBitsNumber ,U8 U8_ParityMode)
    {

        SET_BIT(UCSRC,ursel);
        
        switch (U8_DataBitsNumber)
        {
        case UART_5BIT_MODE:
            CLEAR_BIT(UCSRC,ucsz0);
            CLEAR_BIT(UCSRC,ucsz1);
            CLEAR_BIT(UCSRB,ucsz2);
            break;
        
        case UART_6BIT_MODE:
            SET_BIT(UCSRC,ucsz0);
            CLEAR_BIT(UCSRC,ucsz1);
            CLEAR_BIT(UCSRB,ucsz2);
            break;

        case UART_7BIT_MODE:
            CLEAR_BIT(UCSRC,ucsz0);
            SET_BIT(UCSRC,ucsz1);
            CLEAR_BIT(UCSRB,ucsz2);
            break;

        case UART_8BIT_MODE:
            SET_BIT(UCSRC,ucsz0);
            SET_BIT(UCSRC,ucsz1);
            CLEAR_BIT(UCSRB,ucsz2);
            break;

        case UART_9BIT_MODE:
            SET_BIT(UCSRC,ucsz0);
            SET_BIT(UCSRC,ucsz1);
            SET_BIT(UCSRB,ucsz2);
            break;

        default:
            break;
        }

        switch (U8_StopBitsNumber)
        {
        case UART_ONE_STOP_BIT:
            CLEAR_BIT(UCSRC,usbs);
            break;
        
        
        case UART_TWO_STOP_BITS:
            SET_BIT(UCSRC,usbs);
            break;
        
        default:
            break;
        }

        switch (U8_ParityMode)
        {
        case UART_NO_PARITY:

            CLEAR_BIT(UCSRC,upm0);
            CLEAR_BIT(UCSRC,upm1);
            break;
        
        case UART_EVEN_PARITY:
        
            CLEAR_BIT(UCSRC,upm0);
            SET_BIT(UCSRC,upm1);
            break;

        case UART_ODD_PARITY:
        
            SET_BIT(UCSRC,upm0);
            SET_BIT(UCSRC,upm1);
            break;

            
        default:
            break;
        }

        CLEAR_BIT(UCSRC,ursel);

        switch (U8_selectSynchronization)
        {
        case UART_ASYNCHRONOUS :

            CLEAR_BIT(UCSRC,umsel);
            CLEAR_BIT(UCSRC,ucpol);
            CLEAR_BYTE(UBRRH);
            switch (U16_UARTBaudRate)
            {
            case UART_BR_2400BPS:
            
                SET_BIT(UCSRA,u2x);
                UBRRL = UART_BR_2400BPS;      
                UBRRH = (UART_BR_2400BPS>>8);
            
                break;
        
            case UART_BR_4800BPS:
            
                SET_BIT(UCSRA,u2x);
                UBRRL = UART_BR_4800BPS;      
                UBRRH = (UART_BR_4800BPS>>8);
            
                break;
        
            case UART_BR_9600BPS:
            
                UBRRL = UART_BR_9600BPS;      
            
                break;
        
            case UART_BR_14400BPS:
                
                SET_BIT(UCSRA,u2x);
                UBRRL = UART_BR_14400BPS;      
                
                break;
            
            case UART_BR_19200BPS:
                
                UBRRL = UART_BR_19200BPS;      

            break;
        
            case UART_BR_115200BPS:
            
                SET_BIT(UCSRA,u2x);
                UBRRL = UART_BR_115200BPS;
            
            break;
        
            case UART_BR_250000BPS:
            
                UBRRL = UART_BR_250000BPS;      
            
            break;

        default:
            
            UBRRL = U16_UARTBaudRate;      
            UBRRH = (U16_UARTBaudRate>>8);

            break;
        }


            break;
        


        case UART_SYNCHRONOUS :
            
            
            SET_BIT(UCSRC,umsel);
            CLEAR_BIT(UCSRC,ucpol);
            CLEAR_BYTE(UBRRH);
            switch (U16_UARTBaudRate)
            {
            case UART_BR_2400BPS:
            
                SET_BIT(UCSRA,u2x);
                UBRRL = (UART_BR_2400BPS/2);      
                UBRRH = ((UART_BR_2400BPS/2)>>8);
            
                break;
        
            case UART_BR_4800BPS:
            
                SET_BIT(UCSRA,u2x);
                UBRRL = (UART_BR_4800BPS/2);      
                UBRRH = ((UART_BR_4800BPS/2)>>8);
            
                break;
        
            case UART_BR_9600BPS:
            
                UBRRL = UART_BR_9600BPS;      
            
                break;
        
            case UART_BR_14400BPS:
                
                SET_BIT(UCSRA,u2x);
                UBRRL = (UART_BR_14400BPS/2);      
                
                break;
            
            case UART_BR_19200BPS:
                
                UBRRL = UART_BR_19200BPS;      

            break;
        
            case UART_BR_115200BPS:
            
                SET_BIT(UCSRA,u2x);
                UBRRL = (UART_BR_115200BPS/2);
            
            break;
        
            case UART_BR_250000BPS:
            
                UBRRL = UART_BR_250000BPS;      
            
            break;

        default:
            
            UBRRL = U16_UARTBaudRate;      
            UBRRH = (U16_UARTBaudRate>>8);

            break;
        }


            break;


        default:
            break;
        }        
    
        
      return;
    }
    
    
    
    U16 U16_UARTReadFrame()
    {
        while (!GET_BIT(UCSRA,rxc))
        {
            asm("NOP");
        }
        return (GET_BIT(UCSRB,rxb8)<<9) | UDR;
        
    }



    void Void_UARTWriteFrame(U16 U16_DataBits)
    {   
        while (!GET_BIT(UCSRA,udre))
        {
            asm("NOP");
        }
        
        switch(GET_BIT(U16_DataBits,8))
        {
            case 0:
            CLEAR_BIT(UCSRB,txb8);
            break;

            case 1:
            SET_BIT(UCSRB,txb8);
            break;

            default:
            break;

        }
        UDR =(U8)U16_DataBits;
        while (!GET_BIT(UCSRA,txc))
        {
            asm("NOP");
        }
        SET_BIT(UCSRA,txc);                      
    return;
    }
