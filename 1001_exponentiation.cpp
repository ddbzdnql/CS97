#include <stdio.h>
#include <math.h>

class prec_num{
  int size;
  char * raw_digits;
  int exp;

  prec_num(char * raw, int length){
    exp = 0;
    raw_digits = (char *)malloc(length * sizeof(char));
    int i, cur;
    for (i=0; i<length; i++){
      if (raw[i] != '.'){
        raw_digits[size++] = raw[i];
      }
      else{
        exp = length - i - 1;
      }
    }
  }
}

int main(){
  int stat;
  char * num = (char *)malloc(6*sizeof(char));
  int exp = 0;
  while((stat=scanf("%s%d", num, &exp)) != EOF){
    prec_num cur(num, 6);
    
  }
}
