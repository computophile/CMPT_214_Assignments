/*
Name: Mohammed Thamidur Rashid
NSID: mor867  
Course: CMPT 214
Student Number: 1280257
*/

#include <stdio.h>

int main()
{

  int number;
  FILE *fp;

  fp = fopen("treasure_journal.txt", "w");

  if (fp != NULL)
  {
    printf("Enter positive treasure values: ");
    scanf("%d", &number);

    while (number >= 0)
    {
      fprintf(fp, "%d\n", number);
      printf("Enter positive treasure values: ");
      scanf("%d", &number);
    }
  fclose(fp);//closing the file
  }
  else
  {
    printf("Error reading/creating the file");
    return 0;
  }
}