#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
  int length;
  scanf("%d", &length);

  int i = 0, arr[length];
  while(i < length){
    char * a = (char *)malloc(80 * sizeof(char)); 
    char * b = (char *)malloc(80 * sizeof(char));
    scanf("%s %s", a, b);
    int real_a = 0, real_b = 0, needle = 0, cur = 0;    
	for (needle = 0; a[needle]!='\0' ; needle++){
      
    }
    for (cur = 0; cur < needle; cur++){
      real_a += (a[cur]-'0') * (pow(10, cur));
    }
    for (needle = 0; b[needle]!='\0' ; needle++){
      
    }
    for (cur = 0; cur < needle; cur++){
      real_b += (b[cur]-'0') * (pow(10, cur));
    }
    free(a);
    free(b);
    arr[i] = real_a + real_b;
    i++;
  }

  for (i=0; i<length; i++){
    int cur = arr[i];
    int real = 0;
    while(cur != 0){
      int bit = cur % 10;
      real = real* 10 + bit;
      cur = cur/10;
    }
    printf("%d\n", real);
  }

  return 0;
}
