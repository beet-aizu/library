---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2842.test.cpp
    title: test/aoj/2842.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_rectangle_sum.test.cpp
    title: test/yosupo/point_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rectangle_sum.test.cpp
    title: test/yosupo/rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2063.test.cpp
    title: test/yukicoder/2063.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/count/dynamic_offline.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename Key,typename\
    \ T>\nstruct RangeCount{\n  struct BIT{\n    vector<T> dat;\n    BIT(int n){dat.assign(++n,0);}\n\
    \    T sum(int k){\n      T res=0;\n      for(;k;k-=k&-k) res+=dat[k];\n     \
    \ return res;\n    }\n    void add(int k,T v){\n      for(++k;k<(int)dat.size();k+=k&-k)\
    \ dat[k]+=v;\n    }\n  };\n  int n;\n  vector< vector<Key> > val;\n  vector<BIT>\
    \ dat;\n  RangeCount(int n):n(n){\n    val.assign(n<<1,vector<Key>());\n    dat.reserve(n<<1);\n\
    \  }\n  void preupdate(int a,Key x){\n    a+=n;\n    while(a){\n      val[a].emplace_back(x);\n\
    \      a>>=1;\n    }\n  }\n  void build(){\n    for(int i=0;i<n*2;i++){\n    \
    \  auto &vs=val[i];\n      sort(vs.begin(),vs.end());\n      vs.erase(unique(vs.begin(),vs.end()),vs.end());\n\
    \      dat.emplace_back(vs.size());\n    }\n  }\n  void update(int a,Key x,T z){\n\
    \    a+=n;\n    while(a){\n      auto &vs=val[a];\n      int k=lower_bound(vs.begin(),vs.end(),x)-vs.begin();\n\
    \      dat[a].add(k,z);\n      a>>=1;\n    }\n  }\n  T calc(int k,Key x,Key y){\n\
    \    auto &vs=val[k];\n    int p=lower_bound(vs.begin(),vs.end(),x)-vs.begin();\n\
    \    int q=lower_bound(vs.begin(),vs.end(),y)-vs.begin();\n    return dat[k].sum(q)-dat[k].sum(p);\n\
    \  }\n  // [a, b) * [x, y)\n  T query(int a,int b,Key x,Key y){\n    T res=0;\n\
    \    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){\n      if(l&1) res+=calc(l++,x,y);\n\
    \      if(r&1) res+=calc(--r,x,y);\n    }\n    return res;\n  }\n};\n//END CUT\
    \ HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n//END CUT HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename Key,typename T>\nstruct RangeCount{\n  struct\
    \ BIT{\n    vector<T> dat;\n    BIT(int n){dat.assign(++n,0);}\n    T sum(int\
    \ k){\n      T res=0;\n      for(;k;k-=k&-k) res+=dat[k];\n      return res;\n\
    \    }\n    void add(int k,T v){\n      for(++k;k<(int)dat.size();k+=k&-k) dat[k]+=v;\n\
    \    }\n  };\n  int n;\n  vector< vector<Key> > val;\n  vector<BIT> dat;\n  RangeCount(int\
    \ n):n(n){\n    val.assign(n<<1,vector<Key>());\n    dat.reserve(n<<1);\n  }\n\
    \  void preupdate(int a,Key x){\n    a+=n;\n    while(a){\n      val[a].emplace_back(x);\n\
    \      a>>=1;\n    }\n  }\n  void build(){\n    for(int i=0;i<n*2;i++){\n    \
    \  auto &vs=val[i];\n      sort(vs.begin(),vs.end());\n      vs.erase(unique(vs.begin(),vs.end()),vs.end());\n\
    \      dat.emplace_back(vs.size());\n    }\n  }\n  void update(int a,Key x,T z){\n\
    \    a+=n;\n    while(a){\n      auto &vs=val[a];\n      int k=lower_bound(vs.begin(),vs.end(),x)-vs.begin();\n\
    \      dat[a].add(k,z);\n      a>>=1;\n    }\n  }\n  T calc(int k,Key x,Key y){\n\
    \    auto &vs=val[k];\n    int p=lower_bound(vs.begin(),vs.end(),x)-vs.begin();\n\
    \    int q=lower_bound(vs.begin(),vs.end(),y)-vs.begin();\n    return dat[k].sum(q)-dat[k].sum(p);\n\
    \  }\n  // [a, b) * [x, y)\n  T query(int a,int b,Key x,Key y){\n    T res=0;\n\
    \    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){\n      if(l&1) res+=calc(l++,x,y);\n\
    \      if(r&1) res+=calc(--r,x,y);\n    }\n    return res;\n  }\n};\n//END CUT\
    \ HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n//END CUT HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/count/dynamic_offline.cpp
  requiredBy: []
  timestamp: '2020-10-27 18:08:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2842.test.cpp
  - test/yukicoder/2063.test.cpp
  - test/yosupo/point_add_rectangle_sum.test.cpp
  - test/yosupo/rectangle_sum.test.cpp
documentation_of: segtree/count/dynamic_offline.cpp
layout: document
redirect_from:
- /library/segtree/count/dynamic_offline.cpp
- /library/segtree/count/dynamic_offline.cpp.html
title: segtree/count/dynamic_offline.cpp
---
