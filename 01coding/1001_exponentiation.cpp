#include <stdio.h>
#include <math.h>
#include <stdlib.h>

class prec_num{
public:
  int size;
  char * raw_digits;
  int exp;

  prec_num(char * raw, int length){
    exp = 0;
    size = 0;
    raw_digits = (char *)malloc(length * sizeof(char));
    int i, cur,trail=0;
    for (i=length-1; i>=0; i--){
      if (raw[i] != '.'){
        if (raw[i] != '0'){
          trail = 1;
        }
        if (trail || raw[i] != '0'){
          raw_digits[size++] = raw[i];
        }
      }
      else{
        exp = size;
        trail = 1;
      }
    }
  }

  prec_num(char * digits, int length, int dot){
    size = length;
    exp = dot;
    raw_digits = digits;
  }
};

prec_num multiply(prec_num&, prec_num&);

int main(){
  int stat;
  char * num = (char *)malloc(6*sizeof(char));
  int exp = 0;
  while(scanf("%s%d", num, &exp) != EOF){
    prec_num cur(num, 6);
    prec_num result = cur;
    int times;
    for (times = 1; times < exp; times++){
      result = multiply(cur, result);
    }
    int i, index = 0, lead = 0;
    for (i = result.size-1; i >= 0; i--){  
      if (result.raw_digits[i] != '0'){
	    lead = 1;
      }
      if (index++ + result.exp == result.size){
        printf(".");
        lead = 1;
      }
      if (lead){
        printf("%c", result.raw_digits[i]);
      }
    }
    printf("\n");
  }

  return 0;
}

prec_num multiply(prec_num& mult1, prec_num& mult2){
  int * result_digits = (int *)malloc((mult1.size+mult2.size)*sizeof(int));
  int i, j, result_size = 0;
  for (i = 0; i < mult1.size+mult2.size; i++){
    result_digits[i] = 0;
  }
  int carry = 0;
  for (i = 0; i < mult1.size; i++){
    carry = 0;
    for (j = 0; j < mult2.size; j++){
      int bit1 = mult1.raw_digits[i] - '0';
      int bit2 = mult2.raw_digits[j] - '0';
      int partial = bit1 * bit2 + carry;
      result_digits[i+j] += partial;
      carry = result_digits[i+j] / 10;
      result_digits[i+j] = result_digits[i+j] % 10;
    } 
    result_digits[i+j] += carry;
  }
  if (carry == 0){
    result_size = mult1.size + mult2.size - 1;
  }
  else{
    result_size = mult1.size + mult2.size;
  }

  char * result_char = (char *)malloc(result_size * sizeof(char));
  for (i = 0; i < result_size; i++){
    result_char[i] = result_digits[i] + '0';
  }

  prec_num to_ret(result_char, result_size, mult1.exp+mult2.exp);
  return to_ret;
}
