#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <iostream>

struct node{
  int p;
  std::string l;
} arr[50001];

int main(){
  int size;
  scanf("%d ", &size);
  while(size != 0){
    char c;
    int i = 0;
    while(i < size){
      std::string temp;
      while((c=getchar()) != '/'){
        temp += c;
      }
      arr[i+1].l = temp;

      int cur;
      scanf("%d ", &cur);
      arr[i+1].p = cur;

      i++;
    }
    int j;
    for (j=1; j<=i; j++){
      std::cout << arr[j].l << "/" << arr[j].p << std::endl;
    }
    scanf("%d ", &size);
  }
}

use the quick sort spirit:
every iteration find the largest pr and split by larger and smaller than its label.
then for the left and right parts do the same thing until the left and right parts have length smaller than 3
