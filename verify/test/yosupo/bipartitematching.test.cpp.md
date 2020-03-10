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


# :heavy_check_mark: test/yosupo/bipartitematching.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/bipartitematching.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-05 21:02:53+09:00


* see: <a href="https://judge.yosupo.jp/problem/bipartitematching">https://judge.yosupo.jp/problem/bipartitematching</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/flow/hopcroft_karp.cpp.html">flow/hopcroft_karp.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../flow/hopcroft_karp.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int L,R,M;
  cin>>L>>R>>M;
  BiMatch G(L,R);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    G.add_edge(a,b);
  }
  cout<<G.build()<<endl;
  for(int i=0;i<L;i++){
    if(~G.match[i])
      cout<<i<<" "<<G.match[i]-L<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/bipartitematching.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "test/yosupo/../../flow/hopcroft_karp.cpp"

#line 3 "test/yosupo/../../flow/hopcroft_karp.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
struct BiMatch{
  int L,R;
  vector<vector<int> > G;
  vector<int> match,level;

  BiMatch(){}
  BiMatch(int L,int R):L(L),R(R),G(L+R),match(L+R,-1),level(L+R){}

  void add_edge(int u,int v){
    G[u].emplace_back(v+L);
    G[v+L].emplace_back(u);
  }

  bool bfs(){
    fill(level.begin(),level.end(),-1);
    queue<int> que;
    for(int i=0;i<L;i++){
      if(~match[i]) continue;
      level[i]=0;
      que.emplace(i);
    }
    bool found=false;
    while(!que.empty()){
      int v=que.front();que.pop();
      for(int u:G[v]){
        if(~level[u]) continue;
        level[u]=level[v]+1;
        int w=match[u];
        if(w==-1){
          found=true;
          continue;
        }
        if(~level[w]) continue;
        level[w]=level[u]+1;
        que.emplace(w);
      }
    }
    return found;
  }

  bool dfs(int v){
    for(int u:G[v]){
      if(level[v]+1!=level[u]) continue;
      level[u]=-1;
      int w=match[u];
      if(w<0||dfs(w)){
        match[v]=u;
        match[u]=v;
        level[v]=-1;
        return true;
      }
    }
    level[v]=-1;
    return false;
  }

  int build(){
    int res=0;
    while(bfs())
      for(int i=0;i<L;i++)
        if(match[i]<0&&dfs(i))
          res++;
    return res;
  }

};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
#line 8 "test/yosupo/bipartitematching.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int L,R,M;
  cin>>L>>R>>M;
  BiMatch G(L,R);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    G.add_edge(a,b);
  }
  cout<<G.build()<<endl;
  for(int i=0;i<L;i++){
    if(~G.match[i])
      cout<<i<<" "<<G.match[i]-L<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

