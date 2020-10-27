---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: datastructure/binarytrie.cpp
    title: datastructure/binarytrie.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/aoj/DSL_2_B.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line 1 \"\
    datastructure/binarytrie.cpp\"\n\n#line 3 \"datastructure/binarytrie.cpp\"\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T,size_t X>\nstruct\
    \ BinaryTrie{\n  struct Node{\n    size_t cnt;\n    Node *p,*l,*r;\n    Node(Node*\
    \ p):cnt(0),p(p){l=r=nullptr;}\n  };\n\n  T acc;\n  Node *root;\n  BinaryTrie():acc(0){root=emplace(nullptr);}\n\
    \n  void clear(Node *a){\n    if(!a) return;\n    clear(a->l);clear(a->r);\n \
    \   delete(a);\n  }\n\n  inline Node* emplace(Node* p){\n    return new Node(p);\n\
    \  }\n\n  inline size_t count(Node* a){\n    return a?a->cnt:0;\n  }\n\n  void\
    \ add(const T b,size_t k=1){\n    const T nb=b^acc;\n    Node* a=root;\n    for(int\
    \ i=X-1;i>=0;i--){\n      bool f=(nb>>i)&1;\n      if(!f and !a->l) a->l=emplace(a);\n\
    \      if( f and !a->r) a->r=emplace(a);\n      a=f?a->r:a->l;\n    }\n    a->cnt+=k;\n\
    \    while((a=a->p)) a->cnt=count(a->l)+count(a->r);\n  }\n\n  inline void update(const\
    \ T b){acc^=b;}\n\n  Node* find(const T b){\n    const T nb=b^acc;\n    Node*\
    \ a=root;\n    for(int i=X-1;i>=0;i--){\n      bool f=(nb>>i)&1;\n      a=f?a->r:a->l;\n\
    \      if(!a) return a;\n    }\n    return a;\n  }\n\n  Node* check(Node *a){\n\
    \    if(!a or count(a)) return a;\n    delete(a);\n    return nullptr;\n  }\n\n\
    \  void sub(Node* a,size_t k=1){\n    assert(a and a->cnt>=k);\n    a->cnt-=k;\n\
    \    while((a=a->p)){\n      a->l=check(a->l);\n      a->r=check(a->r);\n    \
    \  a->cnt=count(a->l)+count(a->r);\n    }\n  }\n\n  Node* xmax(const T b){\n \
    \   assert(count(root));\n    const T nb=b^acc;\n    Node* a=root;\n    for(int\
    \ i=X-1;i>=0;i--){\n      bool f=(nb>>i)&1;\n      if(!a->l or !a->r) a=a->l?a->l:a->r;\n\
    \      else a=f?a->l:a->r;\n    }\n    return a;\n  }\n\n  Node* xmin(const T\
    \ b){\n    return xmax(~b&((T(1)<<X)-1));\n  }\n\n  Node* ge(Node *a,int i){\n\
    \    if(!a) return a;\n    Node *l=a->l,*r=a->r;\n    if((acc>>i)&1) swap(l,r);\n\
    \    if(l or r) return ge(l?l:r,i+1);\n    return a;\n  }\n\n  Node* next(Node*\
    \ a,int i){\n    if(!(a->p)) return nullptr;\n    Node *l=a->p->l,*r=a->p->r;\n\
    \    if((acc>>(i+1))&1) swap(l,r);\n    if(a==l and r) return ge(r,i);\n    return\
    \ next(a->p,i+1);\n  }\n\n  Node* lower_bound(const T b){\n    const T nb=b^acc;\n\
    \    Node* a=root;\n    for(int i=X-1;i>=0;i--){\n      bool f=(nb>>i)&1;\n  \
    \    if(!f and a->l){a=a->l;continue;}\n      if( f and a->r){a=a->r;continue;}\n\
    \      if((b>>i)&1) return next(a,i);\n      return ge(a,i);\n    }\n    return\
    \ a;\n  }\n\n  Node* upper_bound(const T b){\n    return lower_bound(b+1);\n \
    \ }\n\n  T val(Node* a){\n    T res(0);\n    for(int i=0;i<(int)X;i++){\n    \
    \  assert(a->p);\n      res|=(T(a==a->p->r)<<i);\n      a=a->p;\n    }\n    return\
    \ res^acc;\n  }\n\n  Node* find_by_order(size_t k){\n    Node *a=root;\n    if(count(a)<=k)\
    \ return nullptr;\n    for(int i=X-1;i>=0;i--){\n      bool f=(acc>>i)&1;\n  \
    \    if(count(f?a->r:a->l)<=k){\n        k-=count(f?a->r:a->l);\n        a=f?a->l:a->r;\n\
    \      }else{\n        a=f?a->r:a->l;\n      }\n    }\n    return a;\n  }\n\n\
    \  size_t order_of_key(const T b){\n    Node *a=root;\n    size_t res=0;\n   \
    \ for(int i=X-1;i>=0;i--){\n      Node *l=a->l,*r=a->r;\n      if((acc>>i)&1)\
    \ swap(l,r);\n      bool f=(b>>i)&1;\n      if(f) res+=count(l);\n      a=f?r:l;\n\
    \      if(!a) break;\n    }\n    return res;\n  }\n};\n//END CUT HERE\n#ifndef\
    \ call_from_test\n\n// find_by_order (weak)\nsigned ARC033_C(){\n  int q;\n  scanf(\"\
    %d\",&q);\n  BinaryTrie<int, 30> bt;\n  while(q--){\n    int t,x;\n    scanf(\"\
    %d %d\",&t,&x);\n    if(t==1) bt.add(x);\n    if(t==2){\n      auto k=bt.find_by_order(x-1);\n\
    \      printf(\"%d\\n\",bt.val(k));\n      bt.sub(k);\n    }\n  }\n  return 0;\n\
    }\n/*\n  verified on 2020/06/06\n  https://atcoder.jp/contests/arc033/tasks/arc033_3\n\
    */\n\n// upper_bound\nsigned CFR477_C(){\n  using ll = long long;\n\n  int n;\n\
    \  scanf(\"%d\",&n);\n  vector<ll> bs(n);\n  for(int i=0;i<n;i++) scanf(\"%lld\"\
    ,&bs[i]);\n\n  BinaryTrie<ll, 61> bt;\n  for(int i=0;i<n;i++) bt.add(bs[i]);\n\
    \n  ll z=0;\n  auto apply=[&](ll a){\n    z^=a;\n    bt.update(a);\n  };\n\n \
    \ vector<ll> ans;\n  ll x=bt.val(bt.xmin(0));\n\n  ans.emplace_back(x);\n  bt.sub(bt.find(x));\n\
    \  apply(x);\n\n  for(int i=1;i<n;i++){\n    if(bt.val(bt.xmax(0))<=x){\n    \
    \  printf(\"No\\n\");\n      return 0;\n    }\n    auto nxt=bt.upper_bound(x);\n\
    \    ll y=bt.val(nxt);\n\n    ans.emplace_back(y^z);\n    bt.sub(nxt);\n    apply(x^y);\n\
    \    x=y;\n  }\n\n  printf(\"Yes\\n\");\n  for(int i=0;i<n;i++){\n    if(i) printf(\"\
    \ \");\n    printf(\"%lld\",ans[i]);\n  }\n  puts(\"\");\n  return 0;\n}\n/*\n\
    \  verified on 2020/06/06\n  http://codeforces.com/contest/966/problem/C\n*/\n\
    \nsigned main(){\n  //ARC033_C();\n  //CFR477_C();\n  return 0;\n}\n#endif\n#line\
    \ 8 \"test/aoj/DSL_2_B.test.cpp\"\n#undef call_from_test\n\nsigned main(){\n \
    \ cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\n  BinaryTrie<int,\
    \ 30> bt;\n  for(int i=0;i<q;i++){\n    int c,x,y;\n    cin>>c>>x>>y;\n    if(c==0){\n\
    \      bt.add(x,y);\n    }\n    if(c==1){\n      int res=bt.order_of_key(y+1)-bt.order_of_key(x);\n\
    \      cout<<res<<\"\\n\";\n    }\n  }\n  cout<<flush;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../datastructure/binarytrie.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,q;\n  cin>>n>>q;\n\n  BinaryTrie<int,\
    \ 30> bt;\n  for(int i=0;i<q;i++){\n    int c,x,y;\n    cin>>c>>x>>y;\n    if(c==0){\n\
    \      bt.add(x,y);\n    }\n    if(c==1){\n      int res=bt.order_of_key(y+1)-bt.order_of_key(x);\n\
    \      cout<<res<<\"\\n\";\n    }\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - datastructure/binarytrie.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 12:55:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B.test.cpp
- /verify/test/aoj/DSL_2_B.test.cpp.html
title: test/aoj/DSL_2_B.test.cpp
---
