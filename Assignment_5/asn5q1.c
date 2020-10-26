/*
Name: Mohammed Thamidur Rashid
NSID: mor867
Student: #11280257
*/
#include <stdio.h>

int countLines(FILE *name)
{
  int linesCount = 0;
  char c;
  int wordCount = 0;
  
  while ((c = fgetc(name)) != EOF)
  {
    if (c == '\n')
      linesCount++;
  }
  rewind(name);
  char buff[100];
  fgets(buff, 100, name);
  printf("buffer value: %s\n", buff);
  for(int i =0; i< 100; i++){
    		if(buff[i] == ' ' || buff[i] == '\n')
		{
			++wordCount;	
              printf("%d ", i);
              if (i ==160)
              printf("The value @ 160 %c:\n", buff[i]);
		} 
  }
  // int data_fruits[][];
  printf("the word count aka column count is : %d\n", wordCount);
  return linesCount -1; //-1 for the first line
}

int main(int argc, char *argv[])
{
  FILE *fruits, *dairy;

  dairy = fopen("dairyCopy.txt", "r+");
  fruits = fopen("fruitsCopy.txt", "r+");

  // count the number of lines in the program:
  int countLinesDairy = countLines(dairy);

  int countLinesFruit = countLines(fruits);


  printf("COunt lines dairy value: %d\n", countLinesDairy);

  printf("Count LInes fruit %d\n", countLinesFruit);

  rewind(fruits);
  rewind(dairy);

  int itemsCount = 5;
  int fruitCount[itemsCount][countLinesFruit], 
  dairyCount[itemsCount][countLinesDairy];

// reading the fruits file
  if (fruits != NULL)
  {
    char buff[1000];
    fgets(buff, 1000, fruits);
    for (int i = 0; i < countLinesFruit; i++)
    {
      char dummy[1000];
      fscanf(fruits, "%s", dummy);
      printf("Reading for %s in fruits\n", dummy);
      for (int j = 0; j < itemsCount; j++)
      {
        fscanf(fruits, "%d", &fruitCount[i][j]);
        printf("%d ", fruitCount[i][j]);
      }
      printf("\n");
    }
  }

// reading the dairy file
printf("Reading the dairy file \n");
    if (dairy != NULL)
  {
    char buff[1000];
    fgets(buff, 1000, dairy);
    for (int i = 0; i < countLinesDairy; i++)
    {
      char dummy[1000];
      fscanf(dairy, "%s", dummy);
      // printf("Reading for %s", dummy);
      for (int j = 0; j < itemsCount; j++)
      {
        fscanf(dairy, "%d", &dairyCount[i][j]);
        printf("%d ", dairyCount[i][j]);
      }
      printf("\n");
    }
  }

  // swapping the values

  for (int i = 0; i < countLinesFruit; i ++){
      int temp = 0;
      temp = dairyCount[i][4];
      dairyCount[i][4]= fruitCount[i][4];
      fruitCount[i][4] = temp;
    }

printf("After the values are swapped-- showing fruit count\n");
  for (int i = 0; i < countLinesDairy; i++)
    {
      for (int j = 0; j < itemsCount; j++)
      {
        printf("%d ", fruitCount[i][j]);
      }
      printf("\n");
    }


printf("After the values are swapped-- showing dairy count\n");
  for (int i = 0; i < countLinesDairy; i++)
    {
      for (int j = 0; j < itemsCount; j++)
      {
        printf("%d ", dairyCount[i][j]);
      }
      printf("\n");
    }



// write it on the file
// reading the dairy file
rewind (dairy);
printf("writing the dairy file swapping from fruits \n");
const char *weekDays[5];
weekDays[0] = "Monday";
weekDays[1] = "Tuesday";
weekDays[2] = "Wednesday";
weekDays[3] = "Thursday";
weekDays[4] = "Friday";

    if (dairy != NULL)
  {

    char buff[1000];
    fgets(buff, 1000, dairy); //skip the first line!

    for (int i = 0; i < countLinesDairy; i++)
    {
      char dummy[20];
      fprintf(dairy, "%s", weekDays[i]);
      printf("The value of dummy : %s\n", weekDays[i]);
      
      for (int j = 0; j < itemsCount; j++)
      {
        fprintf(dairy, " %d", dairyCount[i][j]);
        printf("%d ",  dairyCount[i][j]);
      }
      printf("putting a new line\n");
      fprintf(dairy, " \n");
    }
  }
  fclose(dairy);
  fclose(fruits);
  return 0;
}