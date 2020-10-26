/*
Name: Mohammed Thamidur Rashid
NSID: mor867
Student: #11280257
*/
#include <stdio.h>

typedef struct fileInfo
{
  int column;
  int row;
} FileInfo;

FileInfo countLines(FILE *name)
{
  FileInfo newFile = {0, 0};

  char c;

  while ((c = fgetc(name)) != EOF)
  {
    if (c == '\n')
      newFile.row++;
  }
  rewind(name);
  char buff[100];
  fgets(buff, 100, name);
  // printf("buffer value: %s\n", buff);
  for (int i = 0; i < 100; i++)
  {
    if (buff[i] == ' ' || buff[i] == '\n')
    {
      ++newFile.column;
      // printf("%d ", i);
    }
  }

  // printf("the word count aka column count is : %d\n", newFile.column);
  return newFile;
}

// main funciton
int main(int argc, char *argv[])
{
  FILE *file0, *file1;

  printf("The number of arguments recieved from the command line: %d\n", argc);
  // if (argc == 2)
  // {
  file0 = fopen("dairy.txt", "r+");
  file1 = fopen("fruits.txt", "r+");

  // count the number of lines in the program:
  FileInfo countLinesFile0 = countLines(file0);

  FileInfo countLinesFile1 = countLines(file1);

  printf("------FILE0-----\n");
  printf("Number of Lines: %d\n", countLinesFile0.row);
  printf("Number of Columns: %d\n", countLinesFile0.column);

  printf("------FILE1-----\n");
  printf("Number of Lines: %d\n", countLinesFile1.row);
  printf("Number of Columns: %d\n", countLinesFile1.column);

  // rewind(fruits);
  // rewind(dairy);
  fclose(file0);
  fclose(file1);

  // int itemsCount = 5;
  // int fruitCount[itemsCount][countLinesFruit],
  //     dairyCount[itemsCount][countLinesDairy];

  // // reading the fruits file
  // if (fruits != NULL)
  // {
  //   char buff[1000];
  //   fgets(buff, 1000, fruits);
  //   for (int i = 0; i < countLinesFruit; i++)
  //   {
  //     char dummy[1000];
  //     fscanf(fruits, "%s", dummy);
  //     printf("Reading for %s in fruits\n", dummy);
  //     for (int j = 0; j < itemsCount; j++)
  //     {
  //       fscanf(fruits, "%d", &fruitCount[i][j]);
  //       printf("%d ", fruitCount[i][j]);
  //     }
  //     printf("\n");
  //   }
  // }

  // // reading the dairy file
  // printf("Reading the dairy file \n");
  // if (dairy != NULL)
  // {
  //   char buff[1000];
  //   fgets(buff, 1000, dairy);
  //   for (int i = 0; i < countLinesDairy; i++)
  //   {
  //     char dummy[1000];
  //     fscanf(dairy, "%s", dummy);
  //     // printf("Reading for %s", dummy);
  //     for (int j = 0; j < itemsCount; j++)
  //     {
  //       fscanf(dairy, "%d", &dairyCount[i][j]);
  //       printf("%d ", dairyCount[i][j]);
  //     }
  //     printf("\n");
  //   }
  // }

  // // swapping the values

  // for (int i = 0; i < countLinesFruit; i++)
  // {
  //   int temp = 0;
  //   temp = dairyCount[i][4];
  //   dairyCount[i][4] = fruitCount[i][4];
  //   fruitCount[i][4] = temp;
  // }

  // printf("After the values are swapped-- showing fruit count\n");
  // for (int i = 0; i < countLinesDairy; i++)
  // {
  //   for (int j = 0; j < itemsCount; j++)
  //   {
  //     printf("%d ", fruitCount[i][j]);
  //   }
  //   printf("\n");
  // }

  // printf("After the values are swapped-- showing dairy count\n");
  // for (int i = 0; i < countLinesDairy; i++)
  // {
  //   for (int j = 0; j < itemsCount; j++)
  //   {
  //     printf("%d ", dairyCount[i][j]);
  //   }
  //   printf("\n");
  // }

  // // write it on the file
  // // reading the dairy file
  // rewind(dairy);
  // printf("writing the dairy file swapping from fruits \n");
  // const char *weekDays[5];
  // weekDays[0] = "Monday";
  // weekDays[1] = "Tuesday";
  // weekDays[2] = "Wednesday";
  // weekDays[3] = "Thursday";
  // weekDays[4] = "Friday";

  // if (dairy != NULL)
  // {

  //   char buff[1000];
  //   fgets(buff, 1000, dairy); //skip the first line!

  //   for (int i = 0; i < countLinesDairy; i++)
  //   {
  //     char dummy[20];
  //     fprintf(dairy, "%s", weekDays[i]);
  //     printf("The value of dummy : %s\n", weekDays[i]);

  //     for (int j = 0; j < itemsCount; j++)
  //     {
  //       fprintf(dairy, " %d", dairyCount[i][j]);
  //       printf("%d ", dairyCount[i][j]);
  //     }
  //     printf("putting a new line\n");
  //     fprintf(dairy, " \n");
  //   }
  // }
  // fclose(dairy);
  // fclose(fruits);
  // return 0;
  // }
  // else
  // {
  //   printf("Unexpected Input from Command line!");
  //   return 1;
  // }
}