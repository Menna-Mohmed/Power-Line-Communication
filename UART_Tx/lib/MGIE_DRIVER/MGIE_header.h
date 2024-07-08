 /*
    title: GIE Driver header
    author: a7
    company: amit
    version: 0
    date: 2/12/22
 */

#ifndef _MGIE_HEADER_H
#define _MGIE_HEADER_H

    #include "LIB_BIT_MATH.h"
    #include "LIB_STD.h"
    #include "MGIE_private.h"
    
    #define MGIE_OFF 0x00
    #define MGIE_ON 0xff

    void SetGlobalInteruputEnableBit(U8 ARGGIEbitValueU8);

#endif
