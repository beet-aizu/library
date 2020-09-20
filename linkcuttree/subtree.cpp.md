---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linkcuttree/base.cpp
    title: linkcuttree/base.cpp
  - icon: ':heavy_check_mark:'
    path: tools/fastio.cpp
    title: tools/fastio.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3120.test.cpp
    title: test/aoj/3120.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
    title: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - http://beet-aizu.hatenablog.com/entry/2019/06/08/221833
    - https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_e
    - https://codeforces.com/contest/1172/problem/E
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ linkcuttree/subtree.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"base.cpp\"\n#undef call_from_test\n\n#endif\n\
    /**\n * @see http://beet-aizu.hatenablog.com/entry/2019/06/08/221833\n */\n//BEGIN\
    \ CUT HERE\ntemplate<typename Ap>\nstruct NodeBase{\n  using A = Ap;\n  NodeBase\
    \ *l,*r,*p;\n  bool rev;\n  A val,dat,sum;\n  NodeBase(){}\n  NodeBase(A val,A\
    \ dat,A sum):\n    rev(0),val(val),dat(dat),sum(sum){\n    l=r=p=nullptr;}\n};\n\
    \ntemplate<typename Np, size_t LIM>\nstruct SubTree : LinkCutTreeBase<Np, LIM>{\n\
    \  using super = LinkCutTreeBase<Np, LIM>;\n  using Node = Np;\n  using A = typename\
    \ Node::A;\n\n  SubTree():super(){}\n\n  Node* create(A val){\n    return super::create(Node(val,A(),val));\n\
    \  }\n\n  inline void toggle(Node *t){\n    swap(t->l,t->r);\n    t->rev^=1;\n\
    \  }\n\n  inline Node* eval(Node *t){\n    if(t->rev){\n      if(t->l) toggle(t->l);\n\
    \      if(t->r) toggle(t->r);\n      t->rev=false;\n    }\n    return t;\n  }\n\
    \n  inline A resolve(Node *t){\n    return t?t->sum:A();\n  }\n\n  inline void\
    \ pushup(Node *t){\n    if(t==nullptr) return;\n    t->sum=t->val+t->dat;\n  \
    \  t->sum+=resolve(t->l);\n    t->sum+=resolve(t->r);\n  }\n\n  using super::splay;\n\
    \n  Node* expose(Node *t){\n    Node *rp=nullptr;\n    for(Node *c=t;c;c=c->p){\n\
    \      splay(c);\n      c->dat+=resolve(c->r);\n      c->r=rp;\n      c->dat-=resolve(c->r);\n\
    \      pushup(c);\n      rp=c;\n    }\n    splay(t);\n    return rp;\n  }\n\n\
    \  A query(Node *t){\n    expose(t);\n    return t->sum;\n  }\n\n  void set_val(Node\
    \ *t,A a){\n    expose(t);\n    t->val=a;\n    pushup(t);\n  }\n};\n//END CUT\
    \ HERE\n#ifndef call_from_test\n\n#define call_from_test\n#include \"../tools/fastio.cpp\"\
    \n#undef call_from_test\n\n//INSERT ABOVE HERE\n\n// sum of square\nsigned CFR564_E(){\n\
    \  int n,m;\n  cin>>n>>m;\n  vector<vector<int>> modv(n),modt(n);\n  vector<int>\
    \ cs(n);\n\n  for(int i=0;i<n;i++){\n    cin>>cs[i];\n    cs[i]--;\n    modv[cs[i]].emplace_back(i);\n\
    \    modt[cs[i]].emplace_back(0);\n  }\n\n  vector<vector<int> > G(n+1);\n  for(int\
    \ i=1;i<n;i++){\n    int a,b;\n    cin>>a>>b;\n    a--;b--;\n    G[a].emplace_back(b);\n\
    \    G[b].emplace_back(a);\n  }\n  G[n].emplace_back(0);\n\n  for(int i=1;i<=m;i++){\n\
    \    int v,x;\n    cin>>v>>x;\n    v--;x--;\n    modv[cs[v]].emplace_back(v);\n\
    \    modt[cs[v]].emplace_back(i);\n    cs[v]=x;\n    modv[cs[v]].emplace_back(v);\n\
    \    modt[cs[v]].emplace_back(i);\n  }\n\n  using ll = long long;\n  struct A{\n\
    \    ll sz1,sz2;\n    A():sz1(0),sz2(){}\n    A(ll sz1,ll sz2):sz1(sz1),sz2(sz2){}\n\
    \    A operator+(const A &a)const{\n      return A(sz1+a.sz1,sz2+a.sz2);\n   \
    \ };\n    A& operator+=(const A &a){\n      sz1+=a.sz1;\n      sz2+=a.sz1*a.sz1;\n\
    \      return (*this);\n    }\n    A& operator-=(const A &a){\n      sz1-=a.sz1;\n\
    \      sz2-=a.sz1*a.sz1;\n      return (*this);\n    }\n  };\n\n  using Node =\
    \ NodeBase<A>;\n  constexpr size_t LIM = 1e6;\n  using LCT = SubTree<Node, LIM>;\n\
    \  LCT lct;\n\n  for(int i=0;i<n+1;i++) lct.create(A(1,0));\n\n  vector<int> par(n+1,0);\n\
    \  {\n    using P = pair<int, int>;\n    queue<P> q;\n    q.emplace(n,-1);\n \
    \   while(!q.empty()){\n      int v,p;\n      tie(v,p)=q.front();q.pop();\n  \
    \    par[v]=p;\n      if(~p) lct.link(lct[p],lct[v]);\n      for(int u:G[v])\n\
    \        if(u!=p) q.emplace(u,v);\n    }\n  }\n\n  vector<ll> delta(m+1,0);\n\
    \  vector<int> color(n+1,0);\n\n  for(int c=0;c<n;c++){\n    ll lst=(ll)n*n,cur=(ll)n*n;\n\
    \    delta[0]+=lst;\n\n    if(modv[c].empty()) continue;\n    for(int i=0;i<(int)modv[c].size();i++){\n\
    \      int v=modv[c][i];\n      color[v]^=1;\n      if(color[v]){\n        cur-=lct.query(lct.root(lct[v])).sz2;\n\
    \        lct.cut(lct[v]);\n        cur+=lct.query(lct.root(lct[par[v]])).sz2;\n\
    \        cur+=lct.query(lct[v]).sz2;\n      }else{\n        cur-=lct.query(lct.root(lct[par[v]])).sz2;\n\
    \        cur-=lct.query(lct[v]).sz2;\n        lct.link(lct[par[v]],lct[v]);\n\
    \        cur+=lct.query(lct.root(lct[v])).sz2;\n      }\n      if(i+1==(int)modv[c].size()||modt[c][i]!=modt[c][i+1]){\n\
    \        delta[modt[c][i]]+=cur-lst;\n        lst=cur;\n      }\n    }\n\n   \
    \ for(int i=0;i<(int)modv[c].size();i++){\n      int v=modv[c][i];\n      if(!color[v])\
    \ continue;\n      color[v]^=1;\n      lct.link(lct[par[v]],lct[v]);\n    }\n\
    \  }\n\n  ll ans=(ll)n*n*n;\n  for(int i=0;i<=m;i++){\n    ans-=delta[i];\n  \
    \  cout<<ans<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n/*\n  verified on\
    \ 2020/01/06\n  https://codeforces.com/contest/1172/problem/E\n*/\n\n// test root\n\
    signed NIKKEI2019_QUAL_E(){\n  int n,m;\n  cin>>n>>m;\n  vector<int> xs(n);\n\
    \  for(int i=0;i<n;i++) cin>>xs[i];\n  using T = tuple<int, int, int>;\n  vector<T>\
    \ vt;\n  for(int i=0;i<m;i++){\n    int a,b,y;\n    cin>>a>>b>>y;\n    a--;b--;\n\
    \    vt.emplace_back(y,a,b);\n  }\n  sort(vt.begin(),vt.end());\n\n  using ll\
    \ = long long;\n  using Node = NodeBase<ll>;\n  constexpr size_t LIM = 1e6;\n\
    \  using LCT = SubTree<Node, LIM>;\n  LCT lct;\n\n  for(int i=0;i<n;i++) lct.create(xs[i]);\n\
    \n  using P = pair<int, int>;\n  set<P> es;\n  for(auto t:vt){\n    int a,b;\n\
    \    tie(ignore,a,b)=t;\n    if(lct.is_connected(lct[a],lct[b])) continue;\n \
    \   lct.evert(lct[b]);\n    lct.link(lct[a],lct[b]);\n    es.emplace(a,b);\n \
    \ }\n\n  int ans=0;\n  reverse(vt.begin(),vt.end());\n  for(auto t:vt){\n    int\
    \ y,a,b;\n    tie(y,a,b)=t;\n    auto rt=lct.root(lct[a]);\n    ll sum=lct.query(rt);\n\
    \    if(sum>=y) continue;\n    ans++;\n    if(es.count(P(a,b))){\n      lct.evert(lct[a]);\n\
    \      lct.cut(lct[b]);\n    }\n  }\n\n  cout<<ans<<endl;\n  return 0;\n}\n/*\n\
    \  verified on 2020/01/06\n  https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_e\n\
    */\n\nsigned main(){\n  //CFR564_E();\n  //NIKKEI2019_QUAL_E();\n  return 0;\n\
    }\n#endif\n"
  dependsOn:
  - linkcuttree/base.cpp
  - tools/fastio.cpp
  isVerificationFile: false
  path: linkcuttree/subtree.cpp
  requiredBy: []
  timestamp: '2020-07-16 18:11:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3120.test.cpp
  - test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp
  - test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
documentation_of: linkcuttree/subtree.cpp
layout: document
redirect_from:
- /library/linkcuttree/subtree.cpp
- /library/linkcuttree/subtree.cpp.html
title: linkcuttree/subtree.cpp
---
