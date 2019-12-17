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


# :heavy_check_mark: tree/rerooting.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/rerooting.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-30 14:55:12 +0900




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/1595.test.cpp.html">test/aoj/1595.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Data, typename T>
struct ReRooting{
  struct Node{
    int to,rev;
    Data data;
    Node(int to,int rev,Data data):to(to),rev(rev),data(data){}
  };

  using F1 = function<T(T, T)>;
  using F2 = function<T(T, Data)>;

  vector<vector<Node> > G;
  vector<vector<T> > ld,rd;
  vector<int> lp,rp;

  const F1 f1;
  const F2 f2;
  const T id;

  ReRooting(int n,const F1 f1,const F2 f2,const T id):
    G(n),ld(n),rd(n),lp(n),rp(n),f1(f1),f2(f2),id(id){}

  void add_edge(int u,int v,Data d){
    G[u].emplace_back(v,(int)G[v].size(),d);
    G[v].emplace_back(u,(int)G[u].size()-1,d);
  }

  T dfs(int v,int p){
    while(lp[v]!=p&&lp[v]<(int)G[v].size()){
      auto &e=G[v][lp[v]];
      ld[v][lp[v]+1]=f1(ld[v][lp[v]],f2(dfs(e.to,e.rev),e.data));
      lp[v]++;
    }
    while(rp[v]!=p&&rp[v]>=0){
      auto &e=G[v][rp[v]];
      rd[v][rp[v]]=f1(rd[v][rp[v]+1],f2(dfs(e.to,e.rev),e.data));
      rp[v]--;
    }
    if(p<0) return rd[v][0];
    return f1(ld[v][p],rd[v][p+1]);
  }

  vector<T> build(){
    for(int i=0;i<(int)G.size();i++){
      ld[i].assign((int)G[i].size()+1,id);
      rd[i].assign((int)G[i].size()+1,id);
      lp[i]=0;
      rp[i]=(int)G[i].size()-1;
    }
    vector<T> res;
    for(int i=0;i<(int)G.size();i++){
      res.emplace_back(dfs(i,-1));
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed YUKI_768(){
  int n;
  cin>>n;
  auto f1=[](int a,int b){return max(a,0)+max(b,0);};
  auto f2=[](int a,int d){return d-a;};
  ReRooting<int, int> G(n,f1,f2,0);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.add_edge(a,b,1);
  }
  auto res=G.build();
  vector<int> ans;
  for(int i=0;i<n;i++)
    if(1-res[i]>0) ans.emplace_back(i);
  cout<<ans.size()<<"\n";
  for(int x:ans) cout<<x+1<<"\n";
  cout<<flush;
  return 0;
};
/*
  verified on 2019/10/30
  https://yukicoder.me/problems/no/768
*/

signed DP_V(){
  int n,m;
  cin>>n>>m;
  auto f1=[m](int a,int b)->int{return (long long)a*b%m;};
  auto f2=[m](int a,int d)->int{return (a+d)%m;};
  ReRooting<int, int> G(n,f1,f2,1);
  for(int i=1;i<n;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    G.add_edge(x,y,1);
  }
  auto ans=G.build();
  for(int x:ans) cout<<x<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/30
  https://atcoder.jp/contests/dp/tasks/dp_v
*/

signed main(){
  //YUKI_768();
  DP_V();
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

