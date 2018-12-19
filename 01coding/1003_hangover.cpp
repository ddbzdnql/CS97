#include <stdio.h>

int main(){
  int status;
  double num;
  while((status = scanf("%lf", &num)) >= 0 && num >= 0.01 && num <= 5.20){
    double i = 0, sum = 0;
    while(sum < num){
      sum += 1.0/(i+2);
      i++;
    }
    int output = i;
    printf("%d card(s)\n", output);
  }
  return 0;
}
