#include "Base.h"

const char NUMBER[] = NUM;

void convertNumber(char*);
void dec_To_Binary(char*);
void dec_To_Hexidecimal(char*);

int main(){


  char convertedNumber[10];
  convertNumber(convertedNumber);



}


void convertNumber(char *n1){

  /*if (DECIMAL == true)
    if (BASE ==2 )
      dec_To_Binary(n1);
    else
      */dec_To_Hexidecimal(n1);

}


void dec_To_Binary(char *n1){

  if (atoi(number) < 0)
    int num = atoi(NUMBER);

  for(int index = 32; index > 0;){

    --index;
    n1[index] = (num % 2) + 48;
    num = ((num - (n1[index] - 48)) / 2);
  }
}

void dec_To_Hexidecimal(char *n1){

  int num = atoi(NUMBER);

  int temp;
  for (int index = 8; index > 0;){

    --index;
    temp = (num % 16);
    if (temp > 9)
      n1[index] = temp + 55;
    else
      n1[index] = temp + 48;

    num = (num - temp) / 16;


  }
  printf("0x");
  for (int i = 0; i < 8; i++)
    printf("%c", n1[i]);
  printf("\n");
}
