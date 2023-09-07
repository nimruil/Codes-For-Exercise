// C implementation

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define M 3
#define N 4

// T
// PROGRAMIN CALISMASINI TAKIP ETMEK ICIN KULLANILABILIRLER

// ARZ - TALEP DENGESI KONTROLU
void equalityCheck(int[], int[]);
// ILGILI YOLDAN SAGLANABILECEK AZAMI ARZIN HESABI
int maxPossibleSupply(int[], int[], int, int);
// EGER TALEP KARSILANDIYSA SUTUNU KAPAT (-1 KULLANILDI)
void makeRemainingColumnNull(int, int (*)[M][N], int);
// EGER ARZ KALMADIYSA SATIRI KAPAT (-1 KULLANILDI)
void makeRemainingRowNull(int, int (*)[M][N], int);
// KUZEYBATI KOSESI YONTEMI
void northWest(int[M][N], int[], int[], int (*)[M][N]);
// EN DUSUK MALIYETLER YONTEMI
void minimumCost(int[M][N], int[], int[], int (*)[M][N]);
// PROGRAMIN SONUC CIKTILARI, METHODNUMBER = 0 MIN MALIYETLER, 1 KUZEYBATI
void printResults(int methodNumber, int[M][N], int[M][N]);
// CIFT BOYUTLU DIZI KOPYALAMA FONKSIYONU
void copyArray(int (*)[M][N], int[M][N]);
// TEK BOYUTLU DIZI KOPYALAMA FONKSIYONU
void copyArray2(int *, int *, int);

int main() {
  int costs[M][N] = {{10, 2, 20, 11}, {12, 7, 9, 20}, {4, 14, 16, 18}};
  int supply[M] = {15, 25, 10};
  int demand[N] = {5, 15, 15, 15};
  int usageNW[M][N] = {0};
  int usageMC[M][N] = {0};
  int(*p_usageNW)[M][N] = &usageNW; // 2D ARRAY POINTERI
  int(*p_usageMC)[M][N] = &usageMC; // 2D ARRAY POINTERI
  equalityCheck(supply, demand);
  northWest(costs, supply, demand, p_usageNW);
  printResults(1, costs, usageNW);
  minimumCost(costs, supply, demand, p_usageMC);
  printResults(0, costs, usageMC);
  return 0;
}

void equalityCheck(int supply[], int demand[]) {
  int result = 0, sumSupply = 0, sumDemand = 0;
  printf("\nArz - talep dengesi kontrol ediliyor. ");
  for (int i = 0; i < M; i++) {
    sumSupply += supply[i];
  }
  for (int i = 0; i < N; i++) {
    sumDemand += demand[i];
  }
  if (sumSupply == sumDemand) {
    result = 1;
  }
  if (!result) {
    printf("Arz - talep dengesi yok!\nProgramdan cikiliyor.\n");
    exit(0);
  } else
    printf("Arz - talep dengesi mevcut.\n\n");
}

void northWest(int costs[M][N], int supply[], int demand[],
               int (*usage)[M][N]) {
  // OLABILECEK AZAMI ARZ HESABINI YAPIP,BUNU ARZ VE TALEPLERDEN DUSMEK GEREKIR
  // KULLANIM MATRISINE BU DEGERLER ISLENIR
  // SUPPLY VEYA DEMANDDEN SIFIRLANAN HANGISIYSE ILGILI SATIR VEYA SUTUNDA
  // KALANLAR KAPATILIR (-1) KI SONRADAN IHMAL EDILEBILSIN
  int costsArray[M][N];
  int demandArray[N];
  int supplyArray[M];
  int(*p_costsArray)[M][N] = &costsArray;
  copyArray2(demandArray, demand, N);
  copyArray2(supplyArray, supply, M);
  copyArray(p_costsArray, costs);
  int currentValue, row, col;
  while (1) {
    currentValue = INT_MAX;
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (costsArray[i][j] != -1) {
          currentValue = costsArray[i][j];
          row = i;
          col = j;
        }
        if (currentValue < INT_MAX)
          break; // DEGER BULUNDUYSA FOR DAN CIK
      }
      if (currentValue < INT_MAX)
        break; // DEGER BULUNDUYSA FOR DAN CIK
      else if (currentValue == INT_MAX && i == M - 1)
        break; // DEGER BULUNDUYSA FOR DAN CIK
    }

    if (currentValue == INT_MAX)
      break; // BAKILACAK DEGER KALMADIYSA WHILE DAN CIK

    int temp = maxPossibleSupply(supplyArray, demandArray, row, col);
    supplyArray[row] -= temp;
    demandArray[col] -= temp;
    (*usage)[row][col] += temp;

    if (!supplyArray[row])
      makeRemainingRowNull(0, p_costsArray, row);
    if (!demandArray[col])
      makeRemainingColumnNull(0, p_costsArray, col);
  }
}

void minimumCost(int costs[M][N], int supply[], int demand[],
                 int (*usage)[M][N]) {
  // EN DUSUK MALIYETLI YOLUN ROW,COL DEGERLERINI BUL
  // BUNU YAPARKEN KAPATILMIS DEGERLERI GOZONUNE ALMA
  // OLABILECEK AZAMI ARZ HESABINI YAPIP,BUNU ARZ VE TALEPLERDEN DUSMEK GEREKIR
  // KULLANIM MATRISINE BU DEGERLER ISLENIR
  // SUPPLY VEYA DEMANDDEN SIFIRLANAN HANGISIYSE ILGILI SATIR VEYA SUTUNDA
  // KALANLAR KAPATILIR (-1) KI SONRADAN IHMAL EDILEBILSIN
  int costsArray[M][N];
  int demandArray[N];
  int supplyArray[M];
  int(*p_costsArray)[M][N] = &costsArray;
  copyArray2(demandArray, demand, N);
  copyArray2(supplyArray, supply, M);
  copyArray(p_costsArray, costs);
  int minValue, row, col;
  while (1) {
    minValue = INT_MAX;
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (costsArray[i][j] < minValue && costsArray[i][j] != -1) {
          minValue = costsArray[i][j];
          row = i;
          col = j;
        }
      }
    }

    if (minValue == INT_MAX)
      break; // BAKILACAK DEGER KALMADIYSA WHILE DAN CIK

    int temp = maxPossibleSupply(supplyArray, demandArray, row, col);
    supplyArray[row] -= temp;
    demandArray[col] -= temp;
    (*usage)[row][col] = temp;

    if (!supplyArray[row])
      makeRemainingRowNull(0, p_costsArray, row);
    if (!demandArray[col])
      makeRemainingColumnNull(0, p_costsArray, col);
  }
}

int maxPossibleSupply(int supply[], int demand[], int i, int j) {
  int result = 0;
  if (demand[j] <= supply[i])
    result = demand[j];
  else
    result = supply[i];
  return result;
}

void makeRemainingColumnNull(int methodNumber, int (*usage)[M][N],
                             int colNumber) {
  if (methodNumber) {
    for (int i = 0; i < M; i++) {
      if (!(*usage)[i][colNumber])
        (*usage)[i][colNumber] = -1;
    }
  } else {
    for (int i = 0; i < M; i++) {
      (*usage)[i][colNumber] = -1;
    }
  }
}

void makeRemainingRowNull(int methodNumber, int (*usage)[M][N], int rowNumber) {
  if (methodNumber) {
    for (int i = 0; i < N; i++) {
      if (!(*usage)[rowNumber][i])
        (*usage)[rowNumber][i] = -1;
    }
  } else {
    for (int i = 0; i < N; i++) {
      (*usage)[rowNumber][i] = -1;
    }
  }
}

void printResults(int methodNumber, int costs[M][N], int usage[M][N]) {
  int z = 0;

  if (methodNumber) // 1 ISE PRINT KUZEYBATI DEGILSE PRINT MIN. COSTS
    printf("Kuzeybati Kosesi Yontemi Sonuclar:\n");
  else
    printf("En Dusuk Maliyetler Yontemi Sonuclar:\n");

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (usage[i][j] > 0) {
        printf("X%d%d = %d\n", i + 1, j + 1, usage[i][j]);
        z += usage[i][j] * costs[i][j];
      }
    }
  }
  printf("Z (maliyet) = %d\n\n", z);
}

void copyArray(int (*mainArray)[M][N], int auxArray[M][N]) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      (*mainArray)[i][j] = auxArray[i][j];
    }
  }
}

void copyArray2(int *mainArray, int *auxArray, int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    mainArray[i] = auxArray[i];
  }
}

// printf("COST MATRIX\n");
// for (int i = 0; i < M; i++) {
//   for (int j = 0; j < N; j++) {
//     printf("%d", (costsArray)[i][j]);
//     if (j == N - 1)
//       printf("\n");
//     else
//       printf("\t");
//   }
// }
// printf("USAGE MATRIX\n");
// for (int i = 0; i < M; i++) {
//   for (int j = 0; j < N; j++) {
//     printf("%d", (*usage)[i][j]);
//     if (j == N - 1)
//       printf("\n");
//     else
//       printf("\t");
//   }
// }
