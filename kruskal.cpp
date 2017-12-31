#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct Kruskal{

  struct UnionFind{
    int n;
    vector<int> r,p;
    UnionFind(){}
    UnionFind(int sz):n(sz),r(sz,1),p(sz,0){iota(p.begin(),p.end(),0);}
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

  int n;
  vector<edge> edges;

  Kruskal(){}
  Kruskal(int sz):n(sz){}
  
  void add_edge(int u,int v,int c){
    edges.push_back(edge(u,v,c));
  }

  void input(int m,int offset=0){
    int a,b,c;
    for(int i=0;i<m;i++){
      cin>>a>>b>>c;
      add_edge(a+offset,b+offset,c);
    }
  }
  
  int build(){
    sort(edges.begin(),edges.end());
    UnionFind uf(n+1);
    int res=0;
    for(int i=0;i<(int)edges.size();i++){
      edge e=edges[i];
      if(!uf.same(e.from,e.to)){
	res+=e.cost;
	uf.unite(e.from,e.to);
      }
    }
    return res;
  }
};
//END CUT HERE
int main(){
  int V,E;
  cin>>V>>E;
  Kruskal kruskal(V);
  kruskal.input(E);
  cout<<kruskal.build()<<endl;
  return 0;
}

/*
  verified on 2017/10/29
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
*/
