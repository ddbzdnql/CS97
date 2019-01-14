#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>

int main(){
  int cases;
  scanf("%d", &cases);
  while(cases--){
    int size;
    scanf("%d", &size);
    int * tree = (int *)malloc(sizeof(int) * (size+1));
    int i = 0;
    for (;i < size+1; i++){
      tree[i] = -1;
    }

    i = 0;
    while(i++ < size-1){
      int p, c;
      scanf("%d %d", &p, &c);
      tree[c] = p; 
    }

    int a, b;
    scanf("%d %d", &a, &b);
    std::vector<int> va, vb;
    int cur = a;
    do{
      va.push_back(cur);
      cur = tree[cur];
    }while(cur != -1);

    cur = b;
    do{
      vb.push_back(cur);
      cur = tree[cur];
    }while(cur != -1); 

    int sa = va.size()-1, sb = vb.size()-1, prev = va[sa];
    while(va[sa] == vb[sb]){
      if (sa < 0 || sb < 0 || va[sa] != vb[sb]){
        break;
      }
      prev = va[sa];
      sa --;
      sb --;
    }
    printf("%d\n", prev);
  }
}
