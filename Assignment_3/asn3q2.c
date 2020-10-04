/*
Name: Mohammed Thamidur Rashid
NSID: mor867  
Course: CMPT 214
Student Number: 1280257
*/
// read from the file that I wrote to 
#include <stdio.h>

int main(){

  FILE *readFile;

  readFile = fopen("text.txt", "r");

  if (readFile == NULL){
    printf("File not found");
  }
  else
  {
    int num;
    fscanf(readFile, "%d", &num);
    printf("The content of read file is : %d", num);
    fclose(readFile);
  }
  

  return 0;
}