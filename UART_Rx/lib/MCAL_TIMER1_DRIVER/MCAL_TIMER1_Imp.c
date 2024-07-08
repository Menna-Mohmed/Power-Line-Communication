////////////////// Author:Khaled Montaser //////////////////
////////////////// Date:23/6/23 ////////////////////////////
////////////////// Version:0 ///////////////////////////////

#include "MCAL_TIMER1_Header.h"

    void Void_Timer1CLK ( U8 U8_Timer1ClkSelect)
    {
        SET_BIT(TIMSK,toie1);
        SET_BIT(TIMSK,ocie1b);
        SET_BIT(TIMSK,ocie1a);
        SET_BIT(TIMSK,ticie1);

        ISR(TIM1_CAPT_VECT);
        ISR(TIM1_COMPA_VECT);
        ISR(TIM1_COMPB_VECT);
        ISR(TIM1_OVF_VECT);

        switch (U8_Timer1ClkSelect)
        {
        case TIMER1_CLK_OFF:
            
            CLEAR_BIT(TCCR1B,cs10);
            CLEAR_BIT(TCCR1B,cs11);
            CLEAR_BIT(TCCR1B,cs12);

            break;

        case TIMER1_CLK_DIV1:

            SET_BIT(TCCR1B,cs10);
            CLEAR_BIT(TCCR1B,cs11);
            CLEAR_BIT(TCCR1B,cs12);
            
            break;

        case TIMER1_CLK_DIV8:

            CLEAR_BIT(TCCR1B,cs10);
            SET_BIT(TCCR1B,cs11);
            CLEAR_BIT(TCCR1B,cs12);

            break;

        case TIMER1_CLK_DIV64:

            SET_BIT(TCCR1B,cs10);
            SET_BIT(TCCR1B,cs11);
            CLEAR_BIT(TCCR1B,cs12);

            break;

        case TIMER1_CLK_DIV256:

            CLEAR_BIT(TCCR1B,cs10);
            CLEAR_BIT(TCCR1B,cs11);
            SET_BIT(TCCR1B,cs12);

            break;

        case TIMER1_CLK_DIV1024:

            SET_BIT(TCCR1B,cs10);
            CLEAR_BIT(TCCR1B,cs11);
            SET_BIT(TCCR1B,cs12);

            break;

        case TIMER1_EXTERNAL_CLK_FALLING:

            CLEAR_BIT(TCCR1B,cs10);
            SET_BIT(TCCR1B,cs11);
            SET_BIT(TCCR1B,cs12);

            break;

        case TIMER1_EXTERNAL_CLK_RSING:

            SET_BIT(TCCR1B,cs10);
            SET_BIT(TCCR1B,cs11);
            SET_BIT(TCCR1B,cs12);

            break;

        default:
            break;
        }


    return;
    }

    void Void_Timer1Mode (U8 U8_Timer1Mode)
    {
        switch (U8_Timer1Mode)
        {
        case TIMER1_NORMAL_MODE:
            CLEAR_BIT(TCCR1A,wgm10);
            CLEAR_BIT(TCCR1A,wgm11);
            CLEAR_BIT(TCCR1B,wgm12);
            CLEAR_BIT(TCCR1B,wgm13);
            break;
        
        case TIMER1_PHASE_CORRECT_PWM_MODE:
            CLEAR_BIT(TCCR1A,wgm10);
            SET_BIT(TCCR1A,wgm11);
            CLEAR_BIT(TCCR1B,wgm12);
            SET_BIT(TCCR1B,wgm13);
            break;
        
        
        case TIMER1_COMPARE_MATCH_MODE:
            CLEAR_BIT(TCCR1A,wgm10);
            CLEAR_BIT(TCCR1A,wgm11);
            SET_BIT(TCCR1B,wgm12);
            SET_BIT(TCCR1B,wgm13);
            break;
        
        
        case TIMER1_FAST_PWM_MODE:
            CLEAR_BIT(TCCR1A,wgm10);
            SET_BIT(TCCR1A,wgm11);
            SET_BIT(TCCR1B,wgm12);
            SET_BIT(TCCR1B,wgm13);
            break;
        
        default:
            break;
        }
        
        
        

        

    return;
    }
    
    void Void_Timer1CompareOutputMode (U8 U8_CompareOutputMode)
    {
        switch (U8_CompareOutputMode)
        {
        case  TIMER1_OUTPUT_DISCONNECTED:
            
            CLEAR_BIT(TCCR1A,com1a0);
            CLEAR_BIT(TCCR1A,com1b0);

            CLEAR_BIT(TCCR1A,com1a1);
            CLEAR_BIT(TCCR1A,com1b1);

            break;
        
        case  TIMER1_OUTPUT_TOGGLE:
            
            SET_BIT(TCCR1A,com1a0);
            SET_BIT(TCCR1A,com1b0);

            CLEAR_BIT(TCCR1A,com1a1);
            CLEAR_BIT(TCCR1A,com1b1);

            break;
        
        case  TIMER1_OUTPUT_CLEAR:
            
            CLEAR_BIT(TCCR1A,com1a0);
            CLEAR_BIT(TCCR1A,com1b0);

            SET_BIT(TCCR1A,com1a1);
            SET_BIT(TCCR1A,com1b1);

            break;
        
        case  TIMER1_OUTPUT_SET:
            
            SET_BIT(TCCR1A,com1a0);
            SET_BIT(TCCR1A,com1b0);

            SET_BIT(TCCR1A,com1a1);
            SET_BIT(TCCR1A,com1b1);

            break;
        
        default:
            break;
        }
    
    return;
    }


    void Void_Timer1FPWMConfig (U8 U8_Oc1xSelect, U16 U16_DutyCycle)
    {
        switch (U8_Oc1xSelect)
        {
        case TIMER1_OC1A:

         TIMER1->OCR1A = U16_DutyCycle ;     
            break;
        
        case TIMER1_OC1B:
         TIMER1->OCR1B = U16_DutyCycle;
            break;
        
        case TIMER1_ICR1:        
        TIMER1->ICR1 = U16_DutyCycle;
            break;

        default:
            break;
        }   


     return;
    }

        
           
    void Void_Timer1ClrFlags ()
    {
        if(GET_BIT(TIFR,tov1)) SET_BIT(TIFR,tov1);
        if(GET_BIT(TIFR,ocf1b))SET_BIT(TIFR,ocf1b);
        if(GET_BIT(TIFR,ocf1a))SET_BIT(TIFR,ocf1a);
        if(GET_BIT(TIFR,icf1))SET_BIT(TIFR,icf1);

    return;
    }