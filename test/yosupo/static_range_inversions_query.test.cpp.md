---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algorithm/mo.cpp
    title: algorithm/mo.cpp
  - icon: ':question:'
    path: datastructure/binaryindexedtree.cpp
    title: Binary Indexed Tree
  - icon: ':question:'
    path: io/single.cpp
    title: io/single.cpp
  - icon: ':question:'
    path: vector/compress.cpp
    title: vector/compress.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/yosupo/static_range_inversions_query.test.cpp\"\n//\
    \ verification-helper: PROBLEM https://judge.yosupo.jp/problem/static_range_inversions_query\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line\
    \ 1 \"io/single.cpp\"\n\n#line 3 \"io/single.cpp\"\nusing namespace std;\n#endif\n\
    \n//BEGIN CUT HERE\ntemplate<typename T=int>\nvector<T> read(size_t n){\n  vector<T>\
    \ ts(n);\n  for(size_t i=0;i<n;i++) cin>>ts[i];\n  return ts;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n#line 1 \"vector/compress.cpp\"\
    \n\n#line 3 \"vector/compress.cpp\"\nusing namespace std;\n#endif\n\n//BEGIN CUT\
    \ HERE\ntemplate<typename V>\nV compress(V vs){\n  sort(vs.begin(),vs.end());\n\
    \  vs.erase(unique(vs.begin(),vs.end()),vs.end());\n  return vs;\n}\ntemplate<typename\
    \ T>\nmap<T, int> dict(const vector<T> &vs){\n  map<T, int> res;\n  for(int i=0;i<(int)vs.size();i++)\n\
    \    res[vs[i]]=i;\n  return res;\n}\nmap<char, int> dict(const string &s){\n\
    \  return dict(vector<char>(s.begin(),s.end()));\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 1 \"algorithm/mo.cpp\"\
    \n\n#line 3 \"algorithm/mo.cpp\"\nusing namespace std;\n#endif\n//BEGIN CUT HERE\n\
    struct Mo{\n  using F = function<void(int)>;\n  vector<int> ls,rs,ord;\n  int\
    \ n,width,nl,nr,ptr;\n  F expandL,expandR;\n  F shrinkL,shrinkR;\n\n  Mo(int n,int\
    \ width,F expandL,F expandR,F shrinkL,F shrinkR):\n    n(n),width(width),nl(0),nr(0),ptr(0),\n\
    \    expandL(expandL),expandR(expandR),\n    shrinkL(shrinkL),shrinkR(shrinkR){}\n\
    \n  Mo(int n,int width,F expand,F shrink):\n    Mo(n,width,expand,expand,shrink,shrink){}\n\
    \n  void add(int l,int r){\n    ls.emplace_back(l);\n    rs.emplace_back(r);\n\
    \  }\n\n  void build(){\n    ord.resize(ls.size());\n    iota(ord.begin(),ord.end(),0);\n\
    \    sort(ord.begin(),ord.end(),\n         [&](int a,int b){\n           if(ls[a]/width!=ls[b]/width)\
    \ return ls[a]<ls[b];\n           if(rs[a]==rs[b]) return ls[a]<ls[b];\n     \
    \      return bool((rs[a]<rs[b])^((ls[a]/width)&1));\n         });\n  }\n\n  int\
    \ process(){\n    if(ptr==(int)ord.size()) return -1;\n    const int idx=ord[ptr++];\n\
    \    while(nl>ls[idx]) expandL(--nl);\n    while(nr<rs[idx]) expandR(nr++);\n\
    \    while(nl<ls[idx]) shrinkL(nl++);\n    while(nr>rs[idx]) shrinkR(--nr);\n\
    \    return idx;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n#line 1 \"datastructure/binaryindexedtree.cpp\"\n\n#line\
    \ 3 \"datastructure/binaryindexedtree.cpp\"\nusing namespace std;\n#endif\n\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nclass BIT{\nprivate:\n  // \\sum_{j <\
    \ i}  v[j]\n  T sum(int i){\n    T s(0);\n    for(int x=i;x>0;x-=(x&-x))\n   \
    \   s+=bit[x];\n    return s;\n  }\npublic:\n  int n;\n  vector<T> bit;\n  BIT(int\
    \ n_):n(n_+1),bit(n+1,0){}\n\n  // v[i] += a\n  void add(int i,T a){\n    for(int\
    \ x=++i;x<=n;x+=(x&-x))\n      bit[x]+=a;\n  }\n  // \\sum_{l <= i < r} v[i]\n\
    \  T query(int l,int r){return sum(r)-sum(l);}\n\n  // min({x | sum(x) >= w})\n\
    \  int lower_bound(const T w){\n    if(w<=0) return 0;\n    T r=w;\n    int x=0,p=1;\n\
    \    while(p<n) p<<=1;\n    for(int k=p;k>0;k>>=1){\n      if(x+k<=n and bit[x+k]<r){\n\
    \        r-=bit[x+k];\n        x+=k;\n      }\n    }\n    x++;\n    assert(sum(x-1)<w\
    \ and sum(x)>=w);\n    return x;\n  }\n\n  // min({x | sum(x) > w})\n  int upper_bound(T\
    \ w){return lower_bound(w+1);}\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n#line 11 \"test/yosupo/static_range_inversions_query.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n  auto as=read(n);\n  auto dc=dict(compress(as));\n\
    \  vector<int> cs(n);\n  for(int i=0;i<n;i++) cs[i]=dc[as[i]];\n\n  using ll =\
    \ long long;\n  ll res=0;\n  vector<ll> ans(q);\n  BIT<int> bit(n);\n  auto expandL=[&](int\
    \ i){bit.add(cs[i],+1);res+=bit.query(0,cs[i]);};\n  auto expandR=[&](int i){bit.add(cs[i],+1);res+=bit.query(cs[i]+1,n);};\n\
    \  auto shrinkL=[&](int i){bit.add(cs[i],-1);res-=bit.query(0,cs[i]);};\n  auto\
    \ shrinkR=[&](int i){bit.add(cs[i],-1);res-=bit.query(cs[i]+1,n);};\n\n  Mo mo(n,400,expandL,expandR,shrinkL,shrinkR);\n\
    \  for(int i=0;i<q;i++){\n    int l,r;\n    cin>>l>>r;\n    mo.add(l,r);\n  }\n\
    \  mo.build();\n\n  for(int i=0;i<q;i++){\n    int k=mo.process();\n    ans[k]=res;\n\
    \  }\n\n  for(auto a:ans) cout<<a<<'\\n';\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/static_range_inversions_query\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../io/single.cpp\"\n#include \"../../vector/compress.cpp\"\n#include \"\
    ../../algorithm/mo.cpp\"\n#include \"../../datastructure/binaryindexedtree.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,q;\n  cin>>n>>q;\n  auto as=read(n);\n  auto dc=dict(compress(as));\n\
    \  vector<int> cs(n);\n  for(int i=0;i<n;i++) cs[i]=dc[as[i]];\n\n  using ll =\
    \ long long;\n  ll res=0;\n  vector<ll> ans(q);\n  BIT<int> bit(n);\n  auto expandL=[&](int\
    \ i){bit.add(cs[i],+1);res+=bit.query(0,cs[i]);};\n  auto expandR=[&](int i){bit.add(cs[i],+1);res+=bit.query(cs[i]+1,n);};\n\
    \  auto shrinkL=[&](int i){bit.add(cs[i],-1);res-=bit.query(0,cs[i]);};\n  auto\
    \ shrinkR=[&](int i){bit.add(cs[i],-1);res-=bit.query(cs[i]+1,n);};\n\n  Mo mo(n,400,expandL,expandR,shrinkL,shrinkR);\n\
    \  for(int i=0;i<q;i++){\n    int l,r;\n    cin>>l>>r;\n    mo.add(l,r);\n  }\n\
    \  mo.build();\n\n  for(int i=0;i<q;i++){\n    int k=mo.process();\n    ans[k]=res;\n\
    \  }\n\n  for(auto a:ans) cout<<a<<'\\n';\n  return 0;\n}\n"
  dependsOn:
  - io/single.cpp
  - vector/compress.cpp
  - algorithm/mo.cpp
  - datastructure/binaryindexedtree.cpp
  isVerificationFile: true
  path: test/yosupo/static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:55:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_inversions_query.test.cpp
- /verify/test/yosupo/static_range_inversions_query.test.cpp.html
title: test/yosupo/static_range_inversions_query.test.cpp
---
