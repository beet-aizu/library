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
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  using C = function<bool(T,T)>;
  G g;
  H h;
  C c;
  T INF;
  E ei;
  SkewHeap(G g,H h,C c,T INF,E ei):g(g),h(h),c(c),INF(INF),ei(ei){}
  
  struct Node{
    Node *l,*r;
    T val;
    E add;
    Node(T val,E add):val(val),add(add){l=r=nullptr;}
  };

  void eval(Node *a){
    if(a==nullptr) return;
    if(a->add==ei) return;
    if(a->l) a->l->add=h(a->l->add,a->add);
    if(a->r) a->r->add=h(a->r->add,a->add);
    a->val=g(a->val,a->add);
    a->add=ei;
  }
  
  T top(Node *a){
    return a!=nullptr?g(a->val,a->add):INF;
  }

  T snd(Node *a){
    eval(a);
    return a!=nullptr?min(top(a->l),top(a->r)):INF;
  }

  Node* add(Node *a,E d){
    if(a!=nullptr) a->add=h(a->add,d);
    return a;
  }
  
  Node* push(T v){
    return new Node(v,ei);
  }
  
  Node* meld(Node *a,Node *b){
    if(!a||!b) return a?a:b;
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
  typedef pair<T, int> P;
  using Heap = SkewHeap<P, T>;
  
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

  void add_edge(int from,int to,T cost){
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
    typename Heap::G g=[](P a,T b){return P(a.first+b,a.second);};
    typename Heap::H h=[](T a,T b){return a+b;};
    typename Heap::C c=[](P a,P b){return a>b;};
    Heap heap(g,h,c,INF,0);
  
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
struct AOJ_GRL_2B{
  signed solve(){
    int n,m,r;
    cin>>n>>m>>r;
    const int INF = 1e8;
    Arborescence<int> G(n,INF);
    G.input(m);
    cout<<G.build(r)<<endl;
    return 0;
  }
};

/*
  verified on 2018/03/04
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B&lang=jp
*/

struct UVA11183{
  signed solve(){
    Int T;
    cin>>T;
    for(Int t=1;t<=T;t++){
      Int n,m;
      cin>>n>>m;
      const Int INF = 1e15;
      Arborescence<Int> G(n,INF);
      G.input(m);
      Int ans=G.build(0);
      cout<<"Case #"<<t<<": "; 
      if(ans<0) cout<<"Possums!"<<endl;
      else cout<<ans<<endl;
    }
    return 0;
  }
};


/*
  verified on 2018/03/04
  https://vjudge.net/problem/UVA-11183
*/

double v[111][111];
double c[111][111];
signed AOJ_2309(){
  Int n,m;
  cin>>n>>m;
  for(Int i=0;i<m;i++)
    for(Int j=0;j<n;j++)
      cin>>v[i][j];
 
  for(Int i=0;i<m;i++){
    c[i][i]=0;
    for(Int j=0;j<n;j++) c[i][i]+=v[i][j]*v[i][j];
  }
  for(Int i=0;i<m;i++){
    for(Int j=0;j<m;j++){
      if(i==j) continue;
      if(c[j][j]==0){
        c[i][j]=c[i][i];
        continue;
      }
      double r=0;
      for(Int k=0;k<n;k++)
        r+=v[i][k]*v[j][k];
      r/=c[j][j];
      c[i][j]=0;
      for(Int k=0;k<n;k++)
        c[i][j]+=(v[i][k]-r*v[j][k])*(v[i][k]-r*v[j][k]);      
    }    
  }
  const double INF = 1e12;
  Arborescence<double> G(m+1,INF);
  for(Int i=0;i<m;i++){
    G.add_edge(m,i,c[i][i]);
    for(Int j=0;j<m;j++){
      //cout<<i<<" "<<j<<":"<<c[i][j]<<endl;
      if(i==j) continue;
      G.add_edge(j,i,c[i][j]);
    }
  }
  cout<<fixed<<setprecision(12)<<G.build(m)<<endl;
  return 0;
}

/*
  verified on 2018/07/26
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2309
*/

signed main(){
  //AOJ_GRL_2B ans;
  //UVA11183 ans;
  //ans.solve();
  AOJ_2309();
  return 0;
}
