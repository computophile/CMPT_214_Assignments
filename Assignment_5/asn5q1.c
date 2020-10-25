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
  while ((c = fgetc(name)) != EOF)
  {

    if (c == '\n')
      linesCount++;
  }
  // int data_fruits[][];
  return linesCount - 1; //-1 for the first line
}

int main(int argc, char *argv[])
{
  FILE *fruits, *dairy;

  dairy = fopen("dairyCopy.txt", "r+");
  fruits = fopen("fruitsCopy.txt", "r+");

  // count the number of lines in the program:

  int countLinesFruit = countLines(fruits);
  int countLinesDairy = countLines(dairy);

  printf("%d\n", countLinesFruit);
  printf("%d\n", countLinesDairy);

  rewind(fruits);
  rewind(dairy);

  int itemsCount = 5;
  int *fruitCount[itemsCount][countLinesFruit], *dairyCount[itemsCount][countLinesDairy];

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
    if (dairy != NULL)
  {
    char buff[1000];
    fgets(buff, 1000, dairy);
    for (int i = 0; i < countLinesDairy; i++)
    {
      char dummy[1000];
      fscanf(dairy, "%s", dummy);
  
      for (int j = 0; j < itemsCount; j++)
      {
        fprintf(dairy, " %d", dairyCount[i][j]);
      }
      fprintf(dairy, "\n");
    }
  }
  fclose(dairy);
  fclose(fruits);
  return 0;
}