#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE


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

template<typename T, typename E>
struct SkewHeap{
  typedef function<T(T, E)> F;
  typedef function<E(E, E)> G;
  typedef function<bool(T,T)> C;
  F f;
  G g;
  C c;
  E e;
  SkewHeap(F f,G g,C c,E e):f(f),g(g),c(c),e(e){}

  struct Node{
    Node *l,*r;
    T val;
    E add;
    Node(T val,E add):val(val),add(add){l=r=NULL;}
  };

  void eval(Node *a){
    if(a->add==e) return;
    if(a->l) a->l->add=g(a->l->add,a->add);
    if(a->r) a->r->add=g(a->r->add,a->add);
    a->val=f(a->val,a->add);
    a->add=e;
  }
  
  T top(Node *a){
    return f(a->val,a->add);
  }
  
  Node* push(T v){
    return new Node(v,e);
  }
  
  Node* meld(Node *a,Node *b){
    if(!a) return b;
    if(!b) return a;
    if(c(top(a),top(b))) swap(a,b);
    eval(a);
    a->r=meld(a->r,b);
    swap(a->l,a->r);
    return a;
  }
  
  Node* pop(Node* a){
    eval(a);
    auto res=meld(a->l,a->r);
    free(a);
    return res;
  }
  
};

//INSERT ABOVE HERE
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
  vector<Heap::Node*> come;
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
    Heap::F f=[](P a,int b){return P(a.first+b,a.second);};
    Heap::G g=[](int a,int b){return a+b;};
    Heap::C c=[](P a, P b){return a>b;};
    Heap heap(f,g,c,0);
  
    used[r]=2;
    for(int i=0;i<(int)edges.size();i++){
      edge &e=edges[i];
      come[e.to]=heap.meld(come[e.to],heap.push(P(e.cost,i)));
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
	cost[v]=heap.top(come[v]).first;
	come[v]=heap.pop(come[v]);
	if(from[v]==v) continue;
	
	res+=cost[v];
	if(used[from[v]]==1){
	  int p=v;
	  do{
	    if(come[p]) come[p]->add-=cost[p];
	    if(p!=v){
	      uf.unite(v,p);
	      come[v]=heap.meld(come[v],come[p]);
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
  verified on 2018/02/08
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B&lang=jp
*/
