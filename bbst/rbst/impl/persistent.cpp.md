---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/rbst/data/array.cpp
    title: bbst/rbst/data/array.cpp
  - icon: ':question:'
    path: bbst/rbst/data/lazy.cpp
    title: bbst/rbst/data/lazy.cpp
  - icon: ':question:'
    path: bbst/rbst/rbst.cpp
    title: bbst/rbst/rbst.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0437.test.cpp
    title: test/aoj/0437.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_queue.test.cpp
    title: test/yosupo/persistent_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc030/tasks/arc030_4
    - https://atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ bbst/rbst/impl/persistent.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"../rbst.cpp\"\n#undef call_from_test\n\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename Data, size_t LIM>\nstruct Persistent : RBST<Persistent<Data,\
    \ LIM>, Data, typename Data::Node, LIM>{\n  using super = RBST<Persistent, Data,\
    \ typename Data::Node, LIM>;\n  using Node = typename Data::Node;\n\n  Data data;\n\
    \n  template<class... Args>\n  Persistent(Args... args):data(forward<Args>(args)...){}\n\
    \n  inline Node* clone(Node *t){\n    if(t==nullptr) return t;\n    return super::create(*t);\n\
    \  }\n\n  inline Node* touch(Node *t){\n    if(t==nullptr) return t;\n    t=clone(t);\n\
    \    if(data.dirty(t)){\n      t->l=clone(t->l);\n      t->r=clone(t->r);\n  \
    \  }\n    return data.eval(t);\n  }\n\n  using super::toggle;\n  inline void toggle(Node\
    \ *t){return data.toggle(t);}\n  template<typename E>\n  inline void propagate(Node\
    \ *t,E x){return data.propagate(t,x);}\n  inline Node* pushup(Node *t){return\
    \ data.pushup(t);}\n\n  inline decltype(auto) get_val(Node *a,size_t k){\n   \
    \ return data.get_val(super::get_val(a,k));\n  }\n\n  using super::merge, super::split;\n\
    \  decltype(auto) query(Node *a,size_t l,size_t r){\n    auto s=split(a,l);\n\
    \    auto t=split(s.second,r-l);\n    auto u=t.first;\n    return data.reflect(u);\n\
    \  }\n\n  bool almost_full() const{\n    return super::size+1000>LIM;\n  }\n\n\
    \  Node* rebuild(Node* a){\n    auto vs=data.dump(a);\n    super::size=0;\n  \
    \  return super::build(vs);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    \n#define call_from_test\n#include \"../data/array.cpp\"\n#undef call_from_test\n\
    \nsigned JOISC2012_COPYPASTE(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n \
    \ int m;\n  string buf;\n  cin>>m>>buf;\n\n  using Data = Array<char>;\n  using\
    \ Node = Data::Node;\n  const size_t LIM = 1e7;\n  Persistent<Data, LIM> pa;\n\
    \n  vector<Node> vs(buf.begin(),buf.end());\n  auto rt=pa.build(vs);\n\n  int\
    \ n;\n  cin>>n;\n  for(int i=0;i<n;i++){\n    int a,b,c;\n    cin>>a>>b>>c;\n\
    \    auto s=pa.split(rt,a);\n    auto t=pa.split(s.second,b-a);\n    auto u=pa.split(rt,c);\n\
    \    rt=pa.merge(pa.merge(u.first,t.first),u.second);\n\n    if((int)pa.count(rt)>m)\n\
    \      rt=pa.split(rt,m).first;\n\n    if(pa.almost_full()) rt=pa.rebuild(rt);\n\
    \  }\n\n  auto ds=pa.data.dump(rt);\n  buf.resize(ds.size());\n  for(int i=0;i<(int)ds.size();i++)\
    \ buf[i]=ds[i].val;\n  cout<<buf<<endl;\n  return 0;\n}\n/*\n  verified on 2020/11/04\n\
    \  https://atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste\n*/\n\n\n#define\
    \ call_from_test\n#include \"../data/lazy.cpp\"\n#undef call_from_test\n\nsigned\
    \ ARC030_D(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  const char newl =\
    \ '\\n';\n\n  int n,q;\n  cin>>n>>q;\n\n  using ll = long long;\n  using P = pair<ll,\
    \ ll>;\n  vector<P> vp(n,P(0,1));\n  for(int i=0;i<n;i++) cin>>vp[i].first;\n\n\
    \  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};\n  auto g=[](P\
    \ a,ll b){return P(a.first+b*a.second,a.second);};\n  auto h=[](ll a,ll b){return\
    \ a+b;};\n  auto flip=[](P a){return a;};\n\n  using Data = Lazy<P, ll, decltype(f),\
    \ decltype(g), decltype(h),\n                    decltype(flip)>;\n  using Node\
    \ = Data::Node;\n  constexpr size_t LIM = 6e6;\n  Persistent<Data, LIM> G(f,g,h,flip,P(0,0),0);\n\
    \n  vector<Node> vs;\n  for(auto v:vp) vs.emplace_back(v,0);\n  auto rt=G.build(vs);\n\
    \n  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n\n    if(t==1){\n      int\
    \ a,b,v;\n      cin>>a>>b>>v;\n      a--;\n      rt=G.update(rt,a,b,v);\n    }\n\
    \n    if(t==2){\n      int a,b,c,d;\n      cin>>a>>b>>c>>d;\n      a--;c--;\n\
    \      auto s=G.split(rt,a);\n      auto t=G.split(s.second,b-a);\n      auto\
    \ u=G.split(rt,c);\n      auto v=G.split(u.second,d-c);\n\n      rt=G.merge(G.merge(s.first,v.first),t.second);\n\
    \    }\n\n    if(t==3){\n      int a,b;\n      cin>>a>>b;\n      a--;\n      cout<<G.query(rt,a,b).first<<newl;\n\
    \    }\n\n    if(G.almost_full()) rt=G.rebuild(rt);\n  }\n  return 0;\n}\n/*\n\
    \  verified on 2020/11/04\n  https://atcoder.jp/contests/arc030/tasks/arc030_4\n\
    */\n\n//INSERT ABOVE HERE\nsigned main(){\n  //JOISC2012_COPYPASTE();\n  //ARC030_D();\n\
    \  return 0;\n}\n#endif\n"
  dependsOn:
  - bbst/rbst/rbst.cpp
  - bbst/rbst/data/array.cpp
  - bbst/rbst/data/lazy.cpp
  isVerificationFile: false
  path: bbst/rbst/impl/persistent.cpp
  requiredBy: []
  timestamp: '2020-11-04 18:35:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_queue.test.cpp
  - test/aoj/0437.test.cpp
documentation_of: bbst/rbst/impl/persistent.cpp
layout: document
redirect_from:
- /library/bbst/rbst/impl/persistent.cpp
- /library/bbst/rbst/impl/persistent.cpp.html
title: bbst/rbst/impl/persistent.cpp
---
