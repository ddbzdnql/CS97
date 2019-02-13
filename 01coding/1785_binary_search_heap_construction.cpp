#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
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
  int l = 1, r = size-1, l_max = 0, r_max = 0;
  while(l <= r){
    if (strcmp(needle[l]->label, needle[0]->label) > 0){
      temp = needle[l];
      needle[l] = needle[r];
      needle[r] = temp;
      if (r_max == 0 || needle[r_max]->priority < needle[r]->priority){
        r_max = r;
      }
      r--;
    }
    else{
      if (l_max == 0 || needle[l_max]->priority < needle[l]->priority){
        l_max = l;
      }
      l++;
    }
  }

  

  printf("(");
  if (l-1 > 1){
    print_tree(needle+1, l_max-1, l-1);
  }
  else{
    if (l-1 != 0){
      printf("(%s/%d)", needle[1]->label, needle[1]->priority);
    }
  }
  printf("%s/%d", needle[0]->label, needle[0]->priority);
  if (size-l > 1){
    print_tree(needle+r+1, r_max-l, size-l);
  }
  else{
    if (size-l != 0){
      printf("(%s/%d)", needle[r+1]->label, needle[r+1]->priority);
    }
  }
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
    //random_shuffle(arr+1, arr+l+1);
    int max_p = 0;
    for (int i=1; i<=l; i++){
      if (max_p==0 || arr[max_p]->priority < arr[i]->priority){
        max_p = i;
      }
    }
    print_tree(arr+1, max_p-1, l);
    printf("\n");
     
    scanf("%d", &l);
  } 
}
