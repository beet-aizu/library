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


# :heavy_check_mark: test/aoj/GRL_5_C.lca.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_5_C.lca.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 21:09:31+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/tools/fastio.cpp.html">tools/fastio.cpp</a>
* :heavy_check_mark: <a href="../../../library/tree/lca.cpp.html">tree/lca.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../tree/lca.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;
  LCA lca(n);
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int c;
      cin>>c;
      lca.add_edge(i,c);
    }
  }
  lca.build();

  int q;
  cin>>q;
  while(q--){
    int u,v;
    cin>>u>>v;
    cout<<lca.lca(u,v)<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_5_C.lca.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "test/aoj/../../tools/fastio.cpp"

#line 3 "test/aoj/../../tools/fastio.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
#line 1 "test/aoj/../../tree/lca.cpp"

#line 3 "test/aoj/../../tree/lca.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
struct LCA{
  const int lg = 12;
  const int sz = 1<<lg;
  const int ms = sz-1;
  int n;
  vector<int> P,D,E,A,B,T,ht;
  vector<vector<int> > G,dat;
  LCA(int n):
    n(n),P(n,-1),D(n),E(n*2,0),A(n*2,-1),B(n*2/lg+1),T(sz,0),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void dfs(int v,int p,int d){
    int k=0,u;
    vector<int> iter(n,0);

    using T = tuple<int, int, int>;
    stack<T> st;

  START:
    D[v]=k;
    A[k]=P[v]=p;
    E[k++]=d;
    for(;iter[v]<(int)G[v].size();iter[v]++){
      u=G[v][iter[v]];
      if(u==p) continue;
      st.emplace(v,p,d);
      p=v;v=u;d=d+1;
      goto START;
    END:
      tie(v,p,d)=st.top();st.pop();
    }

    A[k]=P[v];
    E[k++]=d-1;

    if(!st.empty()) goto END;
  }

  // if it need leftmost, then add: if(E[i]==E[j]) return i<j?i:j;
  inline int comp(int i,int j){return E[i]<E[j]?i:j;};
  inline int comp(int i,int j,int k){return comp(comp(i,j),k);};

  void build(int r=0){
    dfs(r,-1,1);

    B[0]=1;
    for(int i=1;i<n*2;i++) B[i/lg]|=(E[i-1]<E[i])<<(i%lg);

    for(int b=0;b<sz;b++){
      int e=0,w=1,&x=T[b];
      for(int i=0;i<lg;i++){
        if((b>>i)&1) e++;
        else e--;
        if(e<w) e=w,x=i;
      }
    }

    int m=(n*2+lg-1)/lg;
    int h=1;
    while((1<<h)<m) h++;
    dat.assign(h,vector<int>(m,-1));
    ht.assign(m+1,0);
    for(int j=2;j<=m;j++) ht[j]=ht[j>>1]+1;

    for(int j=0;j<n*2;j++){
      if(dat[0][j/lg]<0) dat[0][j/lg]=j;
      dat[0][j/lg]=comp(dat[0][j/lg],j);
    }

    for(int i=1,p=1;i<h;i++,p<<=1)
      for(int j=0;j<m;j++)
        dat[i][j]=comp(dat[i-1][j],dat[i-1][min(j+p,m-1)]);
  }

  inline int cs(int a,int b){
    int l=b-a;
    return comp(dat[ht[l]][a],dat[ht[l]][b-(1<<ht[l])]);
  }

  inline int es(int i,int l,int r){
    int x=r-i*lg+1,y=l-i*lg;
    int b=(((B[i]|(ms<<x))>>y)|(ms<<(lg-y)))&ms;
    return l+T[b];
  }

  inline int ls(int i,int l){
    int k=l-i*lg;
    int b=((B[i]>>k)|(ms<<(lg-k)))&ms;
    return l+T[b];
  }

  inline int rs(int j,int r){
    int k=r-j*lg+1;
    int b=(B[j]|(ms<<k))&ms;
    return j*lg+T[b];
  }

  inline int rmq(int l,int r){
    int i=l/lg,j=r/lg;
    if(i==j) return es(i,l,r);
    if(i+1==j) return comp(ls(i,l),rs(j,r));
    return comp(ls(i,l),cs(i+1,j),rs(j,r));
  }

  int lca(int l,int r){
    if(l==r) return l;
    if(D[l]>D[r]) swap(l,r);
    int x=D[l],y=D[r];
    int m=rmq(x,y);
    return m==x?l:A[m];
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
#line 9 "test/aoj/GRL_5_C.lca.test.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;
  LCA lca(n);
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int c;
      cin>>c;
      lca.add_edge(i,c);
    }
  }
  lca.build();

  int q;
  cin>>q;
  while(q--){
    int u,v;
    cin>>u>>v;
    cout<<lca.lca(u,v)<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

