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


# :warning: graph/girth.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/girth.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 21:51:08+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
// size of minimum cycle
int girth(vector< vector<int> > G){
  int n=G.size();
  int res=n+1;
  vector<int> dp(n),pr(n);
  for(int s=0;s<n;s++){
    fill(dp.begin(),dp.end(),-1);
    fill(pr.begin(),pr.end(),-1);
    queue<int> que;
    dp[s]=0;
    que.emplace(s);
    while(!que.empty()){
      int v=que.front();que.pop();
      if(res<=dp[v]*2) break;
      for(int u:G[v]){
        if(u==pr[v]) continue;
        if(~dp[u]){
          res=min(res,dp[u]+dp[v]+1);
          continue;
        }
        dp[u]=dp[v]+1;
        pr[u]=v;
        que.emplace(u);
      }
    }
  }
  if(res>n) res=-1;
  return res;
}
//END CUT HERE
//INSERT ABOVE HERE

signed CFR580_B(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int n;
  cin>>n;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];
  sort(as.rbegin(),as.rend());

  if(as[0]==0){
    cout<<-1<<endl;
    return 0;
  }

  while(as.back()==0) as.pop_back();
  n=as.size();

  if(n>=200){
    cout<<3<<endl;
    return 0;
  }

  vector< vector<int> > G(n);
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if((i!=j)&&(as[i]&as[j]))
        G[i].emplace_back(j);

  cout<<girth(G)<<endl;
  return 0;
}
/*
  verified on 2019/08/21
  https://codeforces.com/contest/1205/problem/B
*/

signed main(){
  CFR580_B();
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/girth.cpp"
#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
// size of minimum cycle
int girth(vector< vector<int> > G){
  int n=G.size();
  int res=n+1;
  vector<int> dp(n),pr(n);
  for(int s=0;s<n;s++){
    fill(dp.begin(),dp.end(),-1);
    fill(pr.begin(),pr.end(),-1);
    queue<int> que;
    dp[s]=0;
    que.emplace(s);
    while(!que.empty()){
      int v=que.front();que.pop();
      if(res<=dp[v]*2) break;
      for(int u:G[v]){
        if(u==pr[v]) continue;
        if(~dp[u]){
          res=min(res,dp[u]+dp[v]+1);
          continue;
        }
        dp[u]=dp[v]+1;
        pr[u]=v;
        que.emplace(u);
      }
    }
  }
  if(res>n) res=-1;
  return res;
}
//END CUT HERE
//INSERT ABOVE HERE

signed CFR580_B(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int n;
  cin>>n;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];
  sort(as.rbegin(),as.rend());

  if(as[0]==0){
    cout<<-1<<endl;
    return 0;
  }

  while(as.back()==0) as.pop_back();
  n=as.size();

  if(n>=200){
    cout<<3<<endl;
    return 0;
  }

  vector< vector<int> > G(n);
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if((i!=j)&&(as[i]&as[j]))
        G[i].emplace_back(j);

  cout<<girth(G)<<endl;
  return 0;
}
/*
  verified on 2019/08/21
  https://codeforces.com/contest/1205/problem/B
*/

signed main(){
  CFR580_B();
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

