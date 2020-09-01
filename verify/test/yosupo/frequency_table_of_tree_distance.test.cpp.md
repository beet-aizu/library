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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/yosupo/frequency_table_of_tree_distance.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/frequency_table_of_tree_distance.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-28 14:30:55+09:00


* see: <a href="https://judge.yosupo.jp/problem/frequency_table_of_tree_distance">https://judge.yosupo.jp/problem/frequency_table_of_tree_distance</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/convolution/fastfouriertransform.cpp.html">convolution/fastfouriertransform.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/fixpoint.cpp.html">tools/fixpoint.cpp</a>
* :heavy_check_mark: <a href="../../../library/tree/centroid.cpp.html">tree/centroid.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tree/centroid.cpp"
#include "../../tools/fixpoint.cpp"
#include "../../convolution/fastfouriertransform.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  Centroid G(n);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    G.add_edge(a,b);
  }

  queue<int> que;
  que.emplace(G.build(0)[0]);

  using ll = long long;
  vector<ll> ans(n,0);
  while(!que.empty()){
    int r=que.front();que.pop();

    vector<ll> cnt;
    cnt.emplace_back(1);
    for(int c:G[r]){
      if(!G.alive(c)) continue;
      vector<ll> num;
      MFP([&](auto dfs,int v,int p,int d)->void{
        while((int)cnt.size()<=d)
          cnt.emplace_back(0);
        while((int)num.size()<=d)
          num.emplace_back(0);
        cnt[d]++;
        num[d]++;
        for(int u:G[v]){
          if(u==p or !G.alive(u)) continue;
          dfs(u,v,d+1);
        }
      })(c,r,1);
      auto ns=FFT::multiply(num,num);
      for(int i=0;i<(int)ns.size();i++) ans[i]-=ns[i];
    }
    auto cs=FFT::multiply(cnt,cnt);
    for(int i=0;i<(int)cs.size();i++) ans[i]+=cs[i];

    G.disable(r);
    for(int c:G[r])
      if(G.alive(c))
        que.emplace(G.build(c)[0]);
  }

  for(int i=1;i<n;i++){
    if(i!=1) cout<<' ';
    cout<<ans[i]/2;
  }
  cout<<endl;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/frequency_table_of_tree_distance.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "tree/centroid.cpp"

#line 3 "tree/centroid.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
struct Centroid{
  vector<int> sz,dead;
  vector< vector<int> > G;
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
    if(ok) cs.emplace_back(v);
  }

  vector<int> build(int r) {
    int tmp=dfs(r,-1);
    vector<int> cs;
    find(r,-1,tmp,cs);
    return cs;
  }

  const vector<int>& operator[](int k)const{return G[k];}
  void disable(int v){dead[v]=1;}
  void  enable(int v){dead[v]=0;}
  int alive(int v){return !dead[v];}
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
#line 1 "tools/fixpoint.cpp"

#line 3 "tools/fixpoint.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
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
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
#line 1 "convolution/fastfouriertransform.cpp"

#line 3 "convolution/fastfouriertransform.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
namespace FFT{
  using dbl = double;

  struct num{
    dbl x,y;
    num(){x=y=0;}
    num(dbl x,dbl y):x(x),y(y){}
  };

  inline num operator+(num a,num b){
    return num(a.x+b.x,a.y+b.y);
  }
  inline num operator-(num a,num b){
    return num(a.x-b.x,a.y-b.y);
  }
  inline num operator*(num a,num b){
    return num(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
  }
  inline num conj(num a){
    return num(a.x,-a.y);
  }

  int base=1;
  vector<num> rts={{0,0},{1,0}};
  vector<int> rev={0,1};

  const dbl PI=asinl(1)*2;

  void ensure_base(int nbase){
    if(nbase<=base) return;

    rev.resize(1<<nbase);
    for(int i=0;i<(1<<nbase);i++)
      rev[i]=(rev[i>>1]>>1)+((i&1)<<(nbase-1));

    rts.resize(1<<nbase);
    while(base<nbase){
      dbl angle=2*PI/(1<<(base+1));
      for(int i=1<<(base-1);i<(1<<base);i++){
        rts[i<<1]=rts[i];
        dbl angle_i=angle*(2*i+1-(1<<base));
        rts[(i<<1)+1]=num(cos(angle_i),sin(angle_i));
      }
      base++;
    }
  }

  void fft(vector<num> &as){
    int n=as.size();
    assert((n&(n-1))==0);

    int zeros=__builtin_ctz(n);
    ensure_base(zeros);
    int shift=base-zeros;
    for(int i=0;i<n;i++)
      if(i<(rev[i]>>shift))
        swap(as[i],as[rev[i]>>shift]);

    for(int k=1;k<n;k<<=1){
      for(int i=0;i<n;i+=2*k){
        for(int j=0;j<k;j++){
          num z=as[i+j+k]*rts[j+k];
          as[i+j+k]=as[i+j]-z;
          as[i+j]=as[i+j]+z;
        }
      }
    }
  }

  template<typename T>
  vector<long long> multiply(vector<T> &as,vector<T> &bs){
    int need=as.size()+bs.size()-1;
    int nbase=0;
    while((1<<nbase)<need) nbase++;
    ensure_base(nbase);

    int sz=1<<nbase;
    vector<num> fa(sz);
    for(int i=0;i<sz;i++){
      T x=(i<(int)as.size()?as[i]:0);
      T y=(i<(int)bs.size()?bs[i]:0);
      fa[i]=num(x,y);
    }
    fft(fa);

    num r(0,-0.25/sz);
    for(int i=0;i<=(sz>>1);i++){
      int j=(sz-i)&(sz-1);
      num z=(fa[j]*fa[j]-conj(fa[i]*fa[i]))*r;
      if(i!=j)
        fa[j]=(fa[i]*fa[i]-conj(fa[j]*fa[j]))*r;
      fa[i]=z;
    }
    fft(fa);

    vector<long long> res(need);
    for(int i=0;i<need;i++)
      res[i]=round(fa[i].x);

    return res;
  }

};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
#line 10 "test/yosupo/frequency_table_of_tree_distance.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  Centroid G(n);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    G.add_edge(a,b);
  }

  queue<int> que;
  que.emplace(G.build(0)[0]);

  using ll = long long;
  vector<ll> ans(n,0);
  while(!que.empty()){
    int r=que.front();que.pop();

    vector<ll> cnt;
    cnt.emplace_back(1);
    for(int c:G[r]){
      if(!G.alive(c)) continue;
      vector<ll> num;
      MFP([&](auto dfs,int v,int p,int d)->void{
        while((int)cnt.size()<=d)
          cnt.emplace_back(0);
        while((int)num.size()<=d)
          num.emplace_back(0);
        cnt[d]++;
        num[d]++;
        for(int u:G[v]){
          if(u==p or !G.alive(u)) continue;
          dfs(u,v,d+1);
        }
      })(c,r,1);
      auto ns=FFT::multiply(num,num);
      for(int i=0;i<(int)ns.size();i++) ans[i]-=ns[i];
    }
    auto cs=FFT::multiply(cnt,cnt);
    for(int i=0;i<(int)cs.size();i++) ans[i]+=cs[i];

    G.disable(r);
    for(int c:G[r])
      if(G.alive(c))
        que.emplace(G.build(c)[0]);
  }

  for(int i=1;i<n;i++){
    if(i!=1) cout<<' ';
    cout<<ans[i]/2;
  }
  cout<<endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

