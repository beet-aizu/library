#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
template<typename K>
struct Matrix{
  typedef vector<K> arr;
  typedef vector<arr> mat;
  mat dat;

  Matrix(size_t r,size_t c):dat(r,arr(c,K())){}
  Matrix(mat dat):dat(dat){}

  size_t size() const{return dat.size();};
  bool empty() const{return size()==0;};
  arr& operator[](size_t k){return dat[k];};
  const arr& operator[](size_t k) const {return dat[k];};
  
  K determinant() const{
    Matrix A(dat);
    K res(1);
    int n=size();
    for(int i=0;i<n;i++){
      int p=i;
      for(int j=i;j<n;j++)
        if(A[j][i]!=K(0)) p=j;
      if(i!=p) swap(A[i],A[p]),res=-res;      
      if(A[i][i]==K(0)) return K(0);      
      res*=A[i][i];
      for(int j=i+1;j<n;j++) A[i][j]/=A[i][i];
      for(int j=i+1;j<n;j++)
        for(int k=i+1;k<n;k++)
          A[j][k]-=A[j][i]*A[i][k];
    }
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
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
  }
};

template<typename K, typename T>
struct MatrixTreeTheorem{
  using M = Matrix<K>;
  struct edge{
    int a,b;
    T c;
    edge(){}
    edge(int a,int b,T c):a(a),b(b),c(c){}
    bool operator<(const edge &e)const{
      return c<e.c;
    };
  };

  int n;
  vector<edge> es;
  vector<int> used;
  vector<vector<int> > H;

  MatrixTreeTheorem(){}
  MatrixTreeTheorem(int n):n(n),used(n),H(n){}

  void add_edge(int a,int b,T c){
    es.emplace_back(a,b,c);
  }
  
  vector<int> bfs(int v){
    vector<int> vs;
    queue<int> q;
    used[v]=1;
    q.emplace(v);
    while(!q.empty()){
      v=q.front();q.pop();
      vs.emplace_back(v);
      for(int u:H[v]){
        if(used[u]) continue;
        used[u]=1;
        q.emplace(u);
      }
    }
    return vs;
  }

  K build(){
    UnionFind uf(n);
    sort(es.begin(),es.end());
    fill(used.begin(),used.end(),0);
    K res(1);
    for(int i=0;i<(int)es.size();){
      queue<int> q,r;
      for(auto &h:H) h.clear();
      int p=i;
      while(i<(int)es.size()&&es[i].c==es[p].c){
        int u=uf.find(es[i].a);
        int v=uf.find(es[i++].b);
        H[u].emplace_back(v);
        H[v].emplace_back(u);
        q.emplace(u);q.emplace(v);
        r.emplace(u);r.emplace(v);
      }
      while(!q.empty()){
        int v=q.front();q.pop();
        if(used[v]) continue;
        vector<int> vs=bfs(v);
        int m=vs.size();
        if(m==1) continue;

        sort(vs.begin(),vs.end());
        auto idx=[&](int x){
                   return lower_bound(vs.begin(),vs.end(),x)-vs.begin();};
        M A(m,m);
        for(int x:vs)
          for(int y:H[x])
            if(x!=y) A[idx(x)][idx(y)]-=K(1);
        
        for(int x=0;x<m;x++)
          for(int y=0;y<m;y++)
            if(x!=y) A[x][x]-=A[x][y];
        
        A.dat.pop_back();
        for(auto &a:A.dat) a.pop_back();

        res*=A.determinant();        
        for(int x:vs) uf.unite(v,x);
      }
      while(!r.empty()){
        int v=r.front();r.pop();
        used[v]=0;        
      }
    }
    return res;
  }
};
// END CUT HERE
template<typename T,T MOD = 1000000007>
struct Mint{
  T v;
  Mint():v(0){}
  Mint(signed v):v(v){}
  Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}

  Mint pow(int k){
    Mint res(1),tmp(v);
    while(k){
      if(k&1) res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }
  
  Mint inv(){return pow(MOD-2);}
  
  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}
  
  Mint operator+(Mint a) const{return Mint(v)+=a;};
  Mint operator-(Mint a) const{return Mint(v)-=a;};
  Mint operator*(Mint a) const{return Mint(v)*=a;};
  Mint operator/(Mint a) const{return Mint(v)/=a;};

  Mint operator-(){return v?MOD-v:v;}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
};


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
    T res(0);
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

//INSERT ABOVE HERE

signed ARC018_D(){
  using M = Mint<int>;
  int n,m;
  scanf("%d %d",&n,&m);
  MatrixTreeTheorem<M, int> mtt(n);
  Kruskal<int> ksk(n);
  for(int i=0;i<m;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    a--;b--;
    mtt.add_edge(a,b,c);
    ksk.add_edge(a,b,c);
  }
  printf("%d %d\n",ksk.build(),mtt.build().v);
  return 0;
}
/*
  verified on 2018/10/17
  https://beta.atcoder.jp/contests/arc018/tasks/arc018_4
*/

signed main(){
  ARC018_D();
  return 0;
}
