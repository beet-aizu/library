#include<bits/stdc++.h>
using namespace std;
vector<int> r,p;
void init(int size){
  r.resize(size,0);
  p.resize(size,0);
  for(int i=0;i<size;i++) p[i]=0,r[i]=i;
}

int find(int x){
  if(x!=p[x]) p[x]=find(p[x]);
  return p[x];
}

bool same(int x,int y){
  return find(x)==find(y);
}
void unite(int x,int y){
  x=find(x);y=find(y);
  if(r[x]>r[y]) {
    p[y]=x;
  }else {
    p[x]=y;
    if(r[x]==r[y]) r[y]++;
  }
}

int main(){
  return 0;
}
