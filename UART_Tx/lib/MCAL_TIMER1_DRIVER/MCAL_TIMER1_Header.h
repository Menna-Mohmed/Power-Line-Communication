////////////////// Author:Khaled Montaser //////////////////
////////////////// Date:23/6/23 ////////////////////////////
////////////////// Version:0 ///////////////////////////////

#ifndef MCAL_TIMER1_HEAD
#define MCAL_TIMER1_HEAD

 #include "MCAL_TIMER1_Private.h"
 /////////////// CLK Select //////////////////
    #define TIMER1_CLK_OFF 0
    #define TIMER1_CLK_DIV1 1
    #define TIMER1_CLK_DIV8 2
    #define TIMER1_CLK_DIV64 3
    #define TIMER1_CLK_DIV256 4
    #define TIMER1_CLK_DIV1024 5
    #define TIMER1_EXTERNAL_CLK_FALLING 6
    #define TIMER1_EXTERNAL_CLK_RSING 7


 /////////////// Mode Select //////////////////
    #define TIMER1_NORMAL_MODE 0
    #define TIMER1_PHASE_CORRECT_PWM_MODE 1
    #define TIMER1_COMPARE_MATCH_MODE 2
    #define TIMER1_FAST_PWM_MODE 3


 //////// Compare Output Mode Select ////////
    #define TIMER1_OUTPUT_DISCONNECTED 0
    #define TIMER1_OUTPUT_TOGGLE 1
    #define TIMER1_OUTPUT_CLEAR 2
    #define TIMER1_OUTPUT_SET 3

/////////////// OCx Select //////////////////
   #define TIMER1_OC1A 0
   #define TIMER1_OC1B 1
   #define TIMER1_ICR1 2

   void Void_Timer1CLK ( U8 U8_Timer1ClkSelect);
   void Void_Timer1Mode (U8 U8_Timer1Mode);
   void Void_Timer1CompareOutputMode (U8 U8_CompareOutputMode);
   void Void_Timer1FPWMConfig (U8 U8_Oc1xSelect, U16 U16_DutyCycle);
   void Void_Timer1ClrFlags ();






#endif