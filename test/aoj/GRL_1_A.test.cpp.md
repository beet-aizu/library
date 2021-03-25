---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: datastructure/radixheap.cpp
    title: datastructure/radixheap.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"test/aoj/GRL_1_A.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line 1 \"\
    datastructure/radixheap.cpp\"\n\n#line 3 \"datastructure/radixheap.cpp\"\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\n// prohibited to push an element less\
    \ than popped one\n// Key: int or long long\ntemplate<typename K,typename V>\n\
    struct RadixHeap{\n  inline static constexpr int bit = sizeof(K) * 8;\n  array<vector<\
    \ pair<K, V> >, bit> vs;\n\n  int size;\n  K last;\n  RadixHeap():size(0),last(0){}\n\
    \n  bool empty() const{return size==0;}\n\n  inline int getbit(int a){\n    return\
    \ a?bit-__builtin_clz(a):0;\n  }\n\n  inline int getbit(long long a){\n    return\
    \ a?bit-__builtin_clzll(a):0;\n  }\n\n  void emplace(K key,V val){\n    size++;\n\
    \    vs[getbit(key^last)].emplace_back(key,val);\n  }\n\n  pair<K, V> pop(){\n\
    \    if(vs[0].empty()){\n      int idx=1;\n      while(vs[idx].empty()) idx++;\n\
    \      last=min_element(vs[idx].begin(),vs[idx].end())->first;\n      for(auto\
    \ &p:vs[idx]) vs[getbit(p.first^last)].emplace_back(p);\n      vs[idx].clear();\n\
    \    }\n    --size;\n    auto res=vs[0].back();\n    vs[0].pop_back();\n    return\
    \ res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n#line 8 \"test/aoj/GRL_1_A.test.cpp\"\n\
    #undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n,m,r;\n  cin>>n>>m>>r;\n\n  using P = pair<int, int>;\n  vector< vector<P>\
    \ > G(n);\n  for(int i=0;i<m;i++){\n    int s,t,d;\n    cin>>s>>t>>d;\n    G[s].emplace_back(t,d);\n\
    \  }\n\n  const int INF = numeric_limits<int>::max();\n  RadixHeap<int, int> pq;\n\
    \  vector<int> dist(n,INF);\n  dist[r]=0;\n  pq.emplace(dist[r],r);\n  while(!pq.empty()){\n\
    \    P p=pq.pop();\n    int v=p.second;\n    if(dist[v]<p.first) continue;\n \
    \   for(auto& e:G[v]){\n      int u=e.first,c=e.second;\n      if(dist[u]>dist[v]+c){\n\
    \        dist[u]=dist[v]+c;\n        pq.emplace(dist[u],u);\n      }\n    }\n\
    \  }\n\n  for(int i=0;i<n;i++){\n    if(dist[i]==INF) cout<<\"INF\\n\";\n    else\
    \ cout<<dist[i]<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../datastructure/radixheap.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int n,m,r;\n  cin>>n>>m>>r;\n\n\
    \  using P = pair<int, int>;\n  vector< vector<P> > G(n);\n  for(int i=0;i<m;i++){\n\
    \    int s,t,d;\n    cin>>s>>t>>d;\n    G[s].emplace_back(t,d);\n  }\n\n  const\
    \ int INF = numeric_limits<int>::max();\n  RadixHeap<int, int> pq;\n  vector<int>\
    \ dist(n,INF);\n  dist[r]=0;\n  pq.emplace(dist[r],r);\n  while(!pq.empty()){\n\
    \    P p=pq.pop();\n    int v=p.second;\n    if(dist[v]<p.first) continue;\n \
    \   for(auto& e:G[v]){\n      int u=e.first,c=e.second;\n      if(dist[u]>dist[v]+c){\n\
    \        dist[u]=dist[v]+c;\n        pq.emplace(dist[u],u);\n      }\n    }\n\
    \  }\n\n  for(int i=0;i<n;i++){\n    if(dist[i]==INF) cout<<\"INF\\n\";\n    else\
    \ cout<<dist[i]<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - datastructure/radixheap.cpp
  isVerificationFile: true
  path: test/aoj/GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-03-25 09:40:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_A.test.cpp
- /verify/test/aoj/GRL_1_A.test.cpp.html
title: test/aoj/GRL_1_A.test.cpp
---
