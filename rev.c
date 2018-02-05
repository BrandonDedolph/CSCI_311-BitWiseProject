#include "Base.h"

void printBinary(int);


int main(){

#if (BIN)

    int  firstReverse = 0,
         secondReverse = 0,
         reverseTemp = 0;

    printf("Original number:  ");
    printBinary(NUM);

    for (int pull = 0; pull < BINARY; pull++){

        reverseTemp = EXTRACT(NUM, pull, 1);
        firstReverse |= INSERT(reverseTemp, BINARY, pull);
    }

    printf("Reversed number:  ");
    printBinary(firstReverse);

    reverseTemp = 0;

    for (int pull = 0; pull < BINARY; pull++){

        reverseTemp = EXTRACT(firstReverse, pull, 1);
        secondReverse |= INSERT(reverseTemp, BINARY, pull);
    }

    printf("Second number:    ");
    printBinary(secondReverse);


#else


    char num[LENGTH + 1];
    sprintf(num, "%.8X", NUM);
    printf("Original number:  0x%s\n", num);

    int     firstReverse,
            secondReverse,
            reverseTemp = 0;

    for (int pull = 3; pull < BINARY; pull += 4){

        reverseTemp = EXTRACT(NUM, pull, 4);
        firstReverse |= INSERT(reverseTemp, BINARY, pull);
    }

    printf("Reversed number:  0x%08X\n", firstReverse);

    reverseTemp = 0;

    for (int pull = 3; pull < BINARY; pull += 4){

        reverseTemp = EXTRACT(firstReverse, pull, 4);
        secondReverse |= INSERT(reverseTemp, BINARY, pull);
    }

    printf("Second number:    0x%08X\n", secondReverse);


#endif

}

void printBinary(int num){


    int tempBinaryNum = 0;
    for (int pull = BINARY; pull > 0;){

        pull--;
        tempBinaryNum = EXTRACT(num, pull, 1);
        printf("%d", tempBinaryNum);
    }

    printf("\n");

}
