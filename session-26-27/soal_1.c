#include <stdio.h>
#include <stdlib.h>

void inputToFile(int num, FILE *file)
{
  fprintf(file, "%d\n", num);
}

FILE *OpenFile(const char *fileName, char mode)
{
  FILE *file;

  switch (mode)
  {
  case 'r':
    file = fopen(fileName, "r");
    break;
  case 'w':
    file = fopen(fileName, "w");
    break;
  default:
    break;
  }

  if (file == NULL)
  {
    printf("Error opening file!\n");
    exit(404);
  }

  return file;
}

int main()
{
  FILE *fileAngka;
  FILE *fileGanjil;
  FILE *fileGenap;
  int num;

  fileAngka = OpenFile("angka.txt", 'r');
  fileGanjil = OpenFile("ganjil.txt", 'w');
  fileGenap = OpenFile("genap.txt", 'w');

  printf("\n============================================================\n");
  printf("\nSoal 1\n");
  printf("\n============================================================\n\n");

  puts("Sorting Number on angka.txt...");
  while (fscanf(fileAngka, "%d", &num) != EOF)
  {
    if (num % 2 == 1)
    {
      inputToFile(num, fileGanjil);
    }
    else
    {
      inputToFile(num, fileGenap);
    }
  }

  puts("\n============================================================\n");
  puts("Done : PLease check ganjil.txt and genap.txt");
  puts("\n============================================================");

  fclose(fileAngka);
  fclose(fileGanjil);
  fclose(fileGenap);
  return 0;
}
