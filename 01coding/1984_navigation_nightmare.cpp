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
  int val;
} arr[10000];

struct comp1{
  bool operator()(struct query q1, struct query q2){
    return q1.o1 < q2.o1;
  }
} c1;

struct comp2{
  bool operator()(struct query q1, struct query q2){
    return q1.o2 < q2.o2;
  }
} c2;

int main(){
  int n, m;
  scanf("%d %d", &n, &m);

  int A[40001][2];
  int B[40002][4][2];
  std::queue<int> q;
  int C[40002][2];
  int D[40002];

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
    scanf("%d %d %d", &(arr[j].a), &(arr[j].b), &(arr[j].o1));
    arr[j].o2=j;
    j++;
  }

  std::sort(arr, arr+j, c1);

  for (j=1; j<=i; j++){
    D[j] = 0;
  }

  int needle=0;
  for(j=0; j<m; j++){
    int a=A[j][0], b=A[j][1];
    int as=a, bs=b;
    while(D[as]!=0){
      as = D[as];
    }
    while(D[bs]!=0){
      bs = D[bs];
    }
    if (as!=bs){
      D[bs] = as;
    }
    while (arr[needle].o1 == j+1){
      int c1 = arr[needle].a, c2 = arr[needle].b;
      int c1r = c1, c2r = c2;
      while(D[c1r]!=0){
        c1r=D[c1r];
      }
      while(D[c2r]!=0){
        c2r=D[c2r];
      }
      if (c1r==c2r){
        arr[needle].val = abs(C[c1][0]-C[c2][0])+abs(C[c1][1]-C[c2][1]);
      }else{
        arr[needle].val = -1;
      }
      needle++;
    }
  }

  std::sort(arr, arr+cases, c2);

  for (j=0; j<cases; j++){
    printf("%d\n", arr[j].val);
  }
}
