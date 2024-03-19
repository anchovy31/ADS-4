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
  int k = 0, count = 0, jbas = NumOfLastValue(arr, len, value);
  int flag = 0, prevk = 0, j = 0;
  j = jbas;
  for (int i = 0; arr[i] <= value / 2; i++) {
    while (i < j) {
      if (flag = 1 && arr[i] == arr[i - 1]) {
        while (arr[i] == arr[i - 1]) {
          count += prevk;
          i++;
        }
      } else {
        if (arr[i] + arr[j] == value) {
          k++;
          count++;
          j--;
          if (i >= j) {
            i++;
            prevk = k;
            k = 0;
            j = jbas;
          }
        } else if (value - arr[i] < arr[j]) {
          j--;
        } else {
          i++;
          prevk = k;
          k = 0;
          j = jbas;
          flag = 1;
        }
      }
    }
  }
  return count;
}
