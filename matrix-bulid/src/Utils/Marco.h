#ifndef __LFR_UTILS_MARCO_H__
#define __LFR_UTILS_MARCO_H__

#include "Define.h"
#include <stdint.h>
#include <string.h>
#if DEBUG
#include <iostream>
#endif
//////////////////////////////////////////////////////////////////////


#ifndef KVALUE 
#define KVALUE 17
#endif

#ifndef BUFFMAX
#define BUFFMAX 10000
#endif


/////////////////////////////////////////////////////////////////////

#define KBITS (KVALUE *2)
#define KMASK ((0x1UL <<( KBITS)) -1)


/////////////////////////////////////////////////////////////////////


inline int64_t KmerIndex(const char * start , size_t len)
{
#if DEBUG
    static int count = 0 ;
    if(start == nullptr)
    {
        std::cout<<"Total kmer calc  "<<count<<std::endl;
        return -1;
    }
    count ++ ;
#endif
    uint64_t l2r = 0 ;
    uint64_t r2l = 0 ;
    const char * end = start+len-1;
    for(size_t i = 0 ; i < len ; i++)
    {
        l2r = (l2r<<2) + (((*start) & 0x6)>>1);
        r2l = (r2l<<2) + ((((*end) ^ 0x4)>>1) & 0x3);
        end --;
        start++;
    }

    return l2r < r2l ? l2r : r2l ;
}



#endif //__LFR_UTILS_MARCO_H__
