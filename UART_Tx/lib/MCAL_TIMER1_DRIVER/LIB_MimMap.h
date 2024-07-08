////////////////// Author:Khaled Montaser //////////////////
////////////////// Date:22/6/23 ////////////////////////////
////////////////// Version:0 ///////////////////////////////

#ifndef LIB_MMap
#define LIB_MMap


#define ISR(vector,...)    \
void vector (void) __attribute__ ((signal))__VA_ARGS__;\
void vector (void)

///////////EXT_Interrupt Vectors////////////
#define  INT0_VECT             __vector_1
#define  INT1_VECT             __vector_2
#define  INT2_VECT             __vector_3

////////////// Timer2 Vectors /////////////
#define  TIM2_COMP_VECT        __vector_4
#define  TIM2_OVF_VECT         __vector_5

////////////// Timer1 Vectors /////////////
#define  TIM1_CAPT_VECT        __vector_6
#define  TIM1_COMPA_VECT       __vector_7
#define  TIM1_COMPB_VECT       __vector_8
#define  TIM1_OVF_VECT         __vector_9

////////////// Timer0 Vectors ///////////////
#define  TIM0_COMP_VECT        __vector_10
#define  TIM0_OVF_VECT         __vector_11

////////////// SPI Vector ///////////////////
#define  SPI_STC_VECT          __vector_12

////////////// USART Vectors /////////////////
#define  USART_RXC_VECT        __vector_13
#define  USART_UDRE_VECT       __vector_14
#define  USART_TXC_VECT        __vector_15


///////////////// ADC Vector //////////////////
#define  ADC_VECT              __vector_16

/////////////// EEPROM Vector ////////////////
#define EE_RDY_VECT            __vector_17

////////// Analog Comparator Vector //////////
#define ANA_COMP_VECT          __vector_18

///////Two-wire Serial Interface Vector///////
#define TWI_VECT               __vector_19

////////////// SPM Vector //////////////
#define SPM_RDY_VECT           __vector_20



#endif