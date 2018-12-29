#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Vertex{
  public:
    int x;
    int y;

    Vertex(int h, int v){
      x=h;
      y=v;
    }

    bool operator==(const Vertex& l)const{
      return l.x==x && l.y==y;
    }
};

struct vhash{
  size_t operator()(const Vertex& v)const{
    return hash<int>()(v.x) ^ (((hash<int>()(v.y)<<1)>>1));
  }
};

class edge{
  public:
    Vertex* first;
    Vertex* second;

    double measure()const{
      return sqrt(pow((first->x-second->x), 2)+pow((first->y-second->y), 2));
    }

    edge(Vertex * f, Vertex * s){
      first = f;
      second = s;
    } 
};

bool comp (edge& l, edge& r){
  return l.measure() > r.measure();
}

int main(){
  unordered_map<Vertex, vector<edge>, vhash> u;
  int i, j, size; 
  scanf("%d", &size);
  int * grid = (int *)malloc(sizeof(int)*size*size);
  for (i=0; i < size; i++){
    char * row = (char *)malloc(size*sizeof(char));
    scanf("%s", row);
    for (j=0; j<size; j++){
      if (row[j]=='J'){
        vector<edge> val;
        Vertex temp(i,j);
        u.insert(make_pair(temp, val));
      }
      if (row[j]=='B'){
        grid[i*size+j] = 0;
      }
    }
  }
  
  for (auto ptr=u.begin(); ptr!=u.end(); ptr++){
     for (auto asso=next(ptr, 1); asso!=u.end(); asso++){
       Vertex v1 = ptr->first;
       Vertex v2 = asso->first;
       edge e(&v1, &v2);
       printf("<%d,%d>,<%d,%d>\n", e.first->x, e.first->y, e.second->x, e.second->y);
       ptr->second.push_back(edge(&v1, &v2));
       asso->second.push_back(edge(&v1, &v2));
  for (auto ptr=u.cbegin(); ptr!=u.cend(); ptr++){
    auto vec = ptr->second;
    printf("(%d,%d):\n", ptr->first.x, ptr->first.y);
    //sort(vec->begin(), vec->end(), comp);
    for (auto v_ptr=vec.cbegin(); v_ptr!=vec.cend(); v_ptr++){
      printf("<%d,%d>, <%d,%d>: %f\n", v_ptr->first->x, v_ptr->first->y, v_ptr->second->x, v_ptr->second->y, (float)(v_ptr->measure()));
    } 
  } 
     }
  }



  return 0;
}
