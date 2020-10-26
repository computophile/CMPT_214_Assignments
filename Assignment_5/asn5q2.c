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

int countLines(FILE *name)
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

void readFile(FILE *name, int row, int column, int fileContent[row][column])
{
  if (name != NULL)
  {
    char buff[1000];
    fgets(buff, 1000, name);
    for (int i = 0; i < row; i++)
    {
      char dummy[1000];
      fscanf(name, "%s", dummy);
      for (int j = 0; j < column; j++)
      {
        fscanf(name, "%d", &fileContent[i][j]);
      }
    }
  }
}

void writeToFile(FILE *file, FILE *newFile, int row, int column, int fileCount[row][column])
{

  // defining the weekdays
  const char *weekDays[5];
  weekDays[0] = "Monday";
  weekDays[1] = "Tuesday";
  weekDays[2] = "Wednesday";
  weekDays[3] = "Thursday";
  weekDays[4] = "Friday";
  printf("The value of row: %d, The value of Column: %d\n", row, column);

  if (newFile != NULL)
  {
    printf("Writing to the file");
    char buff[1000];
    fgets(buff, 1000, file); //skip the first line!
    fprintf(newFile, "%s", buff);
    for (int i = 0; i < row; i++)
    {
      fprintf(newFile, "%s", weekDays[i]);
      printf("The value of dummy : %s\n", weekDays[i]);

      for (int j = 0; j < column; j++)
      {
        fprintf(newFile, " %d", fileCount[i][j]);
      }
      fprintf(newFile, " \n");
    }
  }
  fclose(newFile);
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
    int countLinesFile0 = countLines(file0);

    int countLinesFile1 = countLines(file1);
    
    if (countLinesFile0<2 || countLinesFile1<2){
      printf("Less than 2 lines in the file!");
      return 1;
    }

    // resetting the file pointer to initial state for further operations
    rewind(file0);
    rewind(file1);

    // char header0[countLinesFile0][6];
    // char header0[countLinesFile1][6];

    // readHeaders
    //-1 to accomodate for the decription row and column.
    const size_t ROW0 = countLinesFile0 -1;
    const size_t ROW1 = countLinesFile1 -1;
    const size_t COL = 6 - 1;

// dynamically allocating a one-dimensional view of a two dimensional
// array that can hold all of the unsigned integer data in the file.

    u_int32_t *fileCount0 = (u_int32_t *) malloc(sizeof(u_int32_t) * ROW0 * COL);
    u_int32_t *fileCount1 = (u_int32_t *) malloc(sizeof(u_int32_t) * ROW1 * COL);
    
    // reading the file
    char buff[1000];
    fgets(buff, 1000, file0);
    for (int i = 0; i < countLinesFile0 -1; i++){
      char weekday[10];
      fscanf(file0, "%s", weekday);
      for (int j = 0 ; j < 5; j++){
          fscanf(file0, "%u", &fileCount0[i * ROW0 + j]);
      }
    }

// printing for debgugging
    for (int i = 0; i < countLinesFile0 -1; i++){
      // char weekday[10];
      // fscanf(file0, "%s", &weekday);
      for (int j = 0 ; j < 5; j++){
          printf("%u ", fileCount0[i * ROW0 + j]);
      }
      printf("\n");
    }

      printf("\n");

    // reading the file1
    fgets(buff, 1000, file1);
    for (int i = 0; i < countLinesFile1 -1; i++){
      char weekday[10];
      fscanf(file1, "%s", weekday);
      for (int j = 0 ; j < 5; j++){
          fscanf(file1, "%u", &fileCount1[i * ROW0 + j]);
      }
    }

// printing for debgugging1
    for (int i = 0; i < countLinesFile1 -1; i++){
      // char weekday[10];
      // fscanf(file0, "%s", &weekday);
      for (int j = 0 ; j < 5; j++){
          printf("%u ", fileCount1[i * ROW1 + j]);
      }
      printf("\n");
    }




    return 0;
  }
  else
  {
    printf("Unexpected Input from Command line!\n");
    return 1;
  }
}