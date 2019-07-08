#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
struct EulerTourForEdge{
  int n,pos;
  vector<vector<int> > G;
  vector<int> dep,ds,us;

  EulerTourForEdge(){}
  EulerTourForEdge(int n):
    n(n),G(n),dep(n),ds(n),us(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void dfs(int v,int p,int d){
    dep[v]=d;
    for(int u:G[v]){
      if(u==p) continue;
      ds[u]=pos++;
      dfs(u,v,d+1);
      us[u]=pos++;
    }
  }

  void build(int r=0){
    pos=0;
    dfs(r,-1,0);
  }

  int child(int u,int v){
    return dep[u]<dep[v]?v:u;
  }

  template<typename T,typename F>
  T query(int v,F f){
    return f(0,us[v]);
  }

  template<typename T,typename G>
  void update(int v,T x,G g){
    g(ds[v],+x);
    g(us[v],-x);
  }
};
//END CUT HERE

template<typename T>
struct BIT{
  int n;
  vector<T> bit;
  //1-indexed
  BIT():n(-1){}
  BIT(int n_,T d):n(n_),bit(n_+1,d){}

  T sum(int i){
    T s=bit[0];
    for(int x=i;x>0;x-=(x&-x))
      s+=bit[x];
    return s;
  }
  void add(int i,T a){
    if(i==0) return;
    for(int x=i;x<=n;x+=(x&-x))
      bit[x]+=a;
  }

  int lower_bound(int w){
    if(w<=0) return 0;
    int x=0,r=1;
    while(r<n) r<<=1;
    for(int k=r;k>0;k>>=1){
      if(x+k<=n&&bit[x+k]<w){
        w-=bit[x+k];
        x+=k;
      }
    }
    return x+1;
  }

  T sum0(int i){
    return sum(i+1);
  }
  void add0(int i,T a){
    add(i+1,a);
  }

  T query(int l,int r){
    return sum(r-1)-sum(l-1);
  }

  T query0(int l,int r){
    return sum(r)-sum(l);
  }
};

//INSERT ABOVE HERE
signed AOJ_GRL_5_D(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  EulerTourForEdge et(n);
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int c;
      cin>>c;
      et.add_edge(i,c);
    }
  }
  et.build();

  BIT<int> bit(n*2+100,0);
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int v,w;
      cin>>v>>w;
      auto g=[&](int k,int d){bit.add0(k,d);};
      et.update(v,w,g);
    }
    if(t==1){
      int u;
      cin>>u;
      auto f=[&](int l,int r){return bit.query0(l,r);};
      cout<<et.query<int>(u,f)<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/07/08
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D&lang=jp
*/
signed main(){
  AOJ_GRL_5_D();
  return 0;
}
