/*
Name: Mohammed Thamidur Rashid
NSID: mor867
Student: #11280257
*/
#include <stdio.h>
#include <string.h>

typedef struct fileInfo
{
  int row;
  int column;
} FileInfo;

FileInfo countLines(FILE *name)
{
  FileInfo newFileInfo = {0, 0};

  char c;

  while ((c = fgetc(name)) != EOF)
  {
    if (c == '\n')
      newFileInfo.row++;
  }
  newFileInfo.column = 6;
  return newFileInfo;
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

// 
void modifyFileName(char fileName[], char modifiedFileName[]){
     
      for (int i = 0; i < strlen(fileName); i++ ){
      if (fileName[i] == '.'){
        fileName[i] = '\0';
      }
    } 
    sprintf(modifiedFileName, "%s-revised.txt", fileName);
}

void writeToFile(FILE *file, FILE *newFile, int row, int column, int fileCount[row][column]){

    // defining the weekdays
    const char *weekDays[5];
    weekDays[0] = "Monday";
    weekDays[1] = "Tuesday";
    weekDays[2] = "Wednesday";
    weekDays[3] = "Thursday";
    weekDays[4] = "Friday";
    
  if (newFile != NULL)
    {
      printf("Writing to the file");
      char buff[1000];
      fgets(buff, 1000, file); //skip the first line!
      fprintf(newFile, "%s", buff);
      for (int i = 0; i < row; i++)
      {
        fprintf(newFile, "%s", weekDays[i]);

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
    FileInfo countLinesFile0 = countLines(file0);

    FileInfo countLinesFile1 = countLines(file1);

    printf("------FILE0-----\n");
    printf("Number of Lines: %d\n", countLinesFile0.row);
    printf("Number of Columns: %d\n", countLinesFile0.column);

    printf("------FILE1-----\n");
    printf("Number of Lines: %d\n", countLinesFile1.row);
    printf("Number of Columns: %d\n", countLinesFile1.column);

    // resetting the file pointer to initial state for further operations
    rewind(file0);
    rewind(file1);

    int file0Count[countLinesFile0.row - 1][countLinesFile0.column - 1],
        file1Count[countLinesFile1.row - 1][countLinesFile1.column - 1];
    //-1 to accomodate for the decription row and column.

    // function to read the content of the files into the 2d array
    readFile(file0, countLinesFile0.row - 1, countLinesFile0.column - 1, file0Count);
    readFile(file1, countLinesFile1.row - 1, countLinesFile1.column - 1, file1Count);

    // printing the content of the files for debugging
    printf("%s \n", fileName0);

    for (int i = 0; i < countLinesFile0.row - 1; i++)
    {
      for (int j = 0; j < countLinesFile0.column - 1; j++)
      {
        printf("%d ", file0Count[i][j]);
      }
      printf("\n");
    }

    printf("%s \n", fileName1);

    for (int i = 0; i < countLinesFile1.row - 1; i++)
    {
      for (int j = 0; j < countLinesFile1.column - 1; j++)
      {
        printf("%d ", file1Count[i][j]);
      }
      printf("\n");
    }

    // swapping the values considering the files have the same number of entries

    for (int i = 0; i < countLinesFile0.row - 1; i++)
    {
      int temp = 0;
      temp = file0Count[i][4];
      file0Count[i][4] = file1Count[i][4];
      file1Count[i][4] = temp;
    }

    printf("After swapping the values\n%s \n", argv[1]);

    for (int i = 0; i < countLinesFile0.row - 1; i++)
    {
      for (int j = 0; j < countLinesFile0.column - 1; j++)
      {
        printf("%d ", file0Count[i][j]);
      }
      printf("\n");
    }

    printf("%s \n", argv[2]);

    for (int i = 0; i < countLinesFile1.row - 1; i++)
    {
      for (int j = 0; j < countLinesFile1.column - 1; j++)
      {
        printf("%d ", file1Count[i][j]);
      }
      printf("\n");
    }

    // writing to the new files
    FILE *newFile0, *newFile1; 

    char modifiedFileName0 [32], modifiedFileName1 [32];

    //modifying the file names
    modifyFileName(fileName0, modifiedFileName0);
    modifyFileName(fileName1, modifiedFileName1);

    newFile0 = fopen(modifiedFileName0, "w+");
    newFile1 = fopen(modifiedFileName1, "w+");

    printf("The modified files name: %s\n", modifiedFileName0);
    printf("The modified files name: %s\n", modifiedFileName1);


    // write it on the file
    rewind(file0);
    rewind(file1);


    writeToFile(file0, newFile0, countLinesFile0.row -1, countLinesFile0.column - 1, file0Count );

    writeToFile(file1, newFile1, countLinesFile1.row -1, countLinesFile1.column - 1, file1Count );

    return 0;
  }
  else
  {
    printf("Unexpected Input from Command line!\n");
    return 1;
  }
}