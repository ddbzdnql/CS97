#include <stdio.h>
#include <math.h>
#include <stdlib.h>

class rider{
  public:
    int speed;
    int time;

    rider(int s, int t){
      speed = s;
      time = t;
    }
};

int estimate(rider&);

int main(){
  int size;
  scanf("%d", &size);
  while(size != 0){
    int i, min = 100000;
    rider * rds = (rider *)malloc(size*sizeof(rider));
    for (i = 0; i < size; i++){
      int s, t;
      scanf("%d\t%d", &s, &t);
      rds[i] = rider(s, t);
      if (estimate(rds[i]) < min){
        min = estimate(rds[i]);
      }
    }
    printf("%d\n", min);
    scanf("%d", &size);
  }
  return 0;
}

int estimate(rider& rd){
  if (rd.time < 0){
    return 100000;
  }
  double raw = rd.time + 4.5/((double)rd.speed)*3600.0;
  double toRet = ceil(raw);
  return (int)toRet;
}
