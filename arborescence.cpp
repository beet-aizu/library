#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE

template<typename T, typename E>
struct FGC{
  typedef function<T(T, E)> F;
  typedef function<E(E, E)> G;
  typedef function<bool(T,T)> C;
  F &f;
  G &g;
  C &c;
  FGC(F &f,G &g,C &c):f(f),g(g),c(c){}
};

template<typename T, typename E>
struct SkewHeap{
  SkewHeap *l,*r;
  T val;
  E add,e;
  FGC<T, E> &fgc;
  
  SkewHeap(T val,E e,FGC<T,E> &fgc):
    val(val),add(e),e(e),fgc(fgc){l=r=NULL;}
  
  void eval(){
    if(add==e) return;
    if(l) l->add=fgc.g(l->add,add);
    if(r) r->add=fgc.g(r->add,add);
    val=fgc.f(val,add);
    add=e;
  }
  
  T top(){
    return fgc.f(val,add);
  }
  
};

template<typename T, typename E>
SkewHeap<T, E>* meld(SkewHeap<T, E> *a,SkewHeap<T, E> *b){
  if(!a) return b;
  if(!b) return a;
  if(a->fgc.c(a->top(),b->top()))  swap(a,b);
  a->eval();
  a->r=meld(a->r,b);
  swap(a->l,a->r);
  return a;
}

template<typename T, typename E>
SkewHeap<T, E>* pop(SkewHeap<T, E>* a){
  a->eval();
  auto res=meld(a->l,a->r);
  free(a);
  return res;
};

//Without merge technique
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
    r[x]+=r[y];
    p[y]=x;
  }
};

struct Arborescence{
  using P = pair<int, int>;
  using Heap = SkewHeap<P, int>;
  
  struct edge{
    int from,to,cost;
    edge(){}
    edge(int from,int to,int cost):from(from),to(to),cost(cost){}
  };
  
  int n;
  UnionFind uf;
  vector<edge> edges;
  vector<Heap*> come;
  vector<int> used,from,cost;
  
  Arborescence(int n):n(n),uf(n),come(n,NULL),
		      used(n,0),from(n,-1),cost(n,-1){};

  void add_edge(int from,int to,int cost){
    edges.emplace_back(from,to,cost);
  }

  void input(int m,int offset=0){
    for(int i=0;i<m;i++){
      int u,v,c;
      cin>>u>>v>>c;
      add_edge(u+offset,v+offset,c);
    }
  }

  int build(int r){
    FGC<P, int>::F f=[](P a,int b){return P(a.first+b,a.second);};
    FGC<P, int>::G g=[](int a,int b){return a+b;};
    FGC<P, int>::C c=[](P a, P b){return a>b;};
    FGC<P, int> fgc(f,g,c);
  
    used[r]=2;
    for(int i=0;i<(int)edges.size();i++){
      edge &e=edges[i];
      come[e.to]=meld(come[e.to],new Heap(P(e.cost,i),0,fgc));
    }
    
    int res=0;
    for(int i=0;i<n;i++){
      if(used[i]) continue;
      int v=i;
      vector<int> l;
      while(used[v]!=2){
	used[v]=1;
	l.emplace_back(v);
	if(!come[v]) return -1;
	from[v]=uf.find(edges[come[v]->val.second].from);
	cost[v]=come[v]->top().first;
	come[v]=pop(come[v]);
	if(from[v]==v) continue;
	
	res+=cost[v];
	if(used[from[v]]==1){
	  int p=v;
	  do{
	    if(come[p]) come[p]->add-=cost[p];
	    if(p!=v){
	      uf.unite(v,p);
	      come[v]=meld(come[v],come[p]);
	    }
	    p=uf.find(from[p]);
	  }while(p!=v);
	}else{
	  v=from[v];
	}
      }
      for(int u:l) used[u]=2;
    }
    return res;
  }
  
};
//END CUT HERE
signed main(){
  int n,m,r;
  cin>>n>>m>>r;
  Arborescence G(n);
  G.input(m);
  cout<<G.build(r)<<endl;
  return 0;
}

/*
  verified on 2018/01/04
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B&lang=jp
*/
