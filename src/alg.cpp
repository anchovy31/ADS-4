// Copyright 2021 NNTU-CS
int NumOfLastValue(int arr[], int len, int value) {
  for (int i = len - 1; i >= 0; i--) {
    if (arr[i] <= value)
      return i;
  }
  return -1;
}
int countPairs1(int* arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        k++;
    }
  }
  return k;
}
int countPairs2(int* arr, int len, int value) {
  int k = 0, i = 0, jbas = NumOfLastValue(arr, len, value), j;
  j = jbas;
  while (arr[i] <= value / 2) {
    if (j > i) {
      if (arr[i] + arr[j] == value) {
        k++;
        j--;
      } else if (arr[i] + arr[j] > value) {
        j--;
      } else {
        i++;
        j = jbas;
      }
    } else {
      i++;
      j = jbas;
    }
  }
  return k;
}
int countPairs3(int* arr, int len, int value) {
    int k = 0, center, j = 0;
    int left = 0, right = 0;
    int minlen = NumOfLastValue(arr, len, value);
    for (int i = 0; i < minlen - 1; i++) {
        left = i, right = minlen + 1;
        while (left < right - 1) {
            center = (left + right) / 2;
            if (arr[i] + arr[center] == value) {
                k++;
                j = center + 1;
                while (arr[i] + arr[j] == value && j < right) {
                    k++;
                    j++;
                }
                j = center - 1;
                while (arr[i] + arr[j] == value && j > left) {
                    k++;
                    j--;
                }
                break;
            } else if (arr[i] + arr[center] > value) {
                right = center;
            } else {
                left = center;
            }
        }
    }
    return k;
}
