/*
Name: Mohammed Thamidur Rashid
NSID: mor867  
Course: CMPT 214
Student Number: 11280257
*/

#include <stdio.h>

int main()
{

  int number;
  FILE *fp;

  fp = fopen("treasure_journal.txt", "a");

  if (fp != NULL) //checking if the file was read correctly
  {
    printf("Enter positive treasure values: ");
    scanf("%d", &number);

    while (number >= 0)
    {
      fprintf(fp, "%d\n", number);
      printf("Enter positive treasure values: ");
      scanf("%d", &number);
    }
    fclose(fp); //closing the file
    return 0;
  }
  else
  {
    printf("Error reading/creating the file");
    return 1;
  }
}