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
  T INF;
  E e;
  SkewHeap(F f,G g,C c,T INF,E e):f(f),g(g),c(c),INF(INF),e(e){}
  
  struct Node{
    Node *l,*r;
    T val;
    E add;
    Node(T val,E add):val(val),add(add){l=r=nullptr;}
  };

  void eval(Node *a){
    if(a==nullptr) return;
    if(a->add==e) return;
    if(a->l) a->l->add=g(a->l->add,a->add);
    if(a->r) a->r->add=g(a->r->add,a->add);
    a->val=f(a->val,a->add);
    a->add=e;
  }
  
  T top(Node *a){
    return a!=nullptr?f(a->val,a->add):INF;
  }

  T snd(Node *a){
    eval(a);
    return a!=nullptr?min(top(a->l),top(a->r)):INF;
  }

  Node* add(Node *a,E d){
    if(a!=nullptr) a->add=g(a->add,d);
    return a;
  }
  
  Node* push(T v){
    return new Node(v,e);
  }
  
  Node* meld(Node *a,Node *b){
    if(a==nullptr) return b;
    if(b==nullptr) return a;
    if(c(top(a),top(b))) swap(a,b);
    eval(a);
    a->r=meld(a->r,b);
    swap(a->l,a->r);
    return a;
  }
  
  Node* pop(Node* a){
    eval(a);
    auto res=meld(a->l,a->r);
    delete a;
    return res;
  }
  
};

//INSERT ABOVE HERE
template<typename T>
struct Arborescence{
  using P = pair<T, int>;
  using Heap = SkewHeap<P, int>;
  
  struct edge{
    int from,to;
    T cost;
    edge(){}
    edge(int from,int to,T cost):from(from),to(to),cost(cost){}
  };
  
  int n;
  P INF;
  UnionFind uf;
  vector<edge> edges;
  vector<typename Heap::Node*> come;
  vector<int> used,from;
  vector<T> cost;
  
  Arborescence(int n,T INF):n(n),INF(INF,-1),uf(n),come(n,NULL),
			    used(n,0),from(n,-1),cost(n,-1){};

  void add_edge(int from,int to,int cost){
    edges.emplace_back(from,to,cost);
  }

  void input(int m,int offset=0){
    for(int i=0;i<m;i++){
      int u,v;
      T c;
      cin>>u>>v>>c;
      add_edge(u+offset,v+offset,c);
    }
  }

  T build(int r){
    typename Heap::F f=[](P a,int b){return P(a.first+b,a.second);};
    typename Heap::G g=[](int a,int b){return a+b;};
    typename Heap::C c=[](P a, P b){return a>b;};
    Heap heap(f,g,c,INF,0);
  
    used[r]=2;
    for(int i=0;i<(int)edges.size();i++){
      edge &e=edges[i];
      come[e.to]=heap.meld(come[e.to],heap.push(P(e.cost,i)));
    }
    
    T res=0;
    for(int i=0;i<n;i++){
      if(used[i]) continue;
      int v=i;
      vector<int> l;
      while(used[v]!=2){
	used[v]=1;
	l.emplace_back(v);
	if(!come[v]) return T(-1);
	from[v]=uf.find(edges[come[v]->val.second].from);
	cost[v]=heap.top(come[v]).first;
	come[v]=heap.pop(come[v]);
	if(from[v]==v) continue;
	
	res+=cost[v];
	if(used[from[v]]==1){
	  int p=v;
	  do{
	    if(come[p]!=nullptr) heap.add(come[p],-cost[p]);
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
  const int INF = 1e8;
  Arborescence<int> G(n,INF);
  G.input(m);
  cout<<G.build(r)<<endl;
  return 0;
}

/*
  verified on 2018/02/16
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B&lang=jp
*/
