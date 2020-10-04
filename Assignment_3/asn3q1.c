/*
Name: Mohammed Thamidur Rashid
NSID: mor867  
Course: CMPT 214
Student Number: 1280257
*/

#include <stdio.h>

// opening a file
int main(){
  FILE *file;
  
  file = fopen("text.txt", "w");

  if (file == NULL){
    printf("text.txt could not be found or couldn't be opened for writing.\n");
    return 1;

  }
  else{
    printf("File opened successfully! Time to write to the file!\n");
    printf("Enter a number to write to the file: ");
    int n;
    scanf("%d", &n);

    // writing to the file
    fprintf(file, "%d", n);
    fclose(file);
  }

  return 0;
}