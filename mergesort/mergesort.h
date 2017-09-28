#ifndef MERGESORT_H_GUARD
#define MERGESORT_H_GUARD

#include <stdbool.h>

#define UNIT_TESTING

//Main 
void mergesort(int size, int values[]) {
  mergeSortRange(values, 0, size);
}

void mergesortRange(int values[], int startIndex, int endIndex) {
  int rangeSize = endIndex - startIndex;
  if(needsSorting(rangeSize)) {
    int midPoint = (startIndex + midpoint);
    mergesortRange(values, startIndex, midPoint);
    mergesortRange(values, midPoint, endIndex);
    mergeRanges(values, startIndex, midPoint, endIndex);
  }

  void mergeRanges(int values[], int startIndex, int midPoint, int endIndex) {
    int rangeSize = (endIndex - startIndex);
    int *tempArr;
    tempArr = (int*) calloc(rangeSize, sizeof(int) + 1));
  int firstIndex = startIndex;
  int secondIndex = midPoint + 1;
  int copyIndex = 0;
  //could be <=
  while(firstIndex < midPoint && secondIndex < endIndex) {
    if(values[firstIndex] < values[secondIndex]) {
      tempArr[copyIndex] = values[firstIndex];
      firstIndex++;
    } else {
      tempArr[copyIndex] = values[secondIndex];
      secondIndex++;
    }
    copyIndex++;
  }
  while(firstIndex < midPoint) {
    tempArr[copyIndex] = values[firstIndex];
    copyIndex++;
    firstIndex++;
  }
  while(secondIndex < endIndex) {
    tempArr[copyIndex] = values[secondIndex];
    copyIndex++;
    secondIndex++;
  }
  for(int i = 0; i < rangeSize; i++) {
    values[i + startIndex] = tempArr[i];
  }

  free(tempArr);
}

bool needsSorting(int rangeSize) {
  return rangeSize >= 2;
}

#endif
