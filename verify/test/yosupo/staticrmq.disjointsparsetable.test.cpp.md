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


# :heavy_check_mark: test/yosupo/staticrmq.disjointsparsetable.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/staticrmq.disjointsparsetable.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-05 21:02:53+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/datastructure/disjointsparsetable.cpp.html">datastructure/disjointsparsetable.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/disjointsparsetable.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto f=[](int a,int b){return min(a,b);};
  DisjointSparseTable<int> rmq(f);
  rmq.build(as);

  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    cout<<rmq.query(l,r)<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/staticrmq.disjointsparsetable.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "datastructure/disjointsparsetable.cpp"

#line 3 "datastructure/disjointsparsetable.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct DisjointSparseTable{
  using F = function<T(T, T)>;
  vector< vector<T> > dat;
  vector<int> ht;
  const F f;

  DisjointSparseTable(){}
  DisjointSparseTable(F f):f(f){}

  void build(const vector<T> &vs){
    int n=vs.size(),h=1;
    while((1<<h)<=n) h++;
    dat.assign(h,vector<T>(n));
    ht.assign((1<<h)+1,0);
    for(int j=2;j<(1<<h)+1;j++) ht[j]=ht[j>>1]+1;

    for(int j=0;j<n;j++) dat[0][j]=vs[j];
    for(int i=1;i<h;i++){
      int s=1<<i;
      for(int j=0;j<n;j+=s<<1){
        int t=min(j+s,n);
        dat[i][t-1]=vs[t-1];
        for(int k=t-2;k>=j;k--) dat[i][k]=f(vs[k],dat[i][k+1]);
        if(n<=t) break;
        dat[i][t]=vs[t];
        int r=min(t+s,n);
        for(int k=t+1;k<r;k++) dat[i][k]=f(dat[i][k-1],vs[k]);
      }
    }
  }

  T query(int l,int r){
    if(l>=--r) return dat[0][l];
    return f(dat[ht[l^r]][l],dat[ht[l^r]][r]);
  }

};
//END CUT HERE
#ifndef call_from_test

// find with non-idempotent monoid
signed CODECHEF_SEGPROD(){
  int T;
  scanf("%d",&T);

  int p;
  auto f=[&](int a,int b)->int{return (long long)a*b%p;};
  DisjointSparseTable<int> dst(f);

  for(int t=1;t<=T;t++){
    int n,q;
    scanf("%d %d %d",&n,&p,&q);
    vector<int> v(n);
    for(int i=0;i<n;i++) scanf("%d",&v[i]),v[i]%=p;
    vector<int> b(q/64+2);
    for(int i=0;i<(q/64+2);i++) scanf("%d",&b[i]);

    dst.build(v);

    int x=0,l=0,r=0;
    for(int i=0;i<q;i++){
      if(i%64==0){
        l=(b[i/64]+x)%n;
        r=(b[i/64+1]+x)%n;
      }else{
        l=(l+x)%n;
        r=(r+x)%n;
      }
      if(l>r) swap(l,r);
      x=dst.query(l,r+1)+1;
      if(x>=p) x-=p;
    }
    printf("%d\n",x);
  }
  return 0;
}
/*
  verified on 2019/10/29
  https://www.codechef.com/problems/SEGPROD
*/

//INSERT ABOVE HERE
signed main(){
  //CODECHEF_SEGPROD();
  return 0;
}
#endif
#line 8 "test/yosupo/staticrmq.disjointsparsetable.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto f=[](int a,int b){return min(a,b);};
  DisjointSparseTable<int> rmq(f);
  rmq.build(as);

  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    cout<<rmq.query(l,r)<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

