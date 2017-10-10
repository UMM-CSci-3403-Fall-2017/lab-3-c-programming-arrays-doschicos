#include "array_merge.h"
#include <stdlib.h>
#include "../mergesort/mergesort.c"
#include <stdio.h>

int* array_merge(int num_arrays, int* sizes, int** values) {
  
  //Check to see if there are arrays in values
  //If not then just return an empty array
   if(num_arrays == 0) {
    int* toReturn = (int*) calloc(2, sizeof(int));
    toReturn[0] = 0;
    return toReturn;
   }

  //Add up sizes array to see how many elements
  //there are that we need to add into a separate array
  int numberOfElements = 0;
  for(int i = 0; i < num_arrays; i++) {
    numberOfElements += sizes[i];
  }

  
  //Now we put all of the elements into a new array
  int* allElements = (int*) calloc(numberOfElements + 1, sizeof(int));
  int spotInArray = 0;
  for(int i = 0; i < num_arrays; i++) {
    for(int j = 0; j < sizes[i]; j++) {
      allElements[spotInArray] = values[i][j];
      spotInArray++;
    }
  }

  //Sort with our mergesort
  mergesort(spotInArray, allElements);
  
  

  //Now we need to count up the unique values in
  //our sorted array. We start at 1 as the first
  //value in the array will always be unique
  int uniquesCount = 1;
  for(int i = 1; i < spotInArray; i++) {
    
    //To find out if an element is unique we check
    //if the element prior to the current element
    //is equal, and if it is then we know that the current
    //element is not unique, if not then we increment our
    //uniques counter
    if(allElements[i] != allElements[i-1]) {
      uniquesCount++;
    }
  }

  //For tomorrow: create our array to return, add uniquesCount
  //at start, check for uniques again however add it to our return
  //array, free(allElements)

  //Created our array in which we will return when we have it filled
  int* toReturn = (int*) calloc(uniquesCount + 1, sizeof(int));

  //Add the count at the start and the first unique right after
  toReturn[0] = uniquesCount;
  toReturn[1] = allElements[0];

  //Adds all the unique elements to our array toReturn
  int spotIntoReturn = 2;
  for(int i = 1; i < spotInArray; i++) {
    if(allElements[i] != allElements[i-1]) {
      toReturn[spotIntoReturn] = allElements[i];
      spotIntoReturn++;
    }
  }
  //free our unused arrays
  free(allElements);
  return toReturn;
}
