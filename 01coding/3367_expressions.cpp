#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>

class exp_tree{
  public:
    int type;
    char value;
    struct exp_tree * left;
    struct exp_tree * right;
    struct exp_tree * parent;

    exp_tree(char val){
      type = 1;
      value = val;
      left = NULL;
      right = NULL;
    }

    exp_tree(exp_tree * l, exp_tree * r, char val){
      type = 2;
      value = val;
      left = l;
      right = r;
      l->parent = this;
      r->parent = this;
    }
};

int main(){
  int cases;
  scanf("%d", &cases);
  getchar();
  while(cases > 0){
    std::stack<exp_tree *> s;
    int size = 0;
    char c;
    while((c=getchar()) != '\n'){
      if ('a' <= c && c <= 'z'){
        exp_tree * leaf = new exp_tree(c);
        s.push(leaf);
      }
      else{
        exp_tree * right = s.top();
        s.pop();
        exp_tree * left = s.top();
        s.pop();
        exp_tree * branch = new exp_tree(left, right, c);
        s.push(branch);
      }
      size++;
    }

    exp_tree * root = s.top();
    s.pop();
    char * toprint = (char *)calloc(size, sizeof(char));

    int i = 0;
    std::queue<exp_tree *> q;
    q.push(root);
    while(!q.empty()){
      exp_tree * cur = q.front();
      q.pop();
      toprint[size-1-i++] = cur->value;
      if (cur->type != 1){
        q.push(cur->left);
        q.push(cur->right);
      }
    }


    printf("%s\n", toprint);
    free(toprint);
    cases --;
  }
}
