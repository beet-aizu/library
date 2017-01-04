#include<bits/stdc++.h>
using namespace std;
struct UnionFind{
  vector<int> r,p;
  UnionFind(){}
  UnionFind(int size){init(size);}
  void init(int size){
    r.resize(size,0);
    p.resize(size,0);
    for(int i=0;i<size;i++) r[i]=1,p[i]=i;
  }
  int find(int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
  }
};
struct edge{
  int from,to,cost;
  edge(){}
  edge(int from,int to,int cost):from(from),to(to),cost(cost){}
  bool operator<(const edge& e) const{
    return cost<e.cost;
  }
};
int kruskal(int N,vector<edge> edges){
  int res=0;
  sort(edges.begin(),edges.end());
  UnionFind uf(N+1);
  for(int i=0;i<(int)edges.size();i++){
    edge e=edges[i];
    if(!uf.same(e.from,e.to)){
      res+=e.cost;
      uf.unite(e.from,e.to);
    }
  }
  return res;
}
int main(){
  
  return 0;
}
