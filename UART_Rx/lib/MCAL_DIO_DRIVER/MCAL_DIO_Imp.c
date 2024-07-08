////////////////// Author:Khaled Montaser //////////////////
////////////////// Date:24/6/23 ////////////////////////////
////////////////// Version:1 ///////////////////////////////


#include"MCAL_DIO_Header.h"


    //////////////////PIN FUNCs////////////////
    void Void_SetPinDir(U8 U8_PortName ,U8 U8_PinNumber , U8 U8_PinDirection)
    {
        switch (U8_PinDirection)
        {
        case INPUT:
            switch (U8_PortName)
            {
            case PORTA:
                CLEAR_BIT(PA->DDR ,U8_PinNumber);
                break;
                    
            case PORTB :
                CLEAR_BIT(PB->DDR ,U8_PinNumber);
                break;
        
            case PORTC :
                CLEAR_BIT(PC->DDR ,U8_PinNumber);
                break;
        
            case PORTD :
                CLEAR_BIT(PD->DDR ,U8_PinNumber);
                break;
            
            
            default:
                break;
            }
        
        break;
        
        case OUTPUT:
            switch (U8_PortName)
            {
            case PORTA :
                SET_BIT(PA->DDR ,U8_PinNumber);
                break;
            
            case PORTB :
                SET_BIT(PB->DDR ,U8_PinNumber);
                break;
        
            case PORTC :
                SET_BIT(PC->DDR ,U8_PinNumber);
                break;
        
            case PORTD :
                SET_BIT(PD->DDR ,U8_PinNumber);
                break;
            
            
            default:
                break;
            }
        
        break;
        
        default:
            break;
        }


    return;
    }
    void Void_SetPinValue(U8 U8_PortName ,U8 U8_PinNumber , U8 U8_PinValue)
    {
        switch (U8_PinValue)
        {
        case LOW:
            switch (U8_PortName)
            {
            case PORTA:
                CLEAR_BIT(PA->PORT ,U8_PinNumber);
                break;
                    
            case PORTB :
                CLEAR_BIT(PB->PORT ,U8_PinNumber);
                break;
        
            case PORTC :
                CLEAR_BIT(PC->PORT ,U8_PinNumber);
                break;
        
            case PORTD :
                CLEAR_BIT(PD->PORT ,U8_PinNumber);
                break;
            
            
            default:
                break;
            }
        
        break;
        
        case HIGH:
            switch (U8_PortName)
            {
            case PORTA :
                SET_BIT(PA->PORT ,U8_PinNumber);
                break;
            
            case PORTB :
                SET_BIT(PB->PORT ,U8_PinNumber);
                break;
        
            case PORTC :
                SET_BIT(PC->PORT ,U8_PinNumber);
                break;
        
            case PORTD :
                SET_BIT(PD->PORT ,U8_PinNumber);
                break;
            
            
            default:
                break;
            }
        
        break;
        
        default:
            break;
        }


    return;
   


    }  
    U8 U8_ReadPinValue(U8 U8_PortName ,U8 U8_PinNumber )
    {
        switch (U8_PortName)
        {
        case PORTA:
            return GET_BIT(PA->PIN,U8_PinNumber);
            break;
        
        case PORTB:
            return GET_BIT(PB->PIN,U8_PinNumber);
            break;
        
        case PORTC:
            return GET_BIT(PC->PIN,U8_PinNumber);
            break;
        
        case PORTD:
            return GET_BIT(PD->PIN,U8_PinNumber);
            break;
        
        default:
            break;
        }

        return 0;
    }
    


    //////////////////PORT FUNCs////////////////
    void Void_SetPortDir(U8 U8_PortName , U8 U8_PortDirection)
    {
        switch (U8_PortDirection)
        {
        case INPUT:
            switch (U8_PortName)
            {
            case PORTA:
                CLEAR_BYTE(PA->DDR);
                break;
                    
            case PORTB :
                CLEAR_BYTE(PB->DDR);
                break;
        
            case PORTC :
                CLEAR_BYTE(PC->DDR);
                break;
        
            case PORTD :
                CLEAR_BYTE(PD->DDR);
                break;
            
            
            default:
                break;
            }
        
        break;
        
        case OUTPUT:
            switch (U8_PortName)
            {
            case PORTA :
                SET_BYTE(PA->DDR);
                break;
            
            case PORTB :
                SET_BYTE(PB->DDR);
                break;
        
            case PORTC :
                SET_BYTE(PC->DDR);
                break;
        
            case PORTD :
                SET_BYTE(PD->DDR);
                break;
            
            
            default:
                break;
            }
        
        break;
        
        default:
            break;
        }


    return; 
    }
    void Void_SetPortValue(U8 U8_PortName  , U8 U8_PortValue)
    {
        switch (U8_PortValue)
        {
        case LOW:
            switch (U8_PortName)
            {
            case PORTA:
                CLEAR_BYTE(PA->PORT);
                break;
                    
            case PORTB :
                CLEAR_BYTE(PB->PORT);
                break;
        
            case PORTC :
                CLEAR_BYTE(PC->PORT);
                break;
        
            case PORTD :
                CLEAR_BYTE(PD->PORT);
                break;
            
            
            default:
                break;
            }
        
        break;
        
        case HIGH:
            switch (U8_PortName)
            {
            case PORTA :
                SET_BYTE(PA->PORT);
                break;
            
            case PORTB :
                SET_BYTE(PB->PORT);
                break;
        
            case PORTC :
                SET_BYTE(PC->PORT);
                break;
        
            case PORTD :
                SET_BYTE(PD->PORT);
                break;
            
            
            default:
                break;
            }
        
        break;
        
        default:
            break;
        }


    return; 
    }
    U8 U8_ReadPortValue(U8 U8_PortName )
    {
        switch (U8_PortName)
        {
        case PORTA:
            return PA->PIN;
            break;
        
        
        case PORTB:
            return PB->PIN;
            break;
        
        
        case PORTC:
            return PC->PIN;
            break;

        
        case PORTD:
            return PD->PIN;
            break;
        default:
            break;
        }
    return 0;
    }
    