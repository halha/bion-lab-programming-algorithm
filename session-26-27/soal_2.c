#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, *arrSiswa, totalScore = 0;
  float averageScore;

  printf("\n============================================================\n");
  printf("\nSoal 2\n");
  printf("\n============================================================\n\n");

  printf("Masukkan jumlah siswa : ");
  scanf("%d", &n);

  arrSiswa = (int *)malloc(n * sizeof(int));
  if (arrSiswa == NULL)
  {
    printf("Gagal Alokasi Memori!\n");
    return 1;
  }

  for (int i = 0; i < n; i++)
  {
    printf("Masukkan nilai mahasiswa ke-%d: ", i + 1);
    scanf("%d", &arrSiswa[i]);
  }

  for (int i = 0; i < n; i++)
  {
    totalScore += arrSiswa[i];
  }

  averageScore = (float)totalScore / n;

  printf("Rata-Rata nilai : %.2f", averageScore);

  free(arrSiswa);
  return 0;
}