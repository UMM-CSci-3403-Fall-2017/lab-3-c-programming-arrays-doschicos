#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "mergesort.h"

void mergeRanges(int* values, int startIndex, int midPoint, int endIndex){
        int rangeSize = endIndex - startIndex;
        int* temp = (int*) calloc(rangeSize+1, sizeof(int));
        int firstIndex = startIndex;
        int secondIndex = midPoint;
        int copyIndex = 0;
        while(firstIndex < midPoint && secondIndex < endIndex){
                if(values[firstIndex] < values[secondIndex]){
                	temp[copyIndex] = values[firstIndex];
                	firstIndex++;
        }else{
                	temp[copyIndex] = values[secondIndex];
                	secondIndex++;
        }
        	copyIndex++;
        }
        while (firstIndex < midPoint){
        	temp[copyIndex] = values[firstIndex];
        	copyIndex++;
        	firstIndex++;
        }
        while(secondIndex < endIndex){
        	temp[copyIndex] = values[secondIndex];
        	copyIndex++;
        	secondIndex++;
        }
        for(int i = 0;i < rangeSize; i++){
                values[i + startIndex] = temp[i];
        }

	free(temp);
        }

int needsSorting(int rangeSize){
  return (rangeSize >= 2);
  
}

void mergesortRange(int* values, int startIndex,int endIndex){
        int rangeSize = endIndex - startIndex;
        if(needsSorting(rangeSize) == 1){
                int midPoint = (startIndex + endIndex)/2;
                mergesortRange(values, startIndex, midPoint);
                mergesortRange(values, midPoint, endIndex);
                mergeRanges(values, startIndex, midPoint, endIndex);
        }
}

void mergesort(int size,int* values){
	mergesortRange(values, 0, size);
}



