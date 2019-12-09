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


# :warning: bbst/pb_ds_tree.cpp
* category: bbst


[Back to top page](../../index.html)



## Code
{% raw %}
```cpp
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
template <typename T>
using gtree = tree<T,null_type,less<T>,rb_tree_tag,
                   tree_order_statistics_node_update>;
// usage:
// find_by_order(int k):
// return the iterator of k-th smallest element (0-indexed)
// order_of_key(T key):  return the index of key in tree
//END CUT HERE

signed ARC028_B(){
  int n,k;
  cin>>n>>k;
  int x[n];
  for(int i=0;i<n;i++) cin>>x[i];
  map<int,int> m;
  for(int i=0;i<n;i++) m[x[i]]=i+1;
  gtree<Int> G;
  for(int i=0;i<k-1;i++) G.insert(x[i]);
  for(int i=k-1;i<n;i++){
    G.insert(x[i]);
    Int key=*G.find_by_order(k-1);
    cout<<m[key]<<endl;
  }
  return 0;
}

/*
  verified on 2017/12/31
  http://arc028.contest.atcoder.jp/tasks/arc028_2
*/

signed ARC033_C(){
  int q;
  cin>>q;
  gtree<int> G;
  while(q--){
    int t,x;
    cin>>t>>x;
    if(t==1) G.insert(x);
    if(t==2){
      int k=*G.find_by_order(x-1);
      G.erase(k);
      cout<<k<<endl;
    }
  }
  return 0;
}

/*
  verified on 2017/12/31
  https://beta.atcoder.jp/contests/arc033/tasks/arc033_3
*/

signed main(){
  ARC028_B();
  //ARC033_C();
  return 0;
}

```
{% endraw %}

[Back to top page](../../index.html)

