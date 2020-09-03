---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/nicetree.cpp: line 226: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nstruct NiceTree{\n  vector< vector<int> > G;\n  vector< set<int>\
    \ > ex;\n  vector<int> buff;\n  NiceTree(int n):G(n),ex(n),buff(n){}\n\n  void\
    \ add_edge(int u,int v){\n    if(u>v) swap(u,v);\n    if(ex[u].count(v)) return;\n\
    \    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n    ex[u].emplace(v);\n\
    \  }\n\n  enum Type{LEAF, JOIN, INTRODUCE, FORGET};\n  struct Node{\n    int type,is_root;\n\
    \    Node():type(-1),is_root(1){}\n\n    // index for G\n    vector<int> bag;\n\
    \    void add_vertex(int v){bag.emplace_back(v);}\n\n    // index for T\n    vector<int>\
    \ child;\n    void add_child(int v){child.emplace_back(v);}\n  };\n\n  vector<Node>\
    \ T;\n  void to_nice(){\n    for(auto &vs:T){\n      sort(vs.bag.begin(),vs.bag.end());\n\
    \      for(int c:vs.child) T[c].is_root=0;\n    }\n\n    stack<int> st;\n    for(int\
    \ i=0;i<(int)T.size();i++)\n      if(T[i].is_root) st.emplace(i);\n\n    while(!st.empty()){\n\
    \      int v=st.top();st.pop();\n\n      while(T[v].child.size()>2){\n       \
    \ Node r;\n        r.add_child(T[v].child.back());\n        T[v].child.pop_back();\n\
    \        r.add_child(T[v].child.back());\n        T[v].child.pop_back();\n   \
    \     r.bag=T[v].bag;\n        T[v].add_child(T.size());\n        T.emplace_back(r);\n\
    \      }\n\n      if(T[v].child.size()==2){\n        for(auto &u:T[v].child){\n\
    \          if(T[u].bag!=T[v].bag){\n            Node r;\n            r.add_child(u);\n\
    \            r.bag=T[v].bag;\n            u=T.size();\n            T.emplace_back(r);\n\
    \          }\n        }\n        T[v].type=JOIN;\n      }\n\n      if(T[v].child.size()==1){\n\
    \        int &u=T[v].child[0];\n        vector<int> latte,malta;\n        auto\
    \ &ps=T[v].bag;\n        auto &qs=T[u].bag;\n        set_difference(ps.begin(),ps.end(),qs.begin(),qs.end(),\n\
    \                       back_inserter(latte));\n        set_difference(qs.begin(),qs.end(),ps.begin(),ps.end(),\n\
    \                       back_inserter(malta));\n        if(latte.size()+malta.size()>1){\n\
    \          Node r;\n          r.add_child(u);\n          r.bag=T[v].bag;\n   \
    \       if(!latte.empty()){\n            r.bag.erase(find(r.bag.begin(),r.bag.end(),latte.back()));\n\
    \          }else{\n            r.bag.emplace_back(malta.back());\n          }\n\
    \          u=T.size();\n          T.emplace_back(r);\n        }\n        if(T[v].bag.size()<T[u].bag.size())\
    \ T[v].type=FORGET;\n        if(T[v].bag.size()>T[u].bag.size()) T[v].type=INTRODUCE;\n\
    \      }\n\n      if(T[v].child.empty()){\n        if(T[v].bag.size()>1){\n  \
    \        Node r;\n          r.bag=T[v].bag;\n          r.bag.pop_back();\n   \
    \       T[v].type=INTRODUCE;\n          T[v].add_child(T.size());\n          T.emplace_back(r);\n\
    \        }else{\n          T[v].type=LEAF;\n        }\n      }\n\n      for(auto\
    \ &u:T[v].child)\n        st.emplace(u);\n    }\n\n    for(auto &vs:T)\n     \
    \ for(int c:vs.child) T[c].is_root=0;\n  }\n\n  // root = 0 (if connected)\n \
    \ void build(){\n    int n=G.size();\n    if(n<=3){\n      Node r;\n      for(int\
    \ i=0;i<n;i++) r.add_vertex(i);\n      T=vector<Node>({r});\n      return to_nice();\n\
    \    }\n\n    vector<int> deg(n);\n    queue<int> que;\n    for(int i=0;i<n;i++){\n\
    \      deg[i]=G[i].size();\n      if(deg[i]<=2) que.emplace(i);\n    }\n\n   \
    \ vector<int> used(n,-1);\n    T.emplace_back();\n    while(!que.empty()){\n \
    \     int v=que.front();que.pop();\n      if(deg[v]>2||used[v]!=-1) continue;\n\
    \      Node r;\n      r.add_vertex(v);\n\n      int p=-1,q=-1;\n      for(int\
    \ u:G[v]){\n        if(used[u]==-1){\n          (p==-1?p:q)=u;\n          r.add_vertex(u);\n\
    \        }else if(used[u]>=0){\n          r.add_child(used[u]);\n          used[u]=-2;\n\
    \        }\n      }\n\n      if(deg[v]==0){\n        used[v]=T.size();\n     \
    \   T.emplace_back(r);\n        continue;\n      }\n\n      if(q==-1){\n     \
    \   deg[p]--;\n      }else{\n        if(p>q) swap(p,q);\n        if(!ex[p].count(q)){\n\
    \          add_edge(p,q);\n        }else{\n          deg[p]--;\n          deg[q]--;\n\
    \        }\n      }\n      for(int u:G[v])\n        if(deg[u]<=2) que.emplace(u);\n\
    \      deg[v]=0;\n      used[v]=T.size();\n      T.emplace_back(r);\n    }\n\n\
    \    for(int i=0;i<n;i++){\n      if(deg[i]>0){\n        T={};\n        return;\n\
    \      }\n    }\n\n    T.front()=T.back();T.pop_back();\n    to_nice();\n  }\n\
    \n  template<typename F1,typename F2,typename F3,typename F4>\n  void dfs(int\
    \ v,F1 &leaf,F2 &join,F3 &introduce,F4 &forget){\n    const auto &chd=T[v].child;\n\
    \    for(int u:chd) dfs(u,leaf,join,introduce,forget);\n\n    if(T[v].type==LEAF){\n\
    \      leaf(v);\n      return;\n    }\n    if(T[v].type==JOIN){\n      join(v);\n\
    \      return;\n    }\n\n    const auto &bag=T[v].bag;\n    for(int i=0;i<(int)bag.size();i++)\n\
    \      buff[bag[i]]=1<<i;\n\n    const auto &chd_bag=T[chd[0]].bag;\n    int dif=0;\n\
    \    for(int b:bag) dif^=b;\n    for(int b:chd_bag) dif^=b;\n\n    if(T[v].type==INTRODUCE){\n\
    \      introduce(v,dif);\n      return;\n    }\n    if(T[v].type==FORGET){\n \
    \     forget(v,dif);\n      return;\n    }\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    \n#define call_from_test\n#include \"../tools/fastio.cpp\"\n#include \"../tools/chminmax.cpp\"\
    \n#undef call_from_test\n\nsigned CSA_SPECIAL_MVC(){\n  int n,m;\n  cin>>n>>m;\n\
    \  NiceTree G(n);\n  using P = pair<int, int>;\n  set<P> es;\n  for(int i=0;i<m;i++){\n\
    \    int a,b;\n    cin>>a>>b;\n    a--;b--;\n    G.add_edge(a,b);\n    es.emplace(a,b);\n\
    \    es.emplace(b,a);\n  }\n\n  G.build();\n  auto &T=G.T;\n  auto &buff=G.buff;\n\
    \n  vector< vector<int> > dps(T.size());\n\n  const int INF = 1e9;\n  auto base=\n\
    \    [&](int v){\n      const auto &bag=T[v].bag;\n      auto &dp=dps[v];\n  \
    \    dp.assign(1<<bag.size(),-INF);\n    };\n\n  auto leaf=\n    [&](int v){\n\
    \      base(v);\n      auto &dp=dps[v];\n      dp[0]=0;\n      dp[1]=1;\n    };\n\
    \n  auto join=\n    [&](int v){\n      base(v);\n      const auto &chd=T[v].child;\n\
    \      auto &dp=dps[v];\n      for(int i=0;i<(int)dp.size();i++)\n        chmax(dp[i],dps[chd[0]][i]+dps[chd[1]][i]-__builtin_popcount(i));\n\
    \    };\n\n  auto introduce=\n    [&](int v,int add){\n      base(v);\n\n    \
    \  const auto &chd=T[v].child;\n      const auto &chd_bag=T[chd[0]].bag;\n   \
    \   const auto &pr=dps[chd[0]];\n\n      auto &dp=dps[v];\n      for(int i=0;i<(int)pr.size();i++){\n\
    \        int bit=0,valid=1;\n        for(int j=0;j<(int)chd_bag.size();j++){\n\
    \          if((~i>>j)&1) continue;\n          bit|=buff[chd_bag[j]];\n       \
    \   valid&=!es.count(P(chd_bag[j],add));\n        }\n        assert(!(bit&buff[add]));\n\
    \        if(valid) chmax(dp[bit|buff[add]],pr[i]+1);\n        chmax(dp[bit],pr[i]);\n\
    \      }\n    };\n\n  auto forget=\n    [&](int v,int rmv){\n      base(v);\n\n\
    \      const auto &chd=T[v].child;\n      const auto &chd_bag=T[chd[0]].bag;\n\
    \      const auto &pr=dps[chd[0]];\n\n      auto &dp=dps[v];\n      for(int i=0;i<(int)pr.size();i++){\n\
    \        int bit=0;\n        for(int j=0;j<(int)chd_bag.size();j++){\n       \
    \   if((~i>>j)&1) continue;\n          if(rmv!=chd_bag[j]) bit|=buff[chd_bag[j]];\n\
    \        }\n        chmax(dp[bit],pr[i]);\n      }\n    };\n\n  int ans=n;\n \
    \ for(int i=0;i<(int)T.size();i++){\n    if(!T[i].is_root) continue;\n    G.dfs(i,leaf,join,introduce,forget);\n\
    \    ans-=*max_element(dps[i].begin(),dps[i].end());\n  }\n  cout<<ans<<endl;\n\
    \  return 0;\n}\n/*\n  verified 2020/02/21\n  https://csacademy.com/contest/archive/task/special-mvc/statement/\n\
    */\n\nsigned main(){\n  CSA_SPECIAL_MVC();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - tools/fastio.cpp
  - tools/chminmax.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/fastio.cpp
    title: tools/fastio.cpp
  - icon: ':heavy_check_mark:'
    path: tools/chminmax.cpp
    title: tools/chminmax.cpp
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2405.test.cpp
    title: test/aoj/2405.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tree_decomposition_width_2.test.cpp
    title: test/yosupo/tree_decomposition_width_2.test.cpp
  isVerificationFile: false
  path: graph/nicetree.cpp
  requiredBy: []
  timestamp: '2020-05-07 20:09:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/2405.test.cpp
  - test/yosupo/tree_decomposition_width_2.test.cpp
documentation_of: graph/nicetree.cpp
layout: document
redirect_from:
- /library/graph/nicetree.cpp
- /library/graph/nicetree.cpp.html
title: graph/nicetree.cpp
---
