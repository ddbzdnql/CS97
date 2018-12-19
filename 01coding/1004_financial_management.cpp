#include <stdio.h>
#define MONTH 12

int main(){
  int i;
  double sum;
  for (i = 0; i < MONTH; i++){
    double cur;
    scanf("%lf", &cur);
    sum += cur;
  }
  float avg = sum / MONTH;
  int avg_1 = avg * 1000;
  int prev_bit = avg_1 % 10;
  if (prev_bit >= 5){
    avg += 0.01;
  }
  printf("$%.2f\n", avg);

  return 0;
}
