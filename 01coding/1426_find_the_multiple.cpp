#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define DI 100

int main(){
  int num;
  scanf("%d", &num);
  while(num != 0){
    int rem[DI], prev = 1, i, j;
    int table[DI][num];
    rem[0] = 1;
    for (i=1; i<DI; i++){
      int r = (prev*10) % num;
      rem[i] = r;
      prev = r;

      table[i][r] = 1;
    }

    for (i=0; i<DI; i++){
      for (j=0; j<num; j++){
        if (j!=rem[i]){
          table[i][j] = 0;
        }
        else{
          table[i][j] = 1;
        }
      }
    }


    for (i=1; i<DI; i++){
      for (j=0; j<num; j++){
        if (table[i][j] == 0){
          if (table[i-1][(j+num-rem[i])%num] != 0){
            table[i][j] = 1;
          }
          else{
            if (table[i-1][j] != 0){
              table[i][j] = 2;
            }
          }

        }
      }
    }


  for (i=0; i<DI; i++){
      if (table[i][0] != 0){
        printf("1");
        int left = (num - rem[i]) % num;
        int needle = i-1;
        while(needle >= 0){
          if (table[needle][left] == 1 && left != 0){
            left = (left+num-rem[needle]) % num;
            printf("1");
          }
          else{
            printf("0");
          }
          needle --;
        }
        printf("\n");
        break;
      }
    }
    scanf("%d", &num);
  }
}
