/*
Name: Mohammed Thamidur Rashid
NSID: mor867
Student: #11280257
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct fileInfo
// {
//   int row;
//   int column;
// } FileInfo;

void display_sales(char header[][15], u_int32_t *fileCount, u_int32_t row){
      for (int i = 0; i < row - 1; i++)
    {
      printf("Total %s sales: ", header[i]);
      u_int32_t totalCount = 0;
      for (int j = 0; j < 5; j++)
      {
        totalCount += fileCount[j * 5 + i];
      }
      printf("%u\n", totalCount);
    }
}

u_int32_t countLines(FILE *name)
{
  char c;
  int countLines = 0;

  while ((c = fgetc(name)) != EOF)
  {
    if (c == '\n')
      countLines++;
  }

  return countLines;
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

    // count the number of lines in the program:
    u_int32_t countLinesFile0 = countLines(file0);

    u_int32_t countLinesFile1 = countLines(file1);

    if (countLinesFile0 <= 2 || countLinesFile1 <= 2)
    {
      printf("Less than 2 lines in the file!");
      return 1;
    }

    // resetting the file pointer to initial state for further operations
    rewind(file0);
    rewind(file1);

    // readHeaders
    //-1 to accomodate for the decription row and column.
    const size_t ROW0 = countLinesFile0 - 1;
    const size_t ROW1 = countLinesFile1 - 1;
    const size_t COL = 6 - 1;

    char header0[COL][15];
    char header1[COL][15];

    char buffer[15];
    fscanf(file0, "%s", buffer);//for reading DAY
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

    u_int32_t *fileCount0 = (u_int32_t *)malloc(sizeof(u_int32_t) * ROW0 * COL);
    u_int32_t *fileCount1 = (u_int32_t *)malloc(sizeof(u_int32_t) * ROW1 * COL);

    rewind(file0);
    rewind(file1);

    // reading the file
    char buff[1000];
    fgets(buff, 1000, file0);
    for (int i = 0; i < countLinesFile0 - 1; i++)//number of row/lines
    {
      char weekday[10];
      fscanf(file0, "%s", weekday);// to read the weekday
      for (int j = 0; j < COL; j++)
      {
        fscanf(file0, "%u", &fileCount0[i * ROW0 + j]);
      }
    }

    // printing for debgugging
    for (int i = 0; i < countLinesFile0 - 1; i++)
    {
      // char weekday[10];
      // fscanf(file0, "%s", &weekday);
      for (int j = 0; j < 5; j++)
      {
        printf("%u ", fileCount0[i * ROW0 + j]);
      }
      printf("\n");
    }

    printf("\n");

    // reading the file1
    fgets(buff, 1000, file1);
    for (int i = 0; i < countLinesFile1 - 1; i++)
    {
      char weekday[10];
      fscanf(file1, "%s", weekday);
      for (int j = 0; j < 5; j++)
      {
        fscanf(file1, "%u", &fileCount1[i * ROW0 + j]);
      }
    }

    // printing for debgugging1
    for (int i = 0; i < countLinesFile1 - 1; i++)
    {
      // char weekday[10];
      // fscanf(file0, "%s", &weekday);
      for (int j = 0; j < 5; j++)
      {
        printf("%u ", fileCount1[i * ROW1 + j]);
      }
      printf("\n");
    }

    display_sales(header0, fileCount0, countLinesFile0);
    display_sales(header1, fileCount1, countLinesFile1);
    return 0;
    fclose(file0);
    fclose(file1);

  }
  else
  {
    printf("Unexpected Input from Command line!\n");
    return 1;
  }
}