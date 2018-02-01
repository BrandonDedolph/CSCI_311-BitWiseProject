
#include "Base.h"

const int HEX_START = 2; //number to skip the "0x" when a hex is declared
const int HEX_X_LOCATION = 1; //location of the x when the number chosen is Hex
const int BINARY_BASE = 2; //definition of Binary base
const int HEX_BASE = 16; //definition of Hexadecimal base
const int BINARY_SIZE = 32;
const int HEX_SIZE = 10;

void convertNumber(char[], char*);
void hex_To_Binary(char[], char*);
void dec_To_Binary(char[], int*);
void dec_To_Hexidecimal(char[], char*);
void reverseNumber(char[], char*);
void display(char[]);
void displayBIN(int []);



int main(){

  char number[] = NUM; //number is set to the number determined by which number is defined
  display(number);
  char convertedNumber[LENGTH]  = {'\0'};
  printf("%d\n", LENGTH);
  printf("%d\n", BASE);
  display(convertedNumber);
  //char reversedNumber[LENGTH];
  //char reversedReversedNumber[LENGTH];

  convertNumber(number, convertedNumber);
  //display(convertedNumber);

  return 0;




}

void hex_To_Binary(char n1[], char *n2){
  for (int index = HEX_START; index < strlen(n1); index++){

    switch (n1[index])
    {
    case '0':
        strcat(n2,"0000"); break;
    case '1':
        strcat(n2,"0001"); break;
    case '2':
        strcat(n2,"0010"); break;
    case '3':
        strcat(n2,"0011"); break;
    case '4':
        strcat(n2,"0100"); break;
    case '5':
        strcat(n2,"0101"); break;
    case '6':
        strcat(n2,"0110"); break;
    case '7':
        strcat(n2,"0111"); break;
    case '8':
        strcat(n2,"1000"); break;
    case '9':
        strcat(n2,"1001"); break;
    case 'A':
        strcat(n2,"1010"); break;
    case 'B':
        strcat(n2,"1011"); break;
    case 'C':
        strcat(n2,"1100"); break;
    case 'D':
        strcat(n2,"1101"); break;
    case 'E':
        strcat(n2,"1110"); break;
    case 'F':
        strcat(n2,"1111"); break;
    }
  }
}

void dec_To_Binary(char n1[], int *n2){
  printf("dec_To_Binary reached: ");
  display(n1);
  int num = 0;
  num = atoi(n1);
  printf("%d\n", num);

  for(int index = BINARY_SIZE - 1; num > 0; index--)
    {
      printf("1: %d\n", num);
      n2[index] = (num % BINARY_BASE);
      printf("2: %d\n", n2[index]);
      num = (num - n2[index]) / BINARY_BASE;
      printf("3: %d\n", index);
  }
  printf("dec changed to binary: ");
  displayBIN(n2);

}

void dec_To_Hexidecimal(char n1[], char *n2){
  printf("dec_To_Hexidecimal reached: ");
  display(n1);
  int n3[BINARY_SIZE];
  for (int i = 0; i < BINARY_SIZE; i++)
    n3[i] = 0;
  dec_To_Binary(n1, n3);
  printf("dec_To_Hexidecimal reached: ");
  displayBIN(n3);

  int temp;
  for (int i = 0; i < BINARY_SIZE;){
    temp = 0;
    temp += 8 * n3[i++];
    temp += 4 * n3[i++];
    temp += 2 * n3[i++];
    temp += 1 * n3[i++];
    printf("temp: %d\n", temp);
    if (temp > 9)
      temp += 55;
    else
      temp += 48;

    n2[i] = temp;
    printf("n2: %c\n", n2[i]);
    }



  printf("Number has been changed to Hex: ");
  //display(n2);

}

void convertNumber(char n1[], char *n2){
  printf("convertNumber reached: ");
  display(n1);


  if (BASE == BINARY_BASE)
    if (NUM[HEX_X_LOCATION] == 'x')
      hex_To_Binary(n1, n2);
    else{
      int n3[BINARY_SIZE];
      for(int i = 0; i < BINARY_SIZE; i++)
        n3[i] = 0;
      dec_To_Binary(n2, n3);
    }

  if (BASE == HEX_BASE)
    if (NUM[HEX_X_LOCATION] != 'x')
      dec_To_Hexidecimal(n1, n2);

}

void reverseNumber(char n1[],char *n2){


}

void display(char n[]){
  printf("display accessed \n");
  int count;
  for (count = 0; n[count] != '\0'; ++count);

  for (int index = 0; index < count; index++)
    printf("%c", n[index]);
  printf("\n");
}

void displayBIN(int n[]){
  printf("displayBIN accessed\n");
  for (int index = 0; index < BINARY_SIZE; index++)
    printf("%d", n[index]);
  printf("\n");
}
