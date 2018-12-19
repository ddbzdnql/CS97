#include <stdio.h>
#include <stdlib.h>

int * key;

int measure(char * DNA, int length){
  int i, j, sum = 0;
  for (i = 0; i < length-1; i++){
    for (j = i + 1; j < length; j++){
      if (DNA[i] > DNA[j]){
        sum ++;
      }
    }
  }
  return sum;
}

void quicksort(int * toSort, int size){
  if (size <= 1){
    return;
  }
  if (size == 2){
    if (key[toSort[0]] > key[toSort[1]]){
      int temp = toSort[0];
      toSort[0] = toSort[1];
      toSort[1] = temp;
    }
    return;
  }
  
  int pivot = toSort[0], needle = 1, lsize = 0, rsize = 0;
  while(lsize + rsize < size-1){
    if (key[toSort[needle]] < key[pivot]){
      int temp = toSort[needle];
      toSort[needle] = toSort[lsize];
      toSort[lsize] = temp;
      lsize ++;
      needle ++;
   }
   else{
     int temp = toSort[needle];
     toSort[needle] = toSort[size-1-rsize];
     toSort[size-1-rsize] = temp;
     rsize ++;
   }
  }

  quicksort(toSort, lsize);
  quicksort(toSort + lsize + 1, rsize);
}

int main(){
  int length, size;
  scanf("%d %d", &length, &size);
  int i = 0;
  char ** arr = (char **)malloc(size * sizeof(char *));
  while(i < size){
    arr[i] = (char *)malloc(length * sizeof(char));
    scanf("%s", arr[i]);
    i++;
  }
  key = (int *)malloc(size * sizeof(int));
  for (i = 0; i < size; i++){
    key[i] = measure(arr[i], length);
    //printf("%d\n", key[i]);
  }

  int toSort[size];
  for (i = 0; i < size; i++){
    toSort[i] = i;
  }

  quicksort(toSort, size); 
 
  for (i = 0; i < size; i++){
    printf("%s\n", arr[toSort[i]]);
  }

  return 0;
}
