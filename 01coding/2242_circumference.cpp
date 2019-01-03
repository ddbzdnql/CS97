#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793


int main(){
  float x1, y1, x2, y2, x3, y3;
  while(scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3) == 6){
    float x_mid1 = (x1+x2)/2;
    float y_mid1 = (y1+y2)/2;
    float x_mid2 = (x1+x3)/2;
    float y_mid2 = (y1+y3)/2;
    float x_c, y_c;
    int x=0, y=0;
    if (x1 == x2){
      y_c = y_mid1;
      y=1;
    }
    if (x1 == x3){
      y_c = y_mid2;
      y=1;
    }
    if (y1 == y2){
      x_c = x_mid1;
      x=1;
    }
    if (y1 == y3){
      x_c = x_mid2;
      x=1;
    }
    if (x||y){
      if (x){
        if (y){
          float diam = sqrt(pow((x_c-x1),2) + pow(y_c-y1,2));
          printf("%0.2f\n", diam * 2 * PI);
          continue;
        }
        if (y1==y2){
          y_c = (y_mid2*(y1-y3) - (x_c-x_mid2)*(x1-x3)) / (y1-y3);
        }else{
          y_c = (y_mid1*(y1-y2) - (x_c-x_mid1)*(x1-x2)) / (y1-y2);
        }
      }else{
        if (x1==x2){
          x_c = (x_mid2*(x1-x3) - (y_c-y_mid2)*(y1-y3)) / (x1-x3);
        }else{
          x_c = (x_mid1*(x1-x2) - (y_c-y_mid1)*(y1-y2)) / (x1-x2);
        }
      }
    }else{
      x_c = (x_mid1 + (y_mid1-y_mid2)*(y1-y2)/(x1-x2)  - (y1-y2)/(x1-x2)*(x1-x3)/(y1-y3)*x_mid2)/(1-(y1-y2)/(x1-x2)*(x1-x3)/(y1-y3));
      y_c = (y_mid2*(y1-y3) - (x_c-x_mid2)*(x1-x3)) / (y1-y3);
    }
    float diam = sqrt(pow((x_c-x1),2) + pow(y_c-y1,2));
    printf("%0.2f\n", diam * 2 * PI);

  }
}
