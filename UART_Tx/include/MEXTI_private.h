 /*
    title: MEXTI Driver private
    author: a7
    company: amit
    version: 0
    date: 2/12/22
 */

#ifndef _MEXTIE_PRIVATE_H
#define _MEXTIE_PRIVATE_H

    #define GICR    ((U8*)0x5B)
    #define MCUCR   ((U8*)0x55)
    #define MCUCSR  ((U8*)0x54)
    #define GIFR    ((volatile U8*)0x5A)
    
    #define ISC00 0
    #define ISC01 1
    #define ISC10 2
    #define ISC11 3
    
    #define ISC2 6
    
    #define INTF2 5
    #define INTF0 6
    #define INTF1 7


#endif