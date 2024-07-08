 /*
    title: GIE Driver imp
    author: a7
    company: amit
    version: 0
    date: 2/12/22
 */

#include "MGIE_header.h"
#include "MGIE_private.h"

void SetGlobalInteruputEnableBit(U8 ARGGIEbitValueU8)
{

    switch (ARGGIEbitValueU8)
    {
        case MGIE_ON:
            SET_BIT(SREG, GIEBIT);
        break;

        case MGIE_OFF:
            CLEAR_BIT(SREG, GIEBIT);
        break;
    
        default:
            SET_BIT(SREG, GIEBIT);
        break;
    }
    
    return;
}
