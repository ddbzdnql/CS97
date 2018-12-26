#include <stdio.h>
#include <math.h>

int main(){
  int sum;
  scanf("%d", &sum);

  int ways = 0, i, limit; 
  limit = (int)sqrt(sum*2);
  for (i=1; i<=limit; i++){
    double rep = sum/(double)i;
    if (i % 2 != 0){
      if (rep == (int)rep){
        ways ++;
      }
    }else{
      if ( rep*2 == (int)(rep*2) && rep != (int)rep ){
        ways ++;
      }
    }
    if (rep <= i/2.0){
      ways --;
    }
  }

  printf("%d\n", ways);
}
