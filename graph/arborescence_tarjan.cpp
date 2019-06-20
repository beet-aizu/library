#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
//INSERT ABOVE HERE
template<typename T>
struct Arborescence{  
  struct SkewHeap{
    using P = pair<T, int>;
    const P INF;    
    const T add_identity;    
    SkewHeap(T inf):INF(inf,-1),add_identity(0){}
    
    struct Node{
      Node *l,*r;
      P val;
      T add;
      Node(P val,T add):val(val),add(add){l=r=nullptr;}
    };
    
    P reflect(P x,T y){return P(x.first+y,x.second);}      
    
    void eval(Node *a){
      if(a==nullptr) return;
      if(a->add==add_identity) return;
      if(a->l) a->l->add+=a->add;
      if(a->r) a->r->add+=a->add;      
      a->val=reflect(a->val,a->add);      
      a->add=add_identity;
    }
    
    P top(Node *a){
      return a?reflect(a->val,a->add):INF;
    }
    
    P snd(Node *a){
      eval(a);
      return a?min(top(a->l),top(a->r)):INF;
    }
    
    Node* add(Node *a,T d){
      if(a) a->add+=d;
      return a;
    }
    
    Node* push(T v,int i){
      return new Node(P(v,i),add_identity);
    }
    
    Node* meld(Node *a,Node *b){
      if(!a||!b) return a?a:b;
      if(top(b)<top(a)) swap(a,b);
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
  
  struct edge{
    int from,to;
    T cost;
    edge(){}
    edge(int from,int to,T cost):from(from),to(to),cost(cost){}
  };

  int n;  
  SkewHeap hp;
  UnionFind uf;
  vector<edge> es;
  vector<typename SkewHeap::Node*> come;
  vector<int> used,from;
  vector<T> cost;
  
  Arborescence(int n,T INF):n(n),hp(INF),uf(n),come(n,NULL),
                            used(n,0),from(n,-1),cost(n,-1){};

  void add_edge(int from,int to,T cost){
    es.emplace_back(from,to,cost);
  }

  T build(int r){  
    used[r]=2;
    for(int i=0;i<(int)es.size();i++){
      edge &e=es[i];
      come[e.to]=hp.meld(come[e.to],hp.push(e.cost,i));
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
        from[v]=uf.find(es[come[v]->val.second].from);
        cost[v]=hp.top(come[v]).first;
        come[v]=hp.pop(come[v]);
        if(from[v]==v) continue;
	
        res+=cost[v];
        if(used[from[v]]==1){
          int p=v;
          do{
            if(come[p]!=nullptr) hp.add(come[p],-cost[p]);
            if(p!=v){
              uf.unite(v,p);
              come[v]=hp.meld(come[v],come[p]);
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

signed AOJ_GRL_2B(){
  int n,m,r;
  cin>>n>>m>>r;
  const int INF = 1e8;
  Arborescence<int> G(n,INF);
  for(int i=0;i<m;i++){
    int s,t,w;
    cin>>s>>t>>w;
    G.add_edge(s,t,w);
  }
  cout<<G.build(r)<<endl;
  return 0;
}
/*
  verified on 201/05/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B&lang=jp
*/

signed AOJ_2309(){  
  double v[111][111];
  double c[111][111];
  
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
      if(i==j) continue;
      G.add_edge(j,i,c[i][j]);
    }
  }
  cout<<fixed<<setprecision(12)<<G.build(m)<<endl;
  return 0;
}
/*
  verified on 2019/05/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2309
*/

signed UVA_11183(){
  Int T;
  cin>>T;
  for(Int t=1;t<=T;t++){
    Int n,m;
    cin>>n>>m;
    const Int INF = 1e15;
    Arborescence<Int> G(n,INF);      
    for(int i=0;i<m;i++){
      int s,t,w;
      cin>>s>>t>>w;      
      G.add_edge(s,t,w);
    }
    Int ans=G.build(0);
    cout<<"Case #"<<t<<": "; 
    if(ans<0) cout<<"Possums!"<<endl;
    else cout<<ans<<endl;
  }
  return 0;
}
/*
  verified on 2019/05/24
  https://vjudge.net/problem/UVA-11183
*/


signed main(){
  //AOJ_GRL_2B();
  //AOJ_2309();
  //UVA_11183();
  return 0;
}
