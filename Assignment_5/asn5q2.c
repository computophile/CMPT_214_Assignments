/*
Name: Mohammed Thamidur Rashid
NSID: mor867
Student: #11280257
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_sales(char header[][15], u_int32_t *fileCount, u_int32_t row)
{
  // to display the total sales of each item
  // header[][15]: 2D array of stirng that are 15 characters long
  // *1D view of 2D array that has the data of the files to be calculated and displayed
  // row: number of lines that the file has 
  for (int i = 0; i < row - 1; i++)// -1 to accomodate for the header
  {
    printf("Total %s sales: ", header[i]);
    u_int32_t totalCount = 0;
    for (int j = 0; j < 5; j++) // 5 as the numbe of columns are fixed
    {
      totalCount += fileCount[j * 5 + i];
    }
    printf("%u\n", totalCount);
  }
}

u_int32_t countLines(FILE *name)
{
  // read and return the number of lines in the file
  // *name pointer to the file
  char c;
  int countLines = 0;
  if (name != NULL)
  {
    while ((c = fgetc(name)) != EOF)
    {
      if (c == '\n')
        countLines++;
    }

    return countLines;
  }
  return 255; //error
}

// main funciton
int main(int argc, char *argv[])
{
  FILE *file0, *file1;

  char fileName0[20], fileName1[20];

  if (argc == 3) //checking for the number of arguments passed to the function
  {

    strcpy(fileName0, argv[1]);
    strcpy(fileName1, argv[2]);

    file0 = fopen(fileName0, "r");
    file1 = fopen(fileName1, "r");

    if (file0 == NULL || file1 == NULL)
    {
      printf("Files does not exist!\n");
      return 1; //if error
    }

    // count the number of lines in the program:
    u_int32_t lineCountFile0 = countLines(file0);

    u_int32_t lineCountFile1 = countLines(file1);

    if (lineCountFile0 != lineCountFile1)
    {
      printf("Something wrong with the contents of the file!\n");
      return 1;
    }
    if (lineCountFile0 == 255 || lineCountFile1 == 255)
    {
      printf("Unexpedted error in files!\n");
      return 1;
    }
    if (lineCountFile0 <= 2 || lineCountFile1 <= 2)
    {
      printf("Less than 2 lines in the file!");
      return 1; //indicating error
    }

    // resetting the file pointer to initial state for further operations
    rewind(file0);
    rewind(file1);

    //-1 to accomodate for the decription row and column.
    const size_t ROW0 = lineCountFile0 - 1;
    const size_t ROW1 = lineCountFile1 - 1;
    const size_t COL = 6 - 1; // fixed at 5 , -1 for the Weekdays

    // arrays for holding the header of each file;
    char header0[COL][15];
    char header1[COL][15];

    // reading the header
    char buffer[15];
    fscanf(file0, "%s", buffer); //for reading DAY
    for (int i = 0; i < COL; i++)
    {
      char header_content[15];
      fscanf(file0, "%s", header_content);
      strcpy(header0[i], header_content);
    }

    char buffer1[15];
    fscanf(file1, "%s", buffer1);
    for (int i = 0; i < COL; i++)
    {
      char header_content[15];
      fscanf(file1, "%s", header_content);
      strcpy(header1[i], header_content);
    }

    // dynamically allocating a one-dimensional view of a two dimensional
    // array that can hold all of the unsigned integer data in the file.

    u_int32_t *fileContent0 = (u_int32_t *)malloc(sizeof(u_int32_t) * ROW0 * COL);
    u_int32_t *fileContent1 = (u_int32_t *)malloc(sizeof(u_int32_t) * ROW1 * COL);

    rewind(file0);
    rewind(file1);

    // reading the file0
    char buff[1000];
    fgets(buff, 1000, file0);
    for (int i = 0; i < lineCountFile0 - 1; i++) //-1 for the header
    {
      char weekday[10];
      fscanf(file0, "%s", weekday); // to skip the weekday
      for (int j = 0; j < COL; j++)
      {
        fscanf(file0, "%u", &fileContent0[i * ROW0 + j]);
      }
    }

    // reading the file1
    fgets(buff, 1000, file1);
    for (int i = 0; i < lineCountFile1 - 1; i++)//-1 for the header
    {
      char weekday[10];
      fscanf(file1, "%s", weekday);// to skip the weekday
      for (int j = 0; j < 5; j++)
      {
        fscanf(file1, "%u", &fileContent1[i * ROW0 + j]);
      }
    }

    // diplaying the results on the console;
    display_sales(header0, fileContent0, lineCountFile0);
    display_sales(header1, fileContent1, lineCountFile1);

    fclose(file0); //close file0
    fclose(file1); //close file1
  
    return 0;
  }
  else if (argc == 1)
  {
    printf("Expected 2 more arguments from the command line!\n");
    return 1;
  }
  else
  {
    printf("Unexpected input in the command line!\n");
    return 1;
  }
}