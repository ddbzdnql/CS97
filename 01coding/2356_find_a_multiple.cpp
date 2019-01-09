#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
  int size, i=0, sum=0;
  scanf("%d", &size);
  int * arr = (int *)malloc(sizeof(int) * size);
  int * storage = (int *)malloc(sizeof(int) * size);
  for (i = 0; i < size; i++){
    arr[i] = -1;
  }
  i=0;
  while(i<size){
    int cur;
    scanf("%d", &cur);
    sum += cur;
    storage[i] = cur;
    int bucket = sum % size;
    if (bucket == 0){
      printf("%d\n", i+1);
      int j;
      for (j=0; j<=i; j++){
        printf("%d\n", storage[j]);
      }
      return 0;
    }
    if (arr[bucket] == -1){
      arr[bucket] = i;
    }
    else{
      int start = arr[bucket];
      int end = i;
      printf("%d\n", end-start);
      int j;
      for (j=start+1; j<=end; j++){
        printf("%d\n", storage[j]);
      }
      return 0;
    }
    i++;
  }

}
