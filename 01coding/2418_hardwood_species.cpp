#include <stdio.h>
#include <map>

struct compclass{
  bool operator() (const char* first, const char* second) const {
    for (int i=0; i<30; i++){
      if (first[i] < second[i]){
        return true;
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
    char * cur = (char *)malloc(sizeof(char *)*30);
    strcpy(cur, name);
    for (int i=0; i<30; i++){
      if (cur[i] == '\n'){
        cur[i] = 0;
      }
    }
    vote[cur] = vote[cur]+1;
    sum++;
  }

  for (auto i = vote.begin(); i != vote.end(); i++){
    printf("%s %.4f\n", i->first, i->second/sum);
  }

  return 0;
}
