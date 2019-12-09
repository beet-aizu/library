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


# :warning: graph/independentset.cpp
* category: graph


[Back to top page](../../index.html)



## Verified
* :heavy_check_mark: [test/aoj/2948.test.cpp](../../verify/test/aoj/2948.test.cpp.html)
* :heavy_check_mark: [test/yosupo/maximum_independent_set.test.cpp](../../verify/test/yosupo/maximum_independent_set.test.cpp.html)


## Code
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct IndependentSet{
  int n;
  vector<int> deg,used,dead,pre,ans;
  vector<vector<int> > G;

  IndependentSet(int n):
    n(n),deg(n),used(n,0),dead(n,0),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  int res,cnt,alive;
  void dfs(){
    if(cnt+alive<=res) return;

    int v=-1;
    for(int i=0;i<n;i++){
      if(used[i]||dead[i]) continue;
      if(deg[i]<=1){
        v=i;
        break;
      }
      if(v<0||deg[v]<deg[i]) v=i;
    }
    if(v<0) return;

    if(deg[v]!=1){
      dead[v]=1;
      alive--;
      for(int u:G[v]) deg[u]--;

      dfs();

      dead[v]=0;
      alive++;
      for(int u:G[v]) deg[u]++;
    }
    {
      used[v]=1;
      alive--;
      for(int u:G[v])
        if(0==dead[u]++) alive-=!used[u];
      cnt++;
      if(res<cnt) pre=used;
      res=max(res,cnt);

      dfs();

      used[v]=0;
      alive++;
      for(int u:G[v])
        if(--dead[u]==0) alive+=!used[u];
      cnt--;
    }
  }

  int build(){
    for(int i=0;i<n;i++) deg[i]=G[i].size();
    res=0,cnt=0,alive=n;
    dfs();
    for(int i=0;i<n;i++)
      if(pre[i]) ans.emplace_back(i);
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed CODETHANKSFESTIVAL2017_G(){
  int n,m;
  cin>>n>>m;
  IndependentSet G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.add_edge(a,b);
  }
  cout<<G.build()<<endl;
  return 0;
}
/*
  verified on 2019/11/30
  https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_g
*/

signed CFR533_E(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;

  IndependentSet G(m);
  map<string, int> rev;

  vector<int> vs;

  using P = pair<int, int>;
  set<P> sp;
  auto add_edge=
    [&](){
      sort(vs.begin(),vs.end());
      vs.erase(unique(vs.begin(),vs.end()),vs.end());
      for(int x:vs){
        for(int y:vs){
          if(x==y) continue;
          if(sp.count(P(x,y))) continue;
          sp.emplace(x,y);
          sp.emplace(y,x);
          G.add_edge(x,y);
        }
      }
      vs.clear();
    };

  for(int i=0;i<n;i++){
    int t;
    cin>>t;
    if(t==1) add_edge();
    if(t==2){
      string s;
      cin>>s;
      if(!rev.count(s)){
        int sz=rev.size();
        rev[s]=sz;
      }
      vs.emplace_back(rev[s]);
    }
  }
  add_edge();

  cout<<G.build()<<endl;
  return 0;
}
/*
  verified on 2019/11/30
  https://codeforces.com/contest/1105/problem/E
*/
signed main(){
  //CODETHANKSFESTIVAL2017_G();
  //CFR533_E();
  return 0;
}
#endif

```

[Back to top page](../../index.html)

