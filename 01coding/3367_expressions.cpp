#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>

struct node{
  int type;
  char c;
  int l;
  int r;
} arr[10001];

int main(){
  int cases;
  scanf("%d", &cases);
  getchar();

  while(cases >0){
    char cur = getchar();
    int i = 0;
    std::stack<int> s;
    while(cur != '\n'){
      if (cur>='a' && cur<='z'){
        i++;
        arr[i].type=1;
        arr[i].c = cur;
        s.push(i);
      }
      else{
        if (cur >= 'A' && cur <= 'Z'){
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();
        i++;
        arr[i].type=2;
        arr[i].c = cur;
        arr[i].l = left;
        arr[i].r = right;
        s.push(i);
       }
      }
      cur = getchar();
    }

    if (s.size() == 1){
    char * toprint = (char *)calloc(i, sizeof(char));
    int root = s.top();
    s.pop();
    
    std::queue<int> q;
    q.push(root);
 
    int j=0;
    while(!q.empty()){
      int cur_i = q.front();
      q.pop();
      toprint[i-1-j++] = arr[cur_i].c;
      if (arr[cur_i].type == 2){
        q.push(arr[cur_i].l);
        q.push(arr[cur_i].r);
      }
    }

    printf("%s\n", toprint);
    }
    else{
      printf("\n");
    }
    cases --;
  }

  return 0;
}
