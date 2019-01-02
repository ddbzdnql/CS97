#include <stdio.h>
#include <math.h>

int is_prime(int);

int main(){
  int num;
  while(scanf("%d", &num) && num != 0){
    int i;
    for (i=1; i<=num/2; i+=2){
      int first = i;
      int second = num-i;
      if (is_prime(first) && is_prime(second)){
        printf("%d = %d + %d\n", num, first, second);
        break;
      }
    }
  }
}

int is_prime(int num){
  if (num <= 2){
    return 0;
  }
  for (int i = 2; i*i <= num; i++){
    if (num % i == 0 && i != num){
      return 0;
    }
  }
  return 1;
}
