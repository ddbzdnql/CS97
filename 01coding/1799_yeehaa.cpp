#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

int main(){
  int size, i=0;
  scanf("%d", &size);
  for (i=0; i<size; i++){
    float ra;
    int num;
    scanf("%f %d", &ra, &num);
    printf("Scenario #%d:\n", i+1);
    if (num == 2){
      printf("%0.3f\n\n", ra/2);
      continue;
    }
    float angle = 180/((float)num);
    float diag = 1/sin(angle * PI/180.0);
    float in_ra = ra/(1+diag);
    printf("%0.3f\n\n", in_ra);
  }
}
