// C implementation
#define _CRT_SECURE_NO_WARNINGS
#ifndef _RECURSION_EXAMPLES
#define _RECURSION_EXAMPLES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// SWAP TWO INTEGERS
extern inline void Swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

// C
extern inline int CompareStrings() {
  char *str1, *str2;
  str1 = (char *)malloc(50 * sizeof(char));
  str2 = (char *)malloc(50 * sizeof(char));
  int str1Length, str2Length;
  printf("1.kelime: ");
  scanf("%s", str1);
  printf("2.kelime: ");
  scanf("%s", str2);
  str1Length = strlen(str1);
  str2Length = strlen(str2);
  if (str1Length != str2Length) {
    if (str1Length > str2Length) {
      printf("1. kelime daha uzun\n");
      return 0;
    } else {
      printf("2. kelime daha uzun\n");
      return 0;
    }
  }
  int i;
  if (str1Length == str2Length) {
    for (i = 0; i < str1Length; i++) {
      if (*(str1 + i) != *(str2 + i)) {
        printf("Kelimeler farkli, uzunluklari ayni");
        return 0;
      }
    }
    printf("Kelimeler ayni");
  }
  return 0;
}

// BUBBLE SORT
extern inline int BubbleSort() {
  int dizi[10] = {10, 25, 1, 8, 11, 54, 5, 14, 80, 91};
  int gecici, i, j, n = 10;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - 1 - i; j++) {
      if (dizi[j] > dizi[j + 1]) {
        gecici = dizi[j + 1];
        dizi[j + 1] = dizi[j];
        dizi[j] = gecici;
      }
    }
  }
  for (i = 0; i < n; i++) {
    printf("Bubble %d.deger: %d\n", i + 1, dizi[i]);
  }
  printf("----------------------\n");
  return 0;
};

// INSERTION SORT
extern inline void InsertionSort(int *array, int arraySize) {
  int current, i, j;
  for (j = 1; j < arraySize; j++) {
    current = array[j];
    i = j - 1;
    while (i > -1 & array[i] > current) {
      array[i + 1] = array[i];
      i--;
    }
    array[i + 1] = current;
  }
}

// SELECTION SORT
extern inline void SelectionSort(int array[], int arraySize) {
  int smallestNumber, index, i, j, temp;
  for (i = 0; i < arraySize - 1; i++) {
    smallestNumber = 99;
    for (j = i; j < arraySize; j++) {
      if (array[j] < smallestNumber) {
        smallestNumber = array[j];
        index = j;
      }
    }
    temp = array[i];
    array[i] = array[index];
    array[index] = temp;
  }
}

// MERGE TWO ARRAYS
extern inline int *mergeArray(int arraySize) {
  // TO BE WRITTEN IN MAIN
  // int arraySize, *resultArr, i;
  // printf("Bu birlestirme 2 adet dizi icin yapilacaktir.\n");
  // printf("Dizilerde kacar tane sayi olacak?: ");
  // scanf("%d", &arraySize);
  // resultArr = odevDiziBirlestir(arraySize);
  // printf("----------\n");
  // for (i = 0; i < 2 * arraySize; i++) {
  // printf("Sonuc dizinin %d. elemani: = %d\n", i + 1, *(resultArr + i));
  // }
  // free(resultArr);
  // END OF PART IN MAIN

  int i, j, k, *array1, *array2, *resultArray;
  array1 = (int *)malloc(arraySize * sizeof(int));
  array2 = (int *)malloc(arraySize * sizeof(int));
  resultArray = (int *)malloc(2 * arraySize * sizeof(int));

  for (i = 0; i < arraySize; i++) {
    printf("1.dizinin %d. elemani: ", i + 1);
    scanf("%d", (array1 + i));
  }
  printf("----------\n");
  for (i = 0; i < arraySize; i++) {
    printf("2.dizinin %d. elemani: ", i + 1);
    scanf("%d", (array2 + i));
  }

  i = 0;
  j = 0;
  k = 0;

  while (i < arraySize && j < arraySize) {
    if (*(array1 + i) <= *(array2 + j)) {
      *(resultArray + k) = *(array1 + i);
      *(array1 + i) = 0;
      i++;
    } else {
      *(resultArray + k) = *(array2 + j);
      *(array2 + j) = 0;
      j++;
    }
    k++;
  }

  while (i < arraySize) {
    if (*(array1 + i) != 0) {
      *(resultArray + k) = *(array1 + i);
      i++;
      k++;
    }
  }

  while (j < arraySize) {
    if (*(array2 + j) != 0) {
      *(resultArray + k) = *(array2 + j);
      j++;
      k++;
    }
  }

  free(array1);
  free(array2);
  return resultArray;
}
// ITERATIVE BINARY SEARCH
extern inline int binarySearchIterative(int arr[], int x, int start, int end) {
  // THIS PART GOES TO MAIN
  // int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, input, result;
  // printf("Aranacak deger giriniz: ");
  // scanf("%d", &input);
  // result = binarySearchIterative(array, input, 0, 9);
  // if (result == 1)
  //   printf("Sayi arrayde mevcut\n");
  // else
  //   printf("Sayi arrayde mevcut degil\n");
  // END OF PART IN MAIN

  int result = 0;

  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == x) {
      result = 1;
      break;
    }
    if (arr[mid] > x) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return result;
};
// RECURSIVE SUM OF NUMBERS BETWEEN 0-N
extern inline int toplama(int n) {

  if (n == 1) {
    return 1;
  } else {
    return n + toplama(n - 1);
  }
}

// RECURSIVE FACTORIAL CALCULATION
extern inline int faktoriyel(int n) {

  if (n <= 1) {
    return 1;
  } else {
    return n * (faktoriyel(n - 1));
  }
}

// RECURSIVE CHECK IF NUMBER IS PRIME
extern inline int asalSayiKontrol(int n, int sayac) {

  if (sayac == 1) // eger 1 e geldiysek ve hala arama bitmediyse, sayi asaldir
    return 1;
  else if (sayac != n && n % sayac == 0) {
    return 0;
  } else
    return asalSayiKontrol(n, sayac - 1);
}

// RECURSIVE OKEK CALCULATION
extern inline int okekHesapla(int m, int n) {
  static int okek = 1;

  if (okek % m == 0 && okek % n == 0)
    return okek;

  okek++;
  okekHesapla(m, n);
  return okek;
}

// RECURSIVE FIBONACCI CALCULATION
extern inline int fibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  } else
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// RECURSIVE POWER OF NUMBER CALCULATION
extern inline int ustelHesaplama(int asilSayi, int ust) {

  if (ust == 1)
    return asilSayi;
  else {
    return (asilSayi * ustelHesaplama(asilSayi, ust - 1));
  }
}

// RECURSIVE FIND BIGGEST NUMBER IN AN ARRAY
extern inline int enBuyukSayi(int a[], int n) {
  static int sonuc = 0;

  if (n == 1)
    return sonuc;

  if (sonuc < a[n]) {
    sonuc = a[n];
  }
  return enBuyukSayi(a, n - 1);
}

// RECURSIVE NUMBER DIGIT SUM
extern inline int basamakTopla(int n) {

  int kalan = n / 10;
  if (kalan == 0)
    return n;
  else
    return n % 10 + basamakTopla(kalan);
}

// RECURSIVE OBEB CALCULATION
extern inline int obebHesapla(int num1, int num2) {

  int kalan;
  kalan = num1 % num2;
  if (kalan == 0)
    return num2;
  else
    return obebHesapla(num2, kalan);
}

// RECURSIVE INSERTION SORT SOLUTION
extern inline void insertionSortRekursif(int array[], int n) {
  int i, finalValue;

  if (n <= 1)
    return;

  insertionSortRekursif(array, n - 1);

  finalValue = array[n - 1];
  i = n - 2;

  while (i > -1 && array[i] > finalValue) {
    array[i + 1] = array[i];
    i--;
  }
  array[i + 1] = finalValue;
}

// POPULATE ARRAY WITH RANDOM NUMBERS
extern inline void populateArray(int inputArray[], int arrayLength) {
  int i;

  for (i = 0; i < arrayLength; i++) {
    int temp = rand() % 50 + 1;
    inputArray[i] = temp;
    printf("%d.number: %d\n", i + 1, inputArray[i]);
  }
}

#endif
