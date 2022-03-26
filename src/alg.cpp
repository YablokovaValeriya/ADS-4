// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        count += 1;
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int t;
  for (int i = len - 1; i >= 0; i--) {
    if (arr[i] > value) {
      continue;
    } else {
      t = i;
      break;
    }
  }
  for (int i = 0; i < t - 1; i++) {
    for (int j = t; j >= i + 1; j--) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0, LBound = 0, RBound = len - 1;
  while (LBound < RBound - 1) {
    int middle_1 = (LBound + RBound) / 2;
    if (arr[middle_1] <= value)
      LBound = middle_1;
    else
      RBound = middle_1;
  }
  len = RBound - 1;
  for (int i = 0; i < len; i++) {
    LBound = i + 1, RBound = len - 1;
    int k = 0;
    while (LBound < RBound) {
      int middle_2 = (LBound + RBound) / 2;
      if (arr[middle_2] < (value - arr[i]))
        LBound = middle_2 + 1;
      else
        RBound = middle_2;
    }
    while (arr[LBound] == (value - arr[i])) {
      k++;
      LBound++;
    }
    count += k;
  }
  return count;
}
