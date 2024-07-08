////////////////// Author:Khaled Montaser //////////////////
////////////////// Date:22/6/23 ////////////////////////////
////////////////// Version:1 ///////////////////////////////

#ifndef LIB_BIT_MATH
#define LIB_BIT_MATH


/////////////////////// BIT_FUNCs ////////////////////////////// 
#define SET_BIT(REG, BIT_NUM)        REG |= (1<<BIT_NUM)
#define CLEAR_BIT(REG, BIT_NUM)      REG &= ~(1<<BIT_NUM)
#define TOGGLE_BIT(REG, BIT_NUM)     REG ^= (1<<BIT_NUM)
#define GET_BIT(REG, BIT_NUM)         ((REG>>BIT_NUM)&1)
    

/////////////////////// NIBBLE_FUNCs //////////////////////////// 
#define LOWER_NIBBLE 0x0F
#define HIGHER_NIBBLE 0xF0

#define SET_NIBBLE(REG , NIBBLE_POS)        REG |= NIBBLE_POS 
#define CLEAR_NIBBLE(REG , NIBBLE_POS)      REG &= (~NIBBLE_POS)
#define TOGGLE_NIBBLE(REG , NIBBLE_POS)     REG ^= NIBBLE_POS



/////////////////////// BYTE_FUNCs ////////////////////////////// 
#define SET_BYTE(REG)        REG = 0xFF
#define CLEAR_BYTE(REG)      REG = 0x00
#define TOGGLE_BYTE(REG)     REG ^= 0xFF





#endif