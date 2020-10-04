/*
Name: Mohammed Thamidur Rashid
NSID: mor867
Course: CMPT 214
Assignment 2
*/

#include "stdio.h"

int main(){
  
  printf("The number entered by the user: ");
  int secret_code;
  scanf("%d", &secret_code);
  int reverse = 0;
  while (secret_code != 0){
    int ld = secret_code % 10;
    reverse = reverse * 10 + ld;
    secret_code = secret_code/10;
  } 
  printf("The secret code to open the door: %d", reverse);
  return 0;

}