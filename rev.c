#include "Base.h"




int main(){

#if defined(BIN)
    char num[LENGTH];



#else
    char num[LENGTH + 1];
    sprintf(num, "%.8X", NUM);
    printf("Original number:  0x%s\n", num);

    int firstReverse, secondReverse;
    for (int i = 0, pull = 3, reverseTemp; i < BINARY/4; i++, pull += 4){

        reverseTemp = EXTRACT(NUM, pull, 4);
        firstReverse |= INSERT(reverseTemp, BINARY, pull);
        printf("%d: %d\n", i, reverseTemp);
    }

    printf("Reversed number:  0x%08X\n", firstReverse);

    for (int i = 0, pull = 3, reverseTemp; i < BINARY/4; i++, pull += 4){

        reverseTemp = EXTRACT(firstReverse, pull, 4);
        secondReverse |= INSERT(reverseTemp, BINARY, pull);
        printf("%d: %d\n", i, reverseTemp);
    }

    printf("Second number:   0x%08X\n", secondReverse);


#endif

}


