#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string.h>

struct compclass{
  bool operator() (const char* first, const char* second) const {
    int i;
    for (i=0; i<30; i++){
      if (first[i] < second[i]){
        return true;
      }
      if (first[i] > second[i]){
        return false;
      }
    }
    return false;
  }
};


int main(){
  char * name = (char *)malloc(sizeof(char) * 30);

  std::map<char *, int, compclass> vote;
  size_t size = 30;
  float sum = 0.0;

  while(fgets(name, 30, stdin) != NULL){
    char * cur = (char *)malloc(sizeof(char)*30);
    strcpy(cur, name);
    int i;
    for (i=0; i<30; i++){
      if (cur[i] == '\n'){
        cur[i] = 0;
      }
    }
    vote[cur] ++;
    sum++;
  }

  std::map<char *, int, compclass>::iterator i;
  for (i = vote.begin(); i != vote.end(); i++){
    printf("%s %.4f\n", i->first, 100*i->second/sum);
  }

  return 0;
}
