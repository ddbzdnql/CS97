#include <stdio.h>
#include <math.h>
#include <cstdlib>

int main(){
  int length = 0;
  scanf("%d", &length);

  int cur = 0;
  while(cur < length){
    int size = 0;
    scanf("%d", &size);
    int i, j, k;
    printf("Scenario #%d:\n", cur+1);
    for (i=0; i<size*2+1; i++){
      printf("slice #%d:\n", i+1);
      for (j=0; j<size*2+1; j++){
        for (k=0; k<size*2+1; k++){
          int total = abs(i-size) + abs(j-size) + abs(k-size);
          if (total > size){
            printf(".");
          }else{
            printf("%d", total);
          }
        }
        printf("\n");
      }
    }    
    printf("\n");

    cur++;
  }
}
