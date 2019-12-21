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


# :warning: datastructure/prioritysum.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/prioritysum.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 21:51:08+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
// return sum of top K element (default: maximum)
template<typename T, T identity, typename V=vector<T>,
         typename C1=less<T>, typename C2=greater<T> >
struct PrioritySum{
  size_t num;
  T sum;
  priority_queue<T, V, C1> pq1;
  priority_queue<T, V, C2> pq2;
  PrioritySum():num(0),sum(identity){}
  PrioritySum(size_t num):num(num),sum(identity){}

  void resolve(){
    assert(size()>=num);
    while(pq2.size()<num){
      sum+=pq1.top();
      pq2.emplace(pq1.top());
      pq1.pop();
    }
    while(pq2.size()>num){
      sum-=pq2.top();
      pq1.emplace(pq2.top());
      pq2.pop();
    }
    if(pq1.empty()||pq2.empty()) return;
    while(C2()(pq1.top(),pq2.top())){
      T t1=pq1.top();pq1.pop();
      T t2=pq2.top();pq2.pop();
      sum+=t1;
      sum-=t2;
      pq1.emplace(t2);
      pq2.emplace(t1);
    }
  }

  T query(){resolve();return sum;}

  void push(const T &x){pq1.emplace(x);}
  void expand(){num++;}
  void shrink(){assert(num);num--;}

  size_t size()const{return pq1.size()+pq2.size();}
};
template<typename T>
using MaximumSum=PrioritySum<T, T(0), vector<T>, less<T>, greater<T> >;
template<typename T>
using MinimumSum=PrioritySum<T, T(0), vector<T>, greater<T>, less<T> >;

//END CUT HERE

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed ARC074_D(){
  using ll = long long;

  int n;
  cin>>n;
  vector<ll> a(3*n);
  for(int i=0;i<3*n;i++) cin>>a[i];

  MaximumSum<ll> ps1(n);
  vector<ll> dp1(3*n);
  for(int i=0;i<3*n;i++){
    if(i>=n) dp1[i]=ps1.query();
    ps1.push(a[i]);
  }

  MinimumSum<ll> ps2(n);
  vector<ll> dp2(3*n);
  for(int i=3*n-1;i>=0;i--){
    ps2.push(a[i]);
    if(i<=2*n) dp2[i]=ps2.query();
  }

  ll ans=dp1[n]-dp2[n];
  for(int i=n;i<=2*n;i++) chmax(ans,dp1[i]-dp2[i]);

  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/04/09
  https://atcoder.jp/contests/arc074/tasks/arc074_b
*/

signed CGR002_F(){
  using ll = long long;
  using P = pair<ll, ll>;
  int n;
  cin>>n;
  vector<vector<P> > G(n);
  for(int i=1;i<n;i++){
    ll a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    G[a].emplace_back(b,c);
    G[b].emplace_back(a,c);
  }

  auto cmp=[&](P a,P b){
             return G[a.first].size()>G[b.first].size();
           };
  for(auto &v:G)
    sort(v.begin(),v.end(),cmp);

  vector<vector<int> > alive(n),death(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<=(int)G[i].size();j++)
      alive[j].emplace_back(i);
    death[G[i].size()].emplace_back(i);
  }

  vector<MinimumSum<ll> > ms(n);

  vector<int> par(n,-1),cst(n,0),children(n,0);
  auto dfs=
    [&](int v,int p,auto func)->void{
      for(auto e:G[v]){
        ll u=e.first,c=e.second;
        if(u==p) continue;
        par[u]=v;
        cst[u]=c;
        children[v]++;
        func(u,v,func);
      }
    };
  dfs(0,-1,dfs);

  const ll INF = 1e18;

  vector<int> used(n,0),dead(n,0);
  auto dfs2=
    [&](int v,int p,int t,auto func)->P{
      used[v]=1;
      vector<ll> res;
      ll sum=0;
      for(auto e:G[v]){
        ll u=e.first,c=e.second;
        if(u==p) continue;
        if(dead[u]) break;
        P tmp=func(u,v,t,func);
        sum+=tmp.second;
        res.emplace_back((tmp.first+c)-tmp.second);
      }
      sort(res.begin(),res.end());

      ll x=INF,y=INF,z=0;
      int num=children[v]-t;
      assert(num>=-1);
      for(int i=0;i<=(int)res.size();i++){
        int j=max(num-i,0);
        if(j<=(int)ms[v].size()){
          while((int)ms[v].num<j) ms[v].expand();
          while((int)ms[v].num>j) ms[v].shrink();
          chmin(x,sum+z+ms[v].query());
        }
        int k=max(num-i+1,0);
        if(k<=(int)ms[v].size()){
          while((int)ms[v].num<k) ms[v].expand();
          while((int)ms[v].num>k) ms[v].shrink();
          chmin(y,sum+z+ms[v].query());
        }
        if(i<(int)res.size()) z+=res[i];
      }
      return P(x,y);
    };

  for(int t=0;t<n;t++){
    if(t) cout<<" ";
    ll res=0;
    for(int v:alive[t]){
      if(used[v]) continue;
      int u=v;
      while(~par[u]&&!dead[par[u]]) u=par[u];
      P tmp=dfs2(u,par[u],t,dfs2);
      res+=min(tmp.first+cst[u],tmp.second);
    }

    cout<<res;
    for(int v:alive[t]) used[v]=0;
    for(int v:death[t]){
      dead[v]=1;
      for(auto e:G[v])
        if(e.first==par[v])
          ms[e.first].push(e.second);
    }
  }
  cout<<endl;
  return 0;
}
/*
  verified on 2019/04/10
  https://codeforces.com/contest/1119/problem/F
*/

signed main(){
  //ARC074_D();
  //CGR002_F();
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/prioritysum.cpp"
#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
// return sum of top K element (default: maximum)
template<typename T, T identity, typename V=vector<T>,
         typename C1=less<T>, typename C2=greater<T> >
struct PrioritySum{
  size_t num;
  T sum;
  priority_queue<T, V, C1> pq1;
  priority_queue<T, V, C2> pq2;
  PrioritySum():num(0),sum(identity){}
  PrioritySum(size_t num):num(num),sum(identity){}

  void resolve(){
    assert(size()>=num);
    while(pq2.size()<num){
      sum+=pq1.top();
      pq2.emplace(pq1.top());
      pq1.pop();
    }
    while(pq2.size()>num){
      sum-=pq2.top();
      pq1.emplace(pq2.top());
      pq2.pop();
    }
    if(pq1.empty()||pq2.empty()) return;
    while(C2()(pq1.top(),pq2.top())){
      T t1=pq1.top();pq1.pop();
      T t2=pq2.top();pq2.pop();
      sum+=t1;
      sum-=t2;
      pq1.emplace(t2);
      pq2.emplace(t1);
    }
  }

  T query(){resolve();return sum;}

  void push(const T &x){pq1.emplace(x);}
  void expand(){num++;}
  void shrink(){assert(num);num--;}

  size_t size()const{return pq1.size()+pq2.size();}
};
template<typename T>
using MaximumSum=PrioritySum<T, T(0), vector<T>, less<T>, greater<T> >;
template<typename T>
using MinimumSum=PrioritySum<T, T(0), vector<T>, greater<T>, less<T> >;

//END CUT HERE

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed ARC074_D(){
  using ll = long long;

  int n;
  cin>>n;
  vector<ll> a(3*n);
  for(int i=0;i<3*n;i++) cin>>a[i];

  MaximumSum<ll> ps1(n);
  vector<ll> dp1(3*n);
  for(int i=0;i<3*n;i++){
    if(i>=n) dp1[i]=ps1.query();
    ps1.push(a[i]);
  }

  MinimumSum<ll> ps2(n);
  vector<ll> dp2(3*n);
  for(int i=3*n-1;i>=0;i--){
    ps2.push(a[i]);
    if(i<=2*n) dp2[i]=ps2.query();
  }

  ll ans=dp1[n]-dp2[n];
  for(int i=n;i<=2*n;i++) chmax(ans,dp1[i]-dp2[i]);

  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/04/09
  https://atcoder.jp/contests/arc074/tasks/arc074_b
*/

signed CGR002_F(){
  using ll = long long;
  using P = pair<ll, ll>;
  int n;
  cin>>n;
  vector<vector<P> > G(n);
  for(int i=1;i<n;i++){
    ll a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    G[a].emplace_back(b,c);
    G[b].emplace_back(a,c);
  }

  auto cmp=[&](P a,P b){
             return G[a.first].size()>G[b.first].size();
           };
  for(auto &v:G)
    sort(v.begin(),v.end(),cmp);

  vector<vector<int> > alive(n),death(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<=(int)G[i].size();j++)
      alive[j].emplace_back(i);
    death[G[i].size()].emplace_back(i);
  }

  vector<MinimumSum<ll> > ms(n);

  vector<int> par(n,-1),cst(n,0),children(n,0);
  auto dfs=
    [&](int v,int p,auto func)->void{
      for(auto e:G[v]){
        ll u=e.first,c=e.second;
        if(u==p) continue;
        par[u]=v;
        cst[u]=c;
        children[v]++;
        func(u,v,func);
      }
    };
  dfs(0,-1,dfs);

  const ll INF = 1e18;

  vector<int> used(n,0),dead(n,0);
  auto dfs2=
    [&](int v,int p,int t,auto func)->P{
      used[v]=1;
      vector<ll> res;
      ll sum=0;
      for(auto e:G[v]){
        ll u=e.first,c=e.second;
        if(u==p) continue;
        if(dead[u]) break;
        P tmp=func(u,v,t,func);
        sum+=tmp.second;
        res.emplace_back((tmp.first+c)-tmp.second);
      }
      sort(res.begin(),res.end());

      ll x=INF,y=INF,z=0;
      int num=children[v]-t;
      assert(num>=-1);
      for(int i=0;i<=(int)res.size();i++){
        int j=max(num-i,0);
        if(j<=(int)ms[v].size()){
          while((int)ms[v].num<j) ms[v].expand();
          while((int)ms[v].num>j) ms[v].shrink();
          chmin(x,sum+z+ms[v].query());
        }
        int k=max(num-i+1,0);
        if(k<=(int)ms[v].size()){
          while((int)ms[v].num<k) ms[v].expand();
          while((int)ms[v].num>k) ms[v].shrink();
          chmin(y,sum+z+ms[v].query());
        }
        if(i<(int)res.size()) z+=res[i];
      }
      return P(x,y);
    };

  for(int t=0;t<n;t++){
    if(t) cout<<" ";
    ll res=0;
    for(int v:alive[t]){
      if(used[v]) continue;
      int u=v;
      while(~par[u]&&!dead[par[u]]) u=par[u];
      P tmp=dfs2(u,par[u],t,dfs2);
      res+=min(tmp.first+cst[u],tmp.second);
    }

    cout<<res;
    for(int v:alive[t]) used[v]=0;
    for(int v:death[t]){
      dead[v]=1;
      for(auto e:G[v])
        if(e.first==par[v])
          ms[e.first].push(e.second);
    }
  }
  cout<<endl;
  return 0;
}
/*
  verified on 2019/04/10
  https://codeforces.com/contest/1119/problem/F
*/

signed main(){
  //ARC074_D();
  //CGR002_F();
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

