#include <stdio.h>
#include <math.h>

int sumint(int);

int main(){
  int size, num;
  scanf("%d %d", &size, &num);
  while(size!=-1 || num!=-1){
   
    int s = 0, top = 0, suffix = 0;
    int co[size];
    for (int i=0; i<size; i++){
      co[i] = 0;
    }
    for (int i=0; i<size; i++){
      int upto = sumint(num);
      int val = num - upto*(upto-1)/2;
      if (num > (size-i-2)*(size-i-1)/2){
        int init = suffix+val+1;
        while(co[init-1]){init++;}
        co[init-1] = 1;
        printf("%d", init);
        
        num -= val;
      }else{
        printf("%d", ++suffix);
      }
      if (i!=size-1){
        printf(" ");
      }
    }

    printf("\n");

    scanf("%d %d", &size, &num);
  }
}

int sumint(int s){
  int toRet = (int)(sqrt(s*2));
  while(toRet*(toRet+1) < s*2){
    toRet ++;
  }
  return toRet;
}
