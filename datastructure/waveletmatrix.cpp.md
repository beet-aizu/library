---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/waveletmatrix.md
  bundledCode: "#line 1 \"datastructure/waveletmatrix.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n/**\n * @docs docs/waveletmatrix.md\n */\n//BEGIN\
    \ CUT HERE\nstruct FullyIndexableDictionary{\n  int len,blk;\n  vector<unsigned>\
    \ bit;\n  vector<int> sum;\n\n  FullyIndexableDictionary(){}\n  FullyIndexableDictionary(int\
    \ len)\n    :len(len),blk((len+31)>>5),bit(blk,0),sum(blk,0){}\n\n  void set(int\
    \ k){\n    bit[k>>5]|=1u<<(k&31);\n  }\n\n  void build(){\n    sum[0]=0;\n   \
    \ for(int i=1;i<blk;i++)\n      sum[i]=sum[i-1]+__builtin_popcount(bit[i-1]);\n\
    \  }\n\n  bool operator[](int k) const{\n    return bool((bit[k>>5]>>(k&31))&1);\n\
    \  }\n\n  int rank(int k){\n    return sum[k>>5]+__builtin_popcount(bit[k>>5]&((1u<<(k&31))-1));\n\
    \  }\n\n  int rank(bool v,int k){\n    return (v?rank(k):k-rank(k));\n  }\n\n\
    \  int select(bool v,int k){\n    if(k<0||rank(v,len)<=k) return -1;\n    int\
    \ l=0,r=len;\n    while(l+1<r){\n      int m=(l+r)>>1;\n      if(rank(v,m)>=k+1)\
    \ r=m;\n      else l=m;\n    }\n    return r-1;\n  }\n\n  int select(bool v,int\
    \ i,int l){\n    return select(v,i+rank(v,l));\n  }\n};\n\ntemplate<class T,int\
    \ MAXLOG>\nstruct WaveletMatrix{\n  int len;\n  FullyIndexableDictionary mat[MAXLOG];\n\
    \  int zs[MAXLOG],buff1[MAXLOG],buff2[MAXLOG];\n  static const T npos=-1;\n\n\
    \  WaveletMatrix(vector<T> data){\n    len=data.size();\n    vector<T> ls(len),rs(len);\n\
    \    for(int dep=0;dep<MAXLOG;dep++){\n      mat[dep]=FullyIndexableDictionary(len+1);\n\
    \      int p=0,q=0;\n      for(int i=0;i<len;i++){\n        bool k=(data[i]>>(MAXLOG-(dep+1)))&1;\n\
    \        if(k) rs[q++]=data[i],mat[dep].set(i);\n        else  ls[p++]=data[i];\n\
    \      }\n      zs[dep]=p;\n      mat[dep].build();\n      swap(ls,data);\n  \
    \    for(int i=0;i<q;i++) data[p+i]=rs[i];\n    }\n  }\n\n  T access(int k){\n\
    \    T res=0;\n    for(int dep=0;dep<MAXLOG;dep++){\n      bool bit=mat[dep][k];\n\
    \      res=(res<<1)|bit;\n      k=mat[dep].rank(bit,k)+zs[dep]*dep;\n    }\n \
    \   return res;\n  }\n\n  // return the number of v in [0,k)\n  int rank(T v,int\
    \ k){\n    int l=0,r=k;\n    for(int dep=0;dep<MAXLOG;dep++){\n      buff1[dep]=l;buff2[dep]=r;\n\
    \      bool bit=(v>>(MAXLOG-(dep+1)))&1;\n      l=mat[dep].rank(bit,l)+zs[dep]*bit;\n\
    \      r=mat[dep].rank(bit,r)+zs[dep]*bit;\n    }\n    return r-l;\n  }\n\n  //\
    \ return the position of k-th v\n  int select(T v,int k){\n    rank(v,len);\n\
    \    for(int dep=MAXLOG-1;dep>=0;dep--){\n      bool bit=(v>>(MAXLOG-(dep+1)))&1;\n\
    \      k=mat[dep].select(bit,k,buff1[dep]);\n      if(k>=buff2[dep]||k<0) return\
    \ -1;\n      k-=buff1[dep];\n    }\n    return k;\n  }\n\n  int select(T v,int\
    \ k,int l){\n    return select(v,k+rank(v,l));\n  }\n\n  // return k-th largest\
    \ value in [l,r)\n  T quantile(int l,int r,int k){\n    if(r-l<=k||k<0) return\
    \ -1;\n    T res=0;\n    for(int dep=0;dep<MAXLOG;dep++){\n      int p=mat[dep].rank(1,l);\n\
    \      int q=mat[dep].rank(1,r);\n      if(q-p>k){\n        l=p+zs[dep];\n   \
    \     r=q+zs[dep];\n        res|=T(1)<<(MAXLOG-(dep+1));\n      }else{\n     \
    \   k-=(q-p);\n        l-=p;\n        r-=q;\n      }\n    }\n    return res;\n\
    \  }\n\n  T rquantile(int l,int r,int k){\n    return quantile(l,r,r-l-k-1);\n\
    \  }\n\n  int freq_dfs(int d,int l,int r,T val,T a,T b){\n    if(l==r) return\
    \ 0;\n    if(d==MAXLOG) return (a<=val&&val<b)?r-l:0;\n    T nv=T(1)<<(MAXLOG-d-1)|val;\n\
    \    T nnv=((T(1)<<(MAXLOG-d-1))-1)|nv;\n    if(nnv<a||b<=val) return 0;\n   \
    \ if(a<=val&&nnv<b) return r-l;\n    int lc=mat[d].rank(1,l),rc=mat[d].rank(1,r);\n\
    \    return freq_dfs(d+1,l-lc,r-rc,val,a,b)\n      +freq_dfs(d+1,lc+zs[d],rc+zs[d],nv,a,b);\n\
    \  }\n\n  // return number of points in [left, right) * [lower, upper)\n  int\
    \ rangefreq(int left,int right,T lower,T upper){\n    return freq_dfs(0,left,right,0,lower,upper);\n\
    \  }\n\n  pair<int, int> ll(int l,int r,T v){\n    int res=0;\n    for(int dep=0;dep<MAXLOG;dep++){\n\
    \      buff1[dep]=l;buff2[dep]=r;\n      bool bit=(v>>(MAXLOG-(dep+1)))&1;\n \
    \     if(bit) res+=r-l+mat[dep].rank(bit,l)-mat[dep].rank(bit,r);\n      l=mat[dep].rank(bit,l)+zs[dep]*bit;\n\
    \      r=mat[dep].rank(bit,r)+zs[dep]*bit;\n    }\n    return make_pair(res,r-l);\n\
    \  }\n\n  int lt(int l,int r,T v){\n    auto p=ll(l,r,v);\n    return p.first;\n\
    \  }\n\n  int le(int l,int r,T v){\n    auto p=ll(l,r,v);\n    return p.first+p.second;\n\
    \  }\n\n  T succ(int l,int r,T v){\n    int k=le(l,r,v);\n    return k==r-l?npos:rquantile(l,r,k);\n\
    \  }\n\n  T pred(int l,int r,T v){\n    int k=lt(l,r,v);\n    return k?rquantile(l,r,k-1):npos;\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    /**\n * @docs docs/waveletmatrix.md\n */\n//BEGIN CUT HERE\nstruct FullyIndexableDictionary{\n\
    \  int len,blk;\n  vector<unsigned> bit;\n  vector<int> sum;\n\n  FullyIndexableDictionary(){}\n\
    \  FullyIndexableDictionary(int len)\n    :len(len),blk((len+31)>>5),bit(blk,0),sum(blk,0){}\n\
    \n  void set(int k){\n    bit[k>>5]|=1u<<(k&31);\n  }\n\n  void build(){\n   \
    \ sum[0]=0;\n    for(int i=1;i<blk;i++)\n      sum[i]=sum[i-1]+__builtin_popcount(bit[i-1]);\n\
    \  }\n\n  bool operator[](int k) const{\n    return bool((bit[k>>5]>>(k&31))&1);\n\
    \  }\n\n  int rank(int k){\n    return sum[k>>5]+__builtin_popcount(bit[k>>5]&((1u<<(k&31))-1));\n\
    \  }\n\n  int rank(bool v,int k){\n    return (v?rank(k):k-rank(k));\n  }\n\n\
    \  int select(bool v,int k){\n    if(k<0||rank(v,len)<=k) return -1;\n    int\
    \ l=0,r=len;\n    while(l+1<r){\n      int m=(l+r)>>1;\n      if(rank(v,m)>=k+1)\
    \ r=m;\n      else l=m;\n    }\n    return r-1;\n  }\n\n  int select(bool v,int\
    \ i,int l){\n    return select(v,i+rank(v,l));\n  }\n};\n\ntemplate<class T,int\
    \ MAXLOG>\nstruct WaveletMatrix{\n  int len;\n  FullyIndexableDictionary mat[MAXLOG];\n\
    \  int zs[MAXLOG],buff1[MAXLOG],buff2[MAXLOG];\n  static const T npos=-1;\n\n\
    \  WaveletMatrix(vector<T> data){\n    len=data.size();\n    vector<T> ls(len),rs(len);\n\
    \    for(int dep=0;dep<MAXLOG;dep++){\n      mat[dep]=FullyIndexableDictionary(len+1);\n\
    \      int p=0,q=0;\n      for(int i=0;i<len;i++){\n        bool k=(data[i]>>(MAXLOG-(dep+1)))&1;\n\
    \        if(k) rs[q++]=data[i],mat[dep].set(i);\n        else  ls[p++]=data[i];\n\
    \      }\n      zs[dep]=p;\n      mat[dep].build();\n      swap(ls,data);\n  \
    \    for(int i=0;i<q;i++) data[p+i]=rs[i];\n    }\n  }\n\n  T access(int k){\n\
    \    T res=0;\n    for(int dep=0;dep<MAXLOG;dep++){\n      bool bit=mat[dep][k];\n\
    \      res=(res<<1)|bit;\n      k=mat[dep].rank(bit,k)+zs[dep]*dep;\n    }\n \
    \   return res;\n  }\n\n  // return the number of v in [0,k)\n  int rank(T v,int\
    \ k){\n    int l=0,r=k;\n    for(int dep=0;dep<MAXLOG;dep++){\n      buff1[dep]=l;buff2[dep]=r;\n\
    \      bool bit=(v>>(MAXLOG-(dep+1)))&1;\n      l=mat[dep].rank(bit,l)+zs[dep]*bit;\n\
    \      r=mat[dep].rank(bit,r)+zs[dep]*bit;\n    }\n    return r-l;\n  }\n\n  //\
    \ return the position of k-th v\n  int select(T v,int k){\n    rank(v,len);\n\
    \    for(int dep=MAXLOG-1;dep>=0;dep--){\n      bool bit=(v>>(MAXLOG-(dep+1)))&1;\n\
    \      k=mat[dep].select(bit,k,buff1[dep]);\n      if(k>=buff2[dep]||k<0) return\
    \ -1;\n      k-=buff1[dep];\n    }\n    return k;\n  }\n\n  int select(T v,int\
    \ k,int l){\n    return select(v,k+rank(v,l));\n  }\n\n  // return k-th largest\
    \ value in [l,r)\n  T quantile(int l,int r,int k){\n    if(r-l<=k||k<0) return\
    \ -1;\n    T res=0;\n    for(int dep=0;dep<MAXLOG;dep++){\n      int p=mat[dep].rank(1,l);\n\
    \      int q=mat[dep].rank(1,r);\n      if(q-p>k){\n        l=p+zs[dep];\n   \
    \     r=q+zs[dep];\n        res|=T(1)<<(MAXLOG-(dep+1));\n      }else{\n     \
    \   k-=(q-p);\n        l-=p;\n        r-=q;\n      }\n    }\n    return res;\n\
    \  }\n\n  T rquantile(int l,int r,int k){\n    return quantile(l,r,r-l-k-1);\n\
    \  }\n\n  int freq_dfs(int d,int l,int r,T val,T a,T b){\n    if(l==r) return\
    \ 0;\n    if(d==MAXLOG) return (a<=val&&val<b)?r-l:0;\n    T nv=T(1)<<(MAXLOG-d-1)|val;\n\
    \    T nnv=((T(1)<<(MAXLOG-d-1))-1)|nv;\n    if(nnv<a||b<=val) return 0;\n   \
    \ if(a<=val&&nnv<b) return r-l;\n    int lc=mat[d].rank(1,l),rc=mat[d].rank(1,r);\n\
    \    return freq_dfs(d+1,l-lc,r-rc,val,a,b)\n      +freq_dfs(d+1,lc+zs[d],rc+zs[d],nv,a,b);\n\
    \  }\n\n  // return number of points in [left, right) * [lower, upper)\n  int\
    \ rangefreq(int left,int right,T lower,T upper){\n    return freq_dfs(0,left,right,0,lower,upper);\n\
    \  }\n\n  pair<int, int> ll(int l,int r,T v){\n    int res=0;\n    for(int dep=0;dep<MAXLOG;dep++){\n\
    \      buff1[dep]=l;buff2[dep]=r;\n      bool bit=(v>>(MAXLOG-(dep+1)))&1;\n \
    \     if(bit) res+=r-l+mat[dep].rank(bit,l)-mat[dep].rank(bit,r);\n      l=mat[dep].rank(bit,l)+zs[dep]*bit;\n\
    \      r=mat[dep].rank(bit,r)+zs[dep]*bit;\n    }\n    return make_pair(res,r-l);\n\
    \  }\n\n  int lt(int l,int r,T v){\n    auto p=ll(l,r,v);\n    return p.first;\n\
    \  }\n\n  int le(int l,int r,T v){\n    auto p=ll(l,r,v);\n    return p.first+p.second;\n\
    \  }\n\n  T succ(int l,int r,T v){\n    int k=le(l,r,v);\n    return k==r-l?npos:rquantile(l,r,k);\n\
    \  }\n\n  T pred(int l,int r,T v){\n    int k=lt(l,r,v);\n    return k?rquantile(l,r,k-1):npos;\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2674.test.cpp
    title: test/aoj/2674.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1549.test.cpp
    title: test/aoj/1549.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3063.test.cpp
    title: test/aoj/3063.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_kth_smallest.test.cpp
    title: test/yosupo/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3227.test.cpp
    title: test/yukicoder/3227.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1732.test.cpp
    title: test/yukicoder/1732.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2147.test.cpp
    title: test/yukicoder/2147.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1937.test.cpp
    title: test/yukicoder/1937.test.cpp
  isVerificationFile: false
  path: datastructure/waveletmatrix.cpp
  requiredBy: []
  timestamp: '2020-02-23 20:10:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/2674.test.cpp
  - test/aoj/1549.test.cpp
  - test/aoj/3063.test.cpp
  - test/yosupo/range_kth_smallest.test.cpp
  - test/yukicoder/3227.test.cpp
  - test/yukicoder/1732.test.cpp
  - test/yukicoder/2147.test.cpp
  - test/yukicoder/1937.test.cpp
documentation_of: datastructure/waveletmatrix.cpp
layout: document
redirect_from:
- /library/datastructure/waveletmatrix.cpp
- /library/datastructure/waveletmatrix.cpp.html
title: datastructure/waveletmatrix.cpp
---

## できること
- rank
-- $\lbrack 0, k)$ に含まれる $v$ の個数を求める
- select
-- $k$ 番目の $v$ の位置を求める
- quantile
-- $\lbrack l, r)$ に含まれる要素の中で $k$ 番目に大きいものを求める
- rquantile
-- $\lbrack l, r)$ に含まれる要素の中で $k$ 番目に小さいものを求める
- rangefreq
-- $\vert \lbrace i \mid i \in \lbrack l, r), x _ i \in \lbrack d, u) \rbrace \vert$ を求める
- succ
-- $\lbrack l, r)$ に含まれる要素の中で $v$ の次に大きいものを求める
- pred
-- $\lbrack l, r)$ に含まれる要素の中で $v$ の次に小さいものを求める

## verify 用問題一覧
- rank
-- 募集中
- select
-- 募集中
- quantile
-- [yukicoder 1732](https://yukicoder.me/problems/1732)
- rquantile
-- [Library-Checker Range Kth Smallest](https://judge.yosupo.jp/problem/range_kth_smallest)
- rangefreq
-- [yukicoder 1937](https://yukicoder.me/problems/1937)
- succ, pred
-- [AOJ 1549](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549)
