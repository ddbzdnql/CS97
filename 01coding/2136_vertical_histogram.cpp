#include <stdio.h>
#include <stdlib.h>

int main(){
  char ** arr = (char **)malloc(4 * sizeof(char *));
  int i;
  for (i = 0; i < 4; i++){
    arr[i] = (char *)malloc(72 * sizeof(char));
    size_t size = 72;
    getline(arr+i, &size, stdin);
  }
  
  int bucket[26];
  for (i = 0; i < 26; i++){
    bucket[i] = 0;
  }

  int max = 0;
  for (i = 0; i < 4; i++){
    int j = 0;
    while(arr[i][j] != '\0'){
      int difference = arr[i][j] - 'A';
      if (difference >= 0 && difference < 26){
        bucket[difference] ++;
        if (bucket[difference] > max){
          max = bucket[difference];
        }
      }
      j++;
    }
  }

  for (i = 0; i < max; i++){
    int j = 0;
    for (j = 0; j < 26; j++){
      if (j != 0){
        printf(" ");
      }
      if (i + bucket[j]  >= max){
        printf("*");
      }
      else{
        printf(" ");
      }
    }
    printf("\n");
  }

  for (i = 0; i < 26; i++){
    if (i != 0){
      printf(" ");
    }
    printf("%c", ('A'+i));
  }
  printf("\n");
}
