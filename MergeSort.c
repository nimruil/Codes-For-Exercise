// C implementation

void Merge(int array[], int start, int mid, int end) {
  int arraySize1, arraySize2, i, j, k;
  arraySize1 = mid - start + 1;
  arraySize2 = end - mid;
  int *array1, *array2;
  array1 = (int *)malloc((arraySize1 + 1) * sizeof(int));
  array2 = (int *)malloc((arraySize2 + 1) * sizeof(int));
  for (i = 0; i < arraySize1; i++) {
    array1[i] = array[start + i];
  }
  array1[i] = INT_MAX;
  for (i = 0; i < arraySize2; i++) {
    array2[i] = array[mid + i + 1];
  }
  array2[i] = INT_MAX;
  i = j = 0;
  for (k = start; k <= end; k++) {
    if (array1[i] <= array2[j]) {
      array[k] = array1[i];
      i++;
    } else {
      array[k] = array2[j];
      j++;
    }
  }
}

void MergeSort(int array[], int start, int end) {
  int mid;
  if (start < end) {
    mid = (start + end) / 2;
    MergeSort(array, start, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, start, mid, end);
  }
}
