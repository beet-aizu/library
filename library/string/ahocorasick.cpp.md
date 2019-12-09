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


# :warning: string/ahocorasick.cpp
* category: string


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [string/trie.cpp](trie.cpp.html)
* :heavy_check_mark: [tools/chminmax.cpp](../tools/chminmax.cpp.html)
* :heavy_check_mark: [tools/fastio.cpp](../tools/fastio.cpp.html)
* :heavy_check_mark: [tools/fixpoint.cpp](../tools/fixpoint.cpp.html)


## Verified
* :heavy_check_mark: [test/aoj/2212.test.cpp](../../verify/test/aoj/2212.test.cpp.html)
* :heavy_check_mark: [test/aoj/2257.test.cpp](../../verify/test/aoj/2257.test.cpp.html)
* :heavy_check_mark: [test/aoj/3073.test.cpp](../../verify/test/aoj/3073.test.cpp.html)


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "trie.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<size_t X>
struct AhoCorasick : Trie<X+1>{
  using TRIE = Trie<X+1>;
  using TRIE::TRIE;
  using TRIE::next;
  vector<int> cnt;

  void build(int heavy=true){
    auto &vs=TRIE::vs;
    int n=vs.size();
    cnt.resize(n);
    for(int i=0;i<n;i++){
      if(heavy) sort(vs[i].idxs.begin(),vs[i].idxs.end());
      cnt[i]=vs[i].idxs.size();
    }

    queue<int> que;
    for(int i=0;i<(int)X;i++){
      if(~next(0,i)){
        next(next(0,i),X)=0;
        que.emplace(next(0,i));
      }else{
        next(0,i)=0;
      }
    }

    while(!que.empty()){
      auto &x=vs[que.front()];
      int fail=x.nxt[X];

      cnt[que.front()]+=cnt[fail];
      que.pop();

      for(int i=0;i<(int)X;i++){
        int &nx=x.nxt[i];
        if(nx<0){
          nx=next(fail,i);
          continue;
        }
        que.emplace(nx);
        next(nx,X)=next(fail,i);
        if(heavy){
          auto &idx=vs[nx].idxs;
          auto &idy=vs[next(fail,i)].idxs;
          vector<int> idz;
          set_union(idx.begin(),idx.end(),
                    idy.begin(),idy.end(),
                    back_inserter(idz));
          idx=idz;
        }
      }
    }
  }

  vector<int> match(string s,int heavy=true){
    auto &vs=TRIE::vs;
    vector<int> res(heavy?TRIE::size():1);
    int pos=0;
    for(auto &c:s){
      pos=next(pos,TRIE::conv(c));
      if(heavy) for(auto &x:vs[pos].idxs) res[x]++;
      else res[0]+=cnt[pos];
    }
    return res;
  }

  int count(int pos){
    return cnt[pos];
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "../tools/fixpoint.cpp"
#include "../tools/chminmax.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed SPOJ_BLHETA(){
  string s;
  cin>>s;

  int n;
  cin>>n;
  vector<string> ts(n);
  for(int i=0;i<n;i++)cin>>ts[i];

  auto conv=[](char c){return c-'A';};
  AhoCorasick<26> aho(conv);
  for(int i=0;i<n;i++){
    aho.add(ts[i],i);
  }
  aho.build();

  int l=s.size();
  int pos=0;

  vector<int> vs;
  vs.emplace_back(pos);

  string ans;
  for(int i=0;i<l;i++){
    pos=aho.move(pos,s[i]);
    vs.emplace_back(pos);
    ans+=s[i];
    if(aho.count(pos)){
      int k=aho.vs[pos].idxs[0];
      for(int j=0;j<(int)ts[k].size();j++){
        vs.pop_back();
        pos=vs.back();
        ans.pop_back();
      }
    }
  }

  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/11/14
  https://www.spoj.com/problems/BLHETA/
*/

signed JSC2019_FINAL_E(){
  using ll = long long;

  int n,q,x,y;
  cin>>n>>q>>x>>y;
  vector<string> ss(n);
  for(int i=0;i<n;i++) cin>>ss[i];

  auto f=[&](char c){return c-'a';};
  AhoCorasick<26> aho(f);

  for(int i=0;i<n;i++)
    aho.add(ss[i],i);

  int m=aho.vs.size();
  vector< vector<int> > G(m);
  for(int i=0;i<m;i++)
    for(int j=0;j<26;j++)
      if(~aho.vs[i].nxt[j])
        G[i].emplace_back(aho.vs[i].nxt[j]);

  aho.build();

  const ll INF = 1e17;
  vector<ll> dp(m,INF),dep(m,0);
  MFP([&](auto dfs,int v)->void{
        if(~aho.idx(v)) dp[v]=0;
        for(int u:G[v]){
          dep[u]=dep[v]+1;
          dfs(u);
          chmin(dp[v],dp[u]+y);
        }
      })(0);

  queue<int> que;
  que.emplace(0);
  while(!que.empty()){
    int v=que.front();que.pop();
    for(int u:G[v]) que.emplace(u);

    int f=aho.next(v,26);
    if(~f) chmin(dp[v],dp[f]+(dep[v]-dep[f])*x);
  }

  for(int i=0;i<q;i++){
    string t;
    cin>>t;
    ll pos=0,len=t.size();
    ll ans=dp[0]+len*x;
    for(char c:t){
      pos=aho.move(pos,c);
      chmin(ans,dp[pos]+(len-dep[pos])*x);
    }
    cout<<ans<<"\n";
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/11/14
  https://atcoder.jp/contests/jsc2019-final/tasks/jsc2019_final_e
*/

signed main(){
  //SPOJ_BLHETA();
  //JSC2019_FINAL_E();
  return 0;
}
#endif

```
{% endraw %}

[Back to top page](../../index.html)

