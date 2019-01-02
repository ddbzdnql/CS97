#include <stdio.h>
#include <math.h>

int main(){
  int size, i;
  scanf("%d", &size);
  for(i=0; i<size; i++){
    int num, zeros = 0;
    scanf("%d", &num);
    int base2 = (int)log2(num);
    int base5 = 0, init = 5;
    while(init <= num){
      base5++;
      init = init*5;
    }
    int j, two = 0, five = 0;
    for (j=1; j<=base2; j++){
      int div = pow(2, j);
      two += num/div;
    }
    for (j=1; j<=base5; j++){
      int div = pow(5,j);
      five += num/div;
    }

    if (two < five){
      printf("%d\n", two);
    }
    else{
      printf("%d\n", five);
    }
  }
}
