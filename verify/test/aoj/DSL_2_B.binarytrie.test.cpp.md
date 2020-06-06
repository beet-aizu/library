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


# :heavy_check_mark: test/aoj/DSL_2_B.binarytrie.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_B.binarytrie.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-06 14:04:57+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/datastructure/binarytrie.cpp.html">datastructure/binarytrie.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/binarytrie.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  BinaryTrie<int, 30> bt;
  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c==0){
      bt.add(x,y);
    }
    if(c==1){
      int res=bt.order_of_key(y+1)-bt.order_of_key(x);
      cout<<res<<"\n";
    }
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_B.binarytrie.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 2 "datastructure/binarytrie.cpp"

#ifndef call_from_test
#line 5 "datastructure/binarytrie.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T,size_t X>
struct BinaryTrie{
  struct Node{
    size_t cnt;
    Node *p,*l,*r;
    Node(Node* p):cnt(0),p(p){l=r=nullptr;}
  };

  T acc;
  Node *root;
  BinaryTrie():acc(0){root=emplace(nullptr);}

  void clear(Node *a){
    if(!a) return;
    clear(a->l);clear(a->r);
    delete(a);
  }

  inline Node* emplace(Node* p){
    return new Node(p);
  }

  inline size_t count(Node* a){
    return a?a->cnt:0;
  }

  void add(const T b,size_t k=1){
    const T nb=b^acc;
    Node* a=root;
    for(int i=X-1;i>=0;i--){
      bool f=(nb>>i)&1;
      if(!f&&!a->l) a->l=emplace(a);
      if( f&&!a->r) a->r=emplace(a);
      a=f?a->r:a->l;
    }
    a->cnt+=k;
    while((a=a->p)) a->cnt=count(a->l)+count(a->r);
  }

  inline void update(const T b){acc^=b;}

  Node* find(const T b){
    const T nb=b^acc;
    Node* a=root;
    for(int i=X-1;i>=0;i--){
      bool f=(nb>>i)&1;
      a=f?a->r:a->l;
      if(!a) return a;
    }
    return a;
  }

  Node* check(Node *a){
    if(!a||count(a)) return a;
    delete(a);
    return nullptr;
  }

  void sub(Node* a,size_t k=1){
    assert(a&&a->cnt>=k);
    a->cnt-=k;
    while((a=a->p)){
      a->l=check(a->l);
      a->r=check(a->r);
      a->cnt=count(a->l)+count(a->r);
    }
  }

  Node* xmax(const T b){
    assert(count(root));
    const T nb=b^acc;
    Node* a=root;
    for(int i=X-1;i>=0;i--){
      bool f=(nb>>i)&1;
      if(!a->l||!a->r) a=a->l?a->l:a->r;
      else a=f?a->l:a->r;
    }
    return a;
  }

  Node* xmin(const T b){
    return xmax(~b&((T(1)<<X)-1));
  }

  Node* ge(Node *a,int i){
    if(!a) return a;
    Node *l=a->l,*r=a->r;
    if((acc>>i)&1) swap(l,r);
    if(l||r) return ge(l?l:r,i+1);
    return a;
  }

  Node* next(Node* a,int i){
    if(!(a->p)) return nullptr;
    Node *l=a->p->l,*r=a->p->r;
    if((acc>>(i+1))&1) swap(l,r);
    if(a==l&&r) return ge(r,i);
    return next(a->p,i+1);
  }

  Node* lower_bound(const T b){
    const T nb=b^acc;
    Node* a=root;
    for(int i=X-1;i>=0;i--){
      bool f=(nb>>i)&1;
      if(!f&&a->l){a=a->l;continue;}
      if( f&&a->r){a=a->r;continue;}
      if((b>>i)&1) return next(a,i);
      return ge(a,i);
    }
    return a;
  }

  Node* upper_bound(const T b){
    return lower_bound(b+1);
  }

  T val(Node* a){
    T res(0);
    for(int i=0;i<(int)X;i++){
      assert(a->p);
      res|=(T(a==a->p->r)<<i);
      a=a->p;
    }
    return res^acc;
  }

  Node* find_by_order(size_t k){
    Node *a=root;
    if(count(a)<=k) return nullptr;
    for(int i=X-1;i>=0;i--){
      bool f=(acc>>i)&1;
      if(count(f?a->r:a->l)<=k){
        k-=count(f?a->r:a->l);
        a=f?a->l:a->r;
      }else{
        a=f?a->r:a->l;
      }
    }
    return a;
  }

  size_t order_of_key(const T b){
    Node *a=root;
    size_t res=0;
    for(int i=X-1;i>=0;i--){
      Node *l=a->l,*r=a->r;
      if((acc>>i)&1) swap(l,r);
      bool f=(b>>i)&1;
      if(f) res+=count(l);
      a=f?r:l;
      if(!a) break;
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test

// find_by_order (weak)
signed ARC033_C(){
  int q;
  scanf("%d",&q);
  BinaryTrie<int, 30> bt;
  while(q--){
    int t,x;
    scanf("%d %d",&t,&x);
    if(t==1) bt.add(x);
    if(t==2){
      auto k=bt.find_by_order(x-1);
      printf("%d\n",bt.val(k));
      bt.sub(k);
    }
  }
  return 0;
}
/*
  verified on 2020/06/06
  https://atcoder.jp/contests/arc033/tasks/arc033_3
*/

// upper_bound
signed CFR477_C(){
  using ll = long long;

  int n;
  scanf("%d",&n);
  vector<ll> bs(n);
  for(int i=0;i<n;i++) scanf("%lld",&bs[i]);

  BinaryTrie<ll, 61> bt;
  for(int i=0;i<n;i++) bt.add(bs[i]);

  ll z=0;
  auto apply=[&](ll a){
    z^=a;
    bt.update(a);
  };

  vector<ll> ans;
  ll x=bt.val(bt.xmin(0));

  ans.emplace_back(x);
  bt.sub(bt.find(x));
  apply(x);

  for(int i=1;i<n;i++){
    if(bt.val(bt.xmax(0))<=x){
      printf("No\n");
      return 0;
    }
    auto nxt=bt.upper_bound(x);
    ll y=bt.val(nxt);

    ans.emplace_back(y^z);
    bt.sub(nxt);
    apply(x^y);
    x=y;
  }

  printf("Yes\n");
  for(int i=0;i<n;i++){
    if(i) printf(" ");
    printf("%lld",ans[i]);
  }
  puts("");
  return 0;
}
/*
  verified on 2020/06/06
  http://codeforces.com/contest/966/problem/C
*/

signed main(){
  //ARC033_C();
  //CFR477_C();
  return 0;
}
#endif
#line 8 "test/aoj/DSL_2_B.binarytrie.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  BinaryTrie<int, 30> bt;
  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c==0){
      bt.add(x,y);
    }
    if(c==1){
      int res=bt.order_of_key(y+1)-bt.order_of_key(x);
      cout<<res<<"\n";
    }
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

