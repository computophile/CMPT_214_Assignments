/*
Name: Mohammed Thamidur Rashid
NSID: mor867
Student: #11280257
*/
#include <stdio.h>
#include <string.h>

typedef struct fileInfo
{
  // struct to store the individual file information
  // of line numbers and column
  int row;
  int column;
} FileInfo;

FileInfo countLines(FILE *name)
{
  //Purpose: counts the number of lines that are in the file and returns a struct
  // *name: pointer to the file that will be read to cound the number of lines

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

int readFile(FILE *name, int row, int column, int fileContent[row][column])
{
  // Purpose: to read the file content into the fileContent data structure;
  // *name: pointer to the file that will be read
  // row: number of rows for the fileContent to be stored
  // columns: number of columns for the fileContent to be stored
  // fileContent: 2D array to store the data

  if (name != NULL)
  {
    char buff[100];
    fgets(buff, 100, name); //reads the first line
    for (int i = 0; i < row; i++) //not using feof() as I know exactly how many lines I will be reading as it is checked earlier;
    {
      char weekday[100];
      fscanf(name, "%s", weekday);
      for (int j = 0; j < column; j++)
      {
        fscanf(name, "%d", &fileContent[i][j]);
      }
    }
    return 0;
  }
  else
  {
    return 1;
  }
  
}

//
void modifyFileName(char fileName[], char modifiedFileName[])
{
  // modify the name of the files,
  // fileName: received file name, 
  // modifiedFileName: the modified file name
  for (int i = 0; i < strlen(fileName); i++)
  {
    if (fileName[i] == '.')
    {
      fileName[i] = '\0';//truncate the string at "."
    }
  }
  sprintf(modifiedFileName, "%s-revised.txt", fileName);
}

int writeToFile(FILE *file, FILE *newFile, int row, int column, int fileCount[row][column])
{
  // Purpose: writing the revised files into the disk;
  // *file: pointer to the old file
  // *newFile: pointer to the new file
  // row: number of row to be written;
  // colum: number of columns to be written in each file
  // fileCount: the corrected data to be written to the file;
  
  // defining the weekdays
  const char *weekDays[5];
  weekDays[0] = "Monday";
  weekDays[1] = "Tuesday";
  weekDays[2] = "Wednesday";
  weekDays[3] = "Thursday";
  weekDays[4] = "Friday";

  if (newFile != NULL)
  {
    char buff[100];
    fgets(buff, 100, file); //skip the first line!
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
    fclose(newFile);
    return 0;//if successful
  }
  else
  {
    return 1;//if error in reading the file
  }
}

// main funciton
int main(int argc, char *argv[])
{
  FILE *file0, *file1;

  char fileName0[20], fileName1[20]; //storing the file names from the command line

  if (argc == 3) //checking for the number of arguments passed to the function
  {

    strcpy(fileName0, argv[1]);
    strcpy(fileName1, argv[2]);

    file0 = fopen(fileName0, "r");
    file1 = fopen(fileName1, "r");

    if(file0 == NULL || file1 == NULL){
      printf("Error reading files!\n");
      return 1;//if error
    }

    // count the number of lines in the program:
    FileInfo countLinesFile0 = countLines(file0);

    FileInfo countLinesFile1 = countLines(file1);

    // resetting the file pointer to initial state for further operations
    rewind(file0);
    rewind(file1);

    int file0Count[countLinesFile0.row - 1][countLinesFile0.column - 1],
        file1Count[countLinesFile1.row - 1][countLinesFile1.column - 1];
    //-1 to accomodate for the decription on row and column.

    // function to read the content of the files into the 2D array
    int readSuccess0 = readFile(file0, countLinesFile0.row - 1, countLinesFile0.column - 1, file0Count);
    int readSuccess1 = readFile(file1, countLinesFile1.row - 1, countLinesFile1.column - 1, file1Count);

    if (readSuccess0 == readSuccess1 && readSuccess0 == 1){
      printf("Error in reading files!\n");
      return 1;//if error in reading the files;
    }
    
    // swapping the values considering the files have the same number of entries
    if (countLinesFile0.row == countLinesFile1.row)
    {
      for (int i = 0; i < countLinesFile0.row - 1; i++)
      {
        int temp = 0;
        temp = file0Count[i][4];
        file0Count[i][4] = file1Count[i][4];
        file1Count[i][4] = temp;
      }
    }

    // writing to the new files
    FILE *newFile0, *newFile1;

    char modifiedFileName0[32], modifiedFileName1[32];

    //modifying the file names
    modifyFileName(fileName0, modifiedFileName0);
    modifyFileName(fileName1, modifiedFileName1);

    newFile0 = fopen(modifiedFileName0, "w+");
    newFile1 = fopen(modifiedFileName1, "w+");

    // write it on the file
    rewind(file0);
    rewind(file1);

    int successCode0 = writeToFile(file0, newFile0, countLinesFile0.row - 1, countLinesFile0.column - 1, file0Count);

    int successCode1 = writeToFile(file1, newFile1, countLinesFile1.row - 1, countLinesFile1.column - 1, file1Count);

    if (successCode0 == successCode1 && successCode0 == 0)
    {
      printf("%s, %s written succesfully!\n", modifiedFileName0, modifiedFileName1);
      return 0;
    }
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