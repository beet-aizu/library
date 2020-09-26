---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/ahocorasick.cpp
    title: string/ahocorasick.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2257.test.cpp
    title: test/aoj/2257.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2212.test.cpp
    title: test/aoj/2212.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3073.test.cpp
    title: test/aoj/3073.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/tenka1-2016-final/tasks/tenka1_2016_final_c
  bundledCode: "#line 1 \"string/trie.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<size_t X>\nstruct Trie{\n  struct Node{\n\
    \    char c;\n    array<int, X> nxt;\n    vector<int> idxs;\n    int idx;\n  \
    \  Node(char c):c(c),idx(-1){fill(nxt.begin(),nxt.end(),-1);}\n  };\n\n  using\
    \ F = function<int(char)>;\n  vector<Node> vs;\n  F conv;\n\n  Trie(F conv,char\
    \ c='$'):conv(conv){vs.emplace_back(c);}\n\n  inline int &next(int i,int j){\n\
    \    return vs[i].nxt[j];\n  }\n\n  void add(const string &s,int x){\n    int\
    \ pos=0;\n    for(int i=0;i<(int)s.size();i++){\n      int k=conv(s[i]);\n   \
    \   if(~next(pos,k)){\n        pos=next(pos,k);\n        continue;\n      }\n\
    \      int npos=vs.size();\n      next(pos,k)=npos;\n      vs.emplace_back(s[i]);\n\
    \      pos=npos;\n    }\n    vs[pos].idx=x;\n    vs[pos].idxs.emplace_back(x);\n\
    \  }\n\n  int find(const string &s){\n    int pos=0;\n    for(int i=0;i<(int)s.size();i++){\n\
    \      int k=conv(s[i]);\n      if(next(pos,k)<0) return -1;\n      pos=next(pos,k);\n\
    \    }\n    return pos;\n  }\n\n  int move(int pos,char c){\n    assert(pos<(int)vs.size());\n\
    \    return pos<0?-1:next(pos,conv(c));\n  }\n\n  int size(){return vs.size();}\n\
    \n  int idx(int pos){\n    return pos<0?-1:vs[pos].idx;\n  }\n\n  vector<int>\
    \ idxs(int pos){\n    return pos<0?vector<int>():vs[pos].idxs;\n  }\n\n};\n//END\
    \ CUT HERE\n#ifndef call_from_test\nstruct FastIO{\n  FastIO(){\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(0);\n  }\n}fastio_beet;\n\ntemplate<typename T1,typename\
    \ T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}\ntemplate<typename T1,typename\
    \ T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}\n\n//INSERT ABOVE HERE\n\n//\
    \ test trie without aho-corasick\nsigned tenka1_2016_final_C(){\n  string s;\n\
    \  cin>>s;\n  int m;\n  cin>>m;\n  vector<string> p(m);\n  for(int i=0;i<m;i++)\
    \ cin>>p[i];\n\n  vector<int> w(m);\n  for(int i=0;i<m;i++) cin>>w[i];\n\n  Trie<26>::F\
    \ f=[](char c){return c-'a';};\n  Trie<26> trie(f);\n\n  for(int i=0;i<m;i++)\
    \ trie.add(p[i],i);\n\n  int n=s.size();\n  vector<int> dp(n+1,0);\n  int ans=0;\n\
    \  for(int i=0;i<n;i++){\n    chmax(ans,dp[i]);\n    int pos=0;\n    for(int j=0;j<222&&i+j<n;j++){\n\
    \      pos=trie.move(pos,s[i+j]);\n      if(pos<0) break;\n      int k=trie.idx(pos);\n\
    \      if(~k) chmax(dp[i+p[k].size()],ans+w[k]);\n    }\n  }\n  chmax(ans,dp[n]);\n\
    \  cout<<ans<<endl;\n  return 0;\n}\n\n/*\n  verified on 2019/10/28\n  https://atcoder.jp/contests/tenka1-2016-final/tasks/tenka1_2016_final_c\n\
    */\n\nsigned main(){\n  tenka1_2016_final_C();\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<size_t X>\nstruct Trie{\n  struct Node{\n    char c;\n\
    \    array<int, X> nxt;\n    vector<int> idxs;\n    int idx;\n    Node(char c):c(c),idx(-1){fill(nxt.begin(),nxt.end(),-1);}\n\
    \  };\n\n  using F = function<int(char)>;\n  vector<Node> vs;\n  F conv;\n\n \
    \ Trie(F conv,char c='$'):conv(conv){vs.emplace_back(c);}\n\n  inline int &next(int\
    \ i,int j){\n    return vs[i].nxt[j];\n  }\n\n  void add(const string &s,int x){\n\
    \    int pos=0;\n    for(int i=0;i<(int)s.size();i++){\n      int k=conv(s[i]);\n\
    \      if(~next(pos,k)){\n        pos=next(pos,k);\n        continue;\n      }\n\
    \      int npos=vs.size();\n      next(pos,k)=npos;\n      vs.emplace_back(s[i]);\n\
    \      pos=npos;\n    }\n    vs[pos].idx=x;\n    vs[pos].idxs.emplace_back(x);\n\
    \  }\n\n  int find(const string &s){\n    int pos=0;\n    for(int i=0;i<(int)s.size();i++){\n\
    \      int k=conv(s[i]);\n      if(next(pos,k)<0) return -1;\n      pos=next(pos,k);\n\
    \    }\n    return pos;\n  }\n\n  int move(int pos,char c){\n    assert(pos<(int)vs.size());\n\
    \    return pos<0?-1:next(pos,conv(c));\n  }\n\n  int size(){return vs.size();}\n\
    \n  int idx(int pos){\n    return pos<0?-1:vs[pos].idx;\n  }\n\n  vector<int>\
    \ idxs(int pos){\n    return pos<0?vector<int>():vs[pos].idxs;\n  }\n\n};\n//END\
    \ CUT HERE\n#ifndef call_from_test\nstruct FastIO{\n  FastIO(){\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(0);\n  }\n}fastio_beet;\n\ntemplate<typename T1,typename\
    \ T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}\ntemplate<typename T1,typename\
    \ T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}\n\n//INSERT ABOVE HERE\n\n//\
    \ test trie without aho-corasick\nsigned tenka1_2016_final_C(){\n  string s;\n\
    \  cin>>s;\n  int m;\n  cin>>m;\n  vector<string> p(m);\n  for(int i=0;i<m;i++)\
    \ cin>>p[i];\n\n  vector<int> w(m);\n  for(int i=0;i<m;i++) cin>>w[i];\n\n  Trie<26>::F\
    \ f=[](char c){return c-'a';};\n  Trie<26> trie(f);\n\n  for(int i=0;i<m;i++)\
    \ trie.add(p[i],i);\n\n  int n=s.size();\n  vector<int> dp(n+1,0);\n  int ans=0;\n\
    \  for(int i=0;i<n;i++){\n    chmax(ans,dp[i]);\n    int pos=0;\n    for(int j=0;j<222&&i+j<n;j++){\n\
    \      pos=trie.move(pos,s[i+j]);\n      if(pos<0) break;\n      int k=trie.idx(pos);\n\
    \      if(~k) chmax(dp[i+p[k].size()],ans+w[k]);\n    }\n  }\n  chmax(ans,dp[n]);\n\
    \  cout<<ans<<endl;\n  return 0;\n}\n\n/*\n  verified on 2019/10/28\n  https://atcoder.jp/contests/tenka1-2016-final/tasks/tenka1_2016_final_c\n\
    */\n\nsigned main(){\n  tenka1_2016_final_C();\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.cpp
  requiredBy:
  - string/ahocorasick.cpp
  timestamp: '2019-12-26 23:10:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2257.test.cpp
  - test/aoj/2212.test.cpp
  - test/aoj/3073.test.cpp
documentation_of: string/trie.cpp
layout: document
redirect_from:
- /library/string/trie.cpp
- /library/string/trie.cpp.html
title: string/trie.cpp
---
