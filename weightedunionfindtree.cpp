#include<bits/stdc++.h>
using namespace std;
struct WeightedUnionFind{
  vector<int> r,p,ws;
  WeightedUnionFind(){}
  WeightedUnionFind(int size){init(size);}
  void init(int size){
    r.resize(size,0);
    p.resize(size,0);
    ws.resize(size,0);
    for(int i=0;i<size;i++) r[i]=1,p[i]=i;
  }
  int find(int x){
    if(x==p[x]){
      return x;
    }else{
      int t=find(p[x]);
      ws[x]+=ws[p[x]];
      return p[x]=t;
    }
  }
  int weight(int x){
    find(x);
    return ws[x];
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y,int w){
    w+=weight(x);
    w-=weight(y);
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y),w=-w;
    r[x]+=r[y];
    p[y]=x;
    ws[y]=w;
  }
  int diff(int x,int y){
    return weight(x)-weight(y);
  }
};
int main(){
  return 0;
}
