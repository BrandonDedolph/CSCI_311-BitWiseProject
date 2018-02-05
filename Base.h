#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#ifndef BASE_H
#define BASE_H

#define BINARY 32

#ifdef BIN
#define LENGTH 32
#else
#define LENGTH 8
#endif

#ifdef ONE
#define NUM 0x13579BDF //first sample number to be defined
#endif

#ifdef TWO
#define NUM -65536    //second sample number to be defined
#endif

#ifdef THREE
#define NUM 100       //third sample number to be defined
#endif

#define EXTRACT(NUM, p, n) ( (NUM) >> ( (p) +1- (n) )) & ~(~0 << (n) )
#define INSERT( NUM, NUMBEROFBITS, p) ((NUM)<< (((NUMBEROFBITS) - 1) - (p)))


#endif //BASE_H
