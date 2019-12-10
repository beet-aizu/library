---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: tree/centroid.cpp
* category: tree


<a href="../../index.html">Back to top page</a>



## Verified
* :heavy_check_mark: <a href="../../verify/test/aoj/2790.test.cpp.html">test/aoj/2790.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#endif
//BEGIN CUT HERE
struct Centroid{
  vector<int> sz,dead;
  vector<vector<int> > G;
  Centroid(){}
  Centroid(int n):sz(n,1),dead(n,0),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  int dfs(int v,int p){
    sz[v]=1;
    for(int u:G[v])
      if(u!=p&&!dead[u]) sz[v]+=dfs(u,v);
    return sz[v];
  }

  void find(int v,int p,int tmp,vector<int> &cs) {
    int ok=1;
    for (int u:G[v]){
      if(u==p||dead[u]) continue;
      find(u,v,tmp,cs);
      ok&=(sz[u]<=tmp/2);
    }
    ok&=(tmp-sz[v]<=tmp/2);
    if(ok) cs.push_back(v);
  }

  vector<int> build(int r) {
    int tmp=dfs(r,-1);
    vector<int> cs;
    find(r,-1,tmp,cs);
    return cs;
  }

  void disable(int v){
    dead[v]=1;
  }

  void enable(int v){
    dead[v]=0;
  }

  int alive(int v){
    return !dead[v];
  }
};

//END CUT HERE
#ifndef call_from_test

template<typename F>
struct FixPoint : F{
  FixPoint(F&& f):F(forward<F>(f)){}
  template<typename... Args>
  decltype(auto) operator()(Args&&... args) const{
    return F::operator()(*this,forward<Args>(args)...);
  }
};
template<typename F>
inline decltype(auto) MFP(F&& f){
  return FixPoint<F>{forward<F>(f)};
}

//INSERT ABOVE HERE
signed DWANGO2018QUAL_E(){
  int n,q;
  cin>>n>>q;
  Centroid C(n);
  for(int i=1;i<n;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    C.add_edge(x,y);
  }

  int r=0;
  for(int l=0;l<q;l++){
    auto c=C.build(r);
    if(c.size()==2u){
      cout<<"? "<<c[0]+1<<" "<<c[1]+1<<endl;
      int x;
      cin>>x;
      if(x==c[0]+1){
        r=c[0];
        C.disable(c[1]);
      }
      if(x==c[1]+1){
        r=c[1];
        C.disable(c[0]);
      }
    }else{
      using P = pair<int, int>;
      vector<P> vp;
      for(int u:C.G[c[0]])
        if(C.alive(u)) vp.emplace_back(C.sz[u],u);
      sort(vp.rbegin(),vp.rend());
      if(vp.empty()){
        cout<<"! "<<c[0]+1<<endl;
        return 0;
      }
      if(vp.size()==1u){
        c.emplace_back(vp[0].second);
        cout<<"? "<<c[0]+1<<" "<<c[1]+1<<endl;
        int x;
        cin>>x;
        cout<<"! "<<x<<endl;
        return 0;
      }else{
        int a=vp[0].second;
        int b=vp[1].second;
        cout<<"? "<<a+1<<" "<<b+1<<endl;
        int x;
        cin>>x;
        if(x==0){
          r=c[0];
          C.disable(a);
          C.disable(b);
        }
        if(x==a+1){
          r=a;
          C.disable(c[0]);
        }
        if(x==b+1){
          r=b;
          C.disable(c[0]);
        }
      }
    }
  }
  while(1);
}
/*
  verified on 2019/06/24
  https://beta.atcoder.jp/contests/dwacon2018-prelims/tasks/dwacon2018_prelims_e
*/

signed YAHOO2018FINAL_C(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  Centroid G(n);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.add_edge(a,b);
  }

  vector<int> as(q),bs(q);
  for(int i=0;i<q;i++) cin>>as[i]>>bs[i];
  vector<vector<int> > idx(n);
  for(int i=0;i<q;i++) idx[--as[i]].emplace_back(i);
  vector<int> ans(q,0);
  vector<int> dep(n),num(n);

  queue<int> que;
  que.emplace(0);
  while(!que.empty()){
    vector<vector<int> > dp;
    vector<int> sum(1,1);
    vector<int> check;
    int v=G.build(que.front())[0];que.pop();
    int k=0;

    for(int u:G.G[v]){
      if(!G.alive(u)) continue;
      dp.emplace_back();
      MFP([&](auto dfs,int v,int p,int d,int k)->void{
            while(d>=(int)dp[k].size()) dp[k].emplace_back(0);
            while(d>=(int)sum.size()) sum.emplace_back(0);
            dp[k][d]++;
            sum[d]++;
            dep[v]=d;
            num[v]=k;
            for(int u:G.G[v]){
              if(u==p||!G.alive(u)) continue;
              dfs(u,v,d+1,k);
            }
            if(!idx[v].empty()) check.emplace_back(v);
          })(u,v,1,k++);
    }

    auto calc=
      [&](auto &z,int k)->int{
        if(k<0||k>=(int)z.size()) return 0;
        return z[k];
      };

    for(int y:idx[v])
      ans[y]+=calc(sum,bs[y]);

    for(int x:check)
      for(int y:idx[x])
        ans[y]+=calc(sum,bs[y]-dep[x])-calc(dp[num[x]],bs[y]-dep[x]);

    G.disable(v);
    for(int u:G.G[v])
      if(G.alive(u)) que.emplace(u);
  }

  for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/24
  https://atcoder.jp/contests/yahoo-procon2018-final-open/tasks/yahoo_procon2018_final_c
*/

signed main(){
  //DWANGO2018QUAL_E();
  //YAHOO2018FINAL_C();
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

