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


# :warning: graph/semikernel.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/semikernel.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 21:51:08+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
// https://link.springer.com/content/pdf/10.1007%2FBFb0066192.pdf
struct SemiKernel{
  int n;
  vector<vector<int> > G,R;
  vector<int> used,dp,S;
  SemiKernel(int n):n(n),G(n),R(n),used(n,0),dp(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    R[v].emplace_back(u);
  }

  void dfs(int v){
    if(v==n) return;
    if(used[v]){
      dfs(v+1);
      return;
    }
    used[v]=1;
    for(int u:G[v]) used[u]=1;
    dfs(v+1);
    dp[v]=1;
    for(int u:R[v]) dp[v]&=!dp[u];
    if(dp[v]) S.emplace_back(v);
  }

  vector<int> build(){
    dfs(0);
    reverse(S.begin(),S.end());
    return S;
  }
};
//END CUT HERE
//INSERT ABOVE HERE
signed CFR503_C(){
  int n,m;
  scanf("%d %d",&n,&m);

  SemiKernel sk(n);

  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    a--;b--;
    sk.add_edge(a,b);
  }

  auto ans=sk.build();
  printf("%d\n",(int)ans.size());
  for(int i=0;i<(int)ans.size();i++){
    if(i) printf(" ");
    printf("%d",ans[i]+1);
  }
  puts("");
  return 0;
}
/*
  verified on 2018/08/12
  http://codeforces.com/contest/1019/problem/C
*/

signed main(){
  CFR503_C();
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/semikernel.cpp"
#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
// https://link.springer.com/content/pdf/10.1007%2FBFb0066192.pdf
struct SemiKernel{
  int n;
  vector<vector<int> > G,R;
  vector<int> used,dp,S;
  SemiKernel(int n):n(n),G(n),R(n),used(n,0),dp(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    R[v].emplace_back(u);
  }

  void dfs(int v){
    if(v==n) return;
    if(used[v]){
      dfs(v+1);
      return;
    }
    used[v]=1;
    for(int u:G[v]) used[u]=1;
    dfs(v+1);
    dp[v]=1;
    for(int u:R[v]) dp[v]&=!dp[u];
    if(dp[v]) S.emplace_back(v);
  }

  vector<int> build(){
    dfs(0);
    reverse(S.begin(),S.end());
    return S;
  }
};
//END CUT HERE
//INSERT ABOVE HERE
signed CFR503_C(){
  int n,m;
  scanf("%d %d",&n,&m);

  SemiKernel sk(n);

  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    a--;b--;
    sk.add_edge(a,b);
  }

  auto ans=sk.build();
  printf("%d\n",(int)ans.size());
  for(int i=0;i<(int)ans.size();i++){
    if(i) printf(" ");
    printf("%d",ans[i]+1);
  }
  puts("");
  return 0;
}
/*
  verified on 2018/08/12
  http://codeforces.com/contest/1019/problem/C
*/

signed main(){
  CFR503_C();
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

