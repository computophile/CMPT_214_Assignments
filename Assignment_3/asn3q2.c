/*
Name: Mohammed Thamidur Rashid
NSID: mor867  
Course: CMPT 214
Student Number: 11280257
*/
#include <stdio.h>

int main()
{

  FILE *fp;
  int max, min, totalWineCases;
  totalWineCases = 0;
  int number_of_weeks;
  max = 0; //initializing min with 0 since the number of shipments will be bigger than 0;

  fp = fopen("test_data.txt", "r");


  if (fp != NULL)
  {
    fscanf(fp, "%d", &number_of_weeks);

    if(feof(fp))
    {
      printf("File is empty!\n");
      return 0;
    }

    for (int i = 1; i <= number_of_weeks; i++)
    {
      // for-loop to loop through the number of weeks of shipments
      // defined in the first line of the file;
      int wineCases;

      fscanf(fp, "%d", &wineCases);

      totalWineCases += wineCases;
      // initializing the value of min;
      if (i == 1)
      {
        min = wineCases;
      }

      if (wineCases > max)
      {
        max = wineCases;
      }
      if (wineCases < min)
      {
        min = wineCases;
      }
    }
    fclose(fp); //closing the file;

    printf("The largest shipment size: %d\nThe smallest shipment size: %d \n", max, min);
    printf("Total shipment size: %d\n", totalWineCases);
    printf("Number of weeks: %d\n", number_of_weeks);
    printf("The average shipment size: %0.2f", (float)(totalWineCases / number_of_weeks));
    return 0;
  }
  else
  {
    printf("File doesn't exist / Not enough permission!\n");
    return 1;
  }
}
