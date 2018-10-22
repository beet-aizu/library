#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T>
struct Kruskal{
  
  struct edge{
    int from,to;
    T cost;
    int used;
    edge(){}
    edge(int from,int to,T cost):
      from(from),to(to),cost(cost),used(0){}
    bool operator<(const edge& e) const{
      return cost<e.cost;
    }
  };

  int n;
  vector<int> p,r;
  vector<edge> edges;

  Kruskal(){}
  Kruskal(int n):n(n){}

  void init(int n){
    r.assign(n,1);
    p.resize(n);
    iota(p.begin(),p.end(),0);
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

  void add_edge(int u,int v,T c){
    edges.emplace_back(u,v,c);
  }
  
  T build(){
    sort(edges.begin(),edges.end());
    init(n);
    T res=0;
    for(auto &e:edges){
      if(!same(e.from,e.to)){
        res+=e.cost;
        unite(e.from,e.to);
        e.used=1;
      }
    }
    return res;
  }
};
//END CUT HERE
int main(){
  int V,E;
  scanf("%d %d",&V,&E);
  Kruskal<int> ksk(V);
  for(int i=0;i<E;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    ksk.add_edge(a,b,c);
  }
  printf("%d\n",ksk.build());
  return 0;
}

/*
  verified on 2018/10/22
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
*/
