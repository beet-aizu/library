#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct Mo{
  using F = function<void(int)>;
  vector<int> ls,rs,ord;
  int n,width,nl,nr,ptr;
  vector<bool> flg;
  F expand,shrink;

  Mo(int n,int width,F expand,F shrink):
    n(n),width(width),nl(0),nr(0),ptr(0),flg(n,0),
    expand(expand),shrink(shrink){}

  void add(int l,int r){
    ls.emplace_back(l);
    rs.emplace_back(r);
  }

  void build(){
    ord.resize(ls.size());
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),
         [&](int a,int b){
           if(ls[a]/width!=ls[b]/width) return ls[a]<ls[b];
           return bool((rs[a]<rs[b])^((ls[a]/width)&1));
         });
  }

  int process(){
    if(ptr==(int)ord.size()) return -1;
    const int idx=ord[ptr++];
    while(nl>ls[idx]) calc(--nl);
    while(nr<rs[idx]) calc(nr++);
    while(nl<ls[idx]) calc(nl++);
    while(nr>rs[idx]) calc(--nr);
    return idx;
  }

  inline void calc(int idx){
    flg[idx].flip();
    if(flg[idx]) expand(idx);
    else         shrink(idx);
  }

};
//END CUT HERE

template<typename T>
map<T, int> factorize(T x){
  map<T, int> res;
  for(int i=2;i*i<=x;i++){
    while(x%i==0){
      x/=i;
      res[i]++;
    }
  }
  if(x!=1) res[x]++;
  return res;
}

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T>
vector<vector<T> > make_v(size_t a,size_t b){
  return vector<vector<T> >(a,make_v<T>(b));
}
template<typename T>
vector<vector<vector<T> > > make_v(size_t a,size_t b,size_t c){
  return vector<vector<vector<T> > > (a,make_v<T>(b,c));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}


class EulerTourForEdge{
private:
  vector<int> ds,us,dep,btm;

  void dfs(int v,int p,int d){
    dep[v]=d;
    for(int u:G[v]){
      if(u==p) continue;
      ds[u]=btm.size();
      btm.emplace_back(u);
      dfs(u,v,d+1);
      us[u]=btm.size();
      btm.emplace_back(u);
    }
  }
public:
  vector<vector<int> > G;

  EulerTourForEdge(){}
  EulerTourForEdge(int n):
    ds(n),us(n),dep(n),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void build(int r=0){
    btm.clear();
    ds[r]=btm.size();
    btm.emplace_back(r);
    dfs(r,-1,0);
    us[r]=btm.size();
    btm.emplace_back(r);
  }

  int child(int u,int v){
    return dep[u]<dep[v]?v:u;
  }

  int bottom(int e){
    return btm[e];
  }

  // lca(u, v) must be u or v
  template<typename F>
  void query(int u,int v,F f){
    if(dep[u]>dep[v]) swap(u,v);
    f(ds[u]+1,ds[v]+1);
  }

  template<typename T,typename G>
  void update(int v,T x,G g){
    g(ds[v], x);
    g(us[v],-x);
  }
};

//INSERT ABOVE HERE
signed DWANGO2017FINAL_B(){
  using ll = long long;
  int n,q;
  cin>>n>>q;
  vector<int> x(n);
  for(int i=0;i<n;i++) cin>>x[i];

  const int RT = 40;
  auto acc=make_v<int>(RT,n+1);
  fill_v(acc,0);

  using P = pair<int, int>;
  vector<vector<P> > v(n);
  for(int i=0;i<n;i++){
    for(auto p:factorize(x[i])){
      if(p.first<RT) acc[p.first][i+1]+=p.second;
      else v[i].emplace_back(p);
    }
  }

  for(int j=0;j<RT;j++)
    for(int i=0;i<n;i++)
      acc[j][i+1]+=acc[j][i];

  ll res=1;
  const ll MOD = 1e9+7;
  const int MAX = 5e5+100;
  vector<int> cnt(MAX,0);
  vector<ll> fact(MAX),invs(MAX);

  fact[0]=1;
  for(Int i=1;i<MAX;i++)
    fact[i]=(fact[i-1]*i)%MOD;

  invs[1]=1;
  for(Int i=2;i<MAX;i++)
    invs[i]=invs[MOD%i]*(MOD-MOD/i)%MOD;

  auto expand=[&](int idx){
                for(auto p:v[idx]){
                  res*=invs[cnt[p.first]+1];
                  res%=MOD;
                  cnt[p.first]+=p.second;
                  res*=cnt[p.first]+1;
                  res%=MOD;
                }
              };
  auto shrink=[&](int idx){
                for(auto p:v[idx]){
                  res*=invs[cnt[p.first]+1];
                  res%=MOD;
                  cnt[p.first]-=p.second;
                  res*=cnt[p.first]+1;
                  res%=MOD;
                }
              };
  Mo mo(n,400,expand,shrink);

  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--;
    mo.add(l,r);
  }
  mo.build();

  vector<ll> ans(q);
  for(int i=0;i<q;i++){
    int k=mo.process();
    ans[k]=res;
    int l=mo.ls[k],r=mo.rs[k];
    for(int j=0;j<RT;j++){
      ans[k]*=acc[j][r]-acc[j][l]+1;
      ans[k]%=MOD;
    }
  }

  for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/07/08
  https://beta.atcoder.jp/contests/dwacon2017-honsen/tasks/dwango2017final_b
*/


signed ABC133_F(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  vector<int> as(n),bs(n),cs(n),ds(n);
  vector<int> xs(q),ys(q),us(q),vs(q);

  EulerTourForEdge et(n);
  for(int i=1;i<n;i++){
    cin>>as[i]>>bs[i]>>cs[i]>>ds[i];
    as[i]--;bs[i]--;
    et.add_edge(as[i],bs[i]);
  }
  et.build();

  vector<int> idx(n,0);
  for(int i=1;i<n;i++)
    idx[et.child(as[i],bs[i])]=i;

  for(int i=0;i<q;i++){
    cin>>xs[i]>>ys[i]>>us[i]>>vs[i];
    us[i]--;vs[i]--;
  }

  int all=0;
  vector<int> cnt(n),sum(n),app(n,0);
  auto exec=
    [&](int k){
      int v=et.bottom(k);
      int e=idx[v];
      app[v]^=1;
      if(app[v]){
        all+=ds[e];
        cnt[cs[e]]++;
        sum[cs[e]]+=ds[e];
      }else{
        all-=ds[e];
        cnt[cs[e]]--;
        sum[cs[e]]-=ds[e];
      }
    };
  Mo mo(n*2,400,exec,exec);

  for(int i=0;i<q;i++){
    auto f=[&](int l,int r){mo.add(min(l,r),max(l,r));};
    et.query(us[i],vs[i],f);
  }
  mo.build();

  vector<int> ans(q,0);
  for(int i=0;i<q;i++){
    int k=mo.process();
    ans[k]=all-sum[xs[k]]+cnt[xs[k]]*ys[k];
  }

  for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/07/08
  https://atcoder.jp/contests/abc133/tasks/abc133_f
*/


signed main(){
  //DWANGO2017FINAL_B();
  //ABC133_F();
  return 0;
}
