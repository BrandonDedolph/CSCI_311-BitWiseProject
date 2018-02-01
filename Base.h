#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#ifndef BASE_H
#define BASE_H

#ifdef BIN
#define BASE 2
#define LENGTH 32
#else
#define BASE 16
#define LENGTH 10
#endif

#ifdef ONE
#define NUM "0x13579BDF" //first sample number to be defined
#define DECIMAL false
#define NEGATIVE false
#endif

#ifdef TWO
#define NUM "-65536"    //second sample number to be defined
#define DECIMAL true
#define NEGATIVE true
#endif

#ifdef THREE
#define NUM "100"       //third sample number to be defined
#define DECIMAL true
#define NEGATIVE false
#endif


#define EXTRACT(NUM, p, n) (NUM >> (p+1-n)) & ~(~0 << n)
#define INSERT(NUM, NUMBEROFBITS, p) (1 << ((NUMBEROFBITS - 1) - p))


#endif //BASE_H
