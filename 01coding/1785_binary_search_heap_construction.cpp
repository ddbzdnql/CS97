#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

class node{
  public:
    int priority;
    char * label;
    int left;
    int right;
} * arr[50001];

void print_tree(node ** needle, int max_p, int size){
  node * temp = needle[max_p];
  needle[max_p] = needle[0];
  needle[0] = temp;

  int l = 1, r = size-1;
  while(l <= r){
    if (strcmp(needle[l]->)){

    }
  }

  printf("(");
  printf("%s/%d", needle[0]->label, needle[0]->label);
  printf(")");
}

int main(){
  int l;
  unsigned seed = 1221;
  scanf("%d", &l);
  char delim[] = "/";
  while(l != 0){
    int i = 0;
    while(i < l){
      i++;
      char str[17];
      scanf("%s", str);
      char * ptr = strtok(str, delim);
      char * la = (char *)calloc(8, sizeof(char));
      strcpy(la, str);
      ptr = strtok(NULL, ptr);
      int p = atoi(ptr);
      if (arr[i] == NULL){
        arr[i] = (node *)malloc(sizeof(node));
      }
      arr[i]->priority = p;
      arr[i]->label = la;
      arr[i]->left = 0;
      arr[i]->right = 0;
    }
    random_shuffle(arr+1, arr+l+1);
    int max_p = 0;
    for (int i=1; i<=l; i++){
      if (max_p==0 || arr[max_p]->priority < arr[i]->priority){
        max_p = i;
      }
      printf("%s %d\n", arr[i]->label, arr[i]->priority);
    }
    //print_tree(arr+1, max_p, size);
     
    scanf("%d", &l);
  } 
}
