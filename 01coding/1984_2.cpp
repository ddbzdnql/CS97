#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>

struct query{
  int a;
  int b;
  int o1;
  int o2;
} arr[10000];

struct comp1{
  bool operator()(struct query q1, struct query q2){
    return q1.o1 < q1.o2;
  }
};

struct comp2{
  bool operator()(struct query q1, struct query q2){
    return q1.o2 < q1.o2;
  }
};

int main(){
  int n, m;
  scanf("%d %d", &n, &m);

  int A[40001][2];
  int B[40002][4][2];
  std::queue<int> q;
  int C[40002][2];

  int i = 0;
  while(i<m){
    int a, b, dis;
    char dir;
    scanf("%d %d %d %c", &a, &b, &dis, &dir);
    A[i][0] = a;
    A[i][1] = b;

    int ref;
    if (dir=='E'||dir=='W'){
      ref = dis * 2;
    }else{
      ref = dis * 2 + 1;
    }
    if (dir=='S'||dir=='W'){
      ref = -ref;
    }

    int j;
    for (j=0; j<4; j++){
      if (B[a][j][0] == 0){
        B[a][j][0] = b;
        B[a][j][1] = ref;
        break;
      }
    }
    for (j=0; j<4; j++){
      if (B[b][j][0] == 0){
        B[b][j][0] = a;
        B[b][j][1] = -ref;
        break;
      }
    }
    i++;
  }

  C[1][0] = 0; C[1][1] = 0;
  q.push(1);

  while(!q.empty()){
    int cur = q.front(); q.pop();
    int j;
    for (j=0; j<4; j++){
      int child = B[cur][j][0];
      if(child!=1  && child!=0 && C[child][0]==0 && C[child][1]==0){
        int raw = B[cur][j][1];
        int ref = abs(raw)/2*raw/abs(raw);
        C[child][0] = C[cur][0];
        C[child][1] = C[cur][1];
        if (raw%2 == 0){
          C[child][0] += ref;
        }else{
          C[child][1] += ref;
        }
        q.push(child);
      }
    }
  }

  int cases, j=0;
  scanf("%d", &cases);
  while(j<cases){
    int D[40002];
    int a, b, step, c;
    scanf("%d %d %d", &a, &b, &step);
    for(c=0; c<step; c++){
      int f = A[c][0], s = A[c][1];
      int fr = f, sr = s;
      while (D[fr] != 0){
        fr = D[fr];
      }
      while (D[sr] != 0){
        sr = D[sr];
      }
      if (fr != sr){
        D[sr] = fr;
      }
    }
    int sa = a, sb = b;
    while(D[sa] != 0){
      sa = D[sa];
    }
    while(D[sb] != 0){
      sb = D[sb];
    }
    if (sa == sb){
      printf("%d\n", abs(C[a][0]-C[b][0])+abs(C[a][1]-C[b][1]));
    }else{
      printf("-1\n");
    }

    j++;
  }

}

