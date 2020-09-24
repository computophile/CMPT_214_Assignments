/*
Name: Mohammed Thamidur Rashid
NSID: mor867
Course: CMPT 214
Assignment 1
*/

#include <stdio.h>

int main(){
  int num1, num2;
  float real_number;

  printf("Enter an integer: ");
  scanf("%d", &num1);

  printf("Enter a real number: ");
  scanf("%f", &real_number);

  printf("Enter an integer: ");
  scanf("%d", &num2);

  printf("\n A man was walking about %d miles away from his home on a lonely road at night carrying about %.2f litres of oil for his tractor that broke down due to low fuel while he was working on his field. He bought enough fuel to get him running for the next %d days.", num1, real_number, num2);
}