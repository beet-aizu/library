---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2292.test.cpp
    title: test/aoj/2292.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0399.test.cpp
    title: test/yukicoder/0399.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"string/palindromictree.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nstruct PalindromicTree{\n  struct\
    \ node{\n    map<char, int> nxt;\n    int len,suf,app,cnt;\n    node(){}\n   \
    \ node(int len,int suf,int app,int cnt)\n      :len(len),suf(suf),app(app),cnt(cnt){}\n\
    \  };\n  vector<node> vs;\n  vector<int> ord;\n  int n,ptr;\n\n  PalindromicTree(){}\n\
    \  PalindromicTree(const string &s)\n    :vs(s.size()+10),n(2),ptr(1){\n\n   \
    \ vs[0]=node(-1,0,-1,0);\n    vs[1]=node( 0,0,-1,0);\n\n    for(int i=0;i<(int)s.size();i++)\
    \ add_char(s,i);\n    calc_order();\n    calc_count();\n  }\n\n  bool add_char(const\
    \ string &s,int pos){\n    char ch=s[pos];\n    int cur=ptr;\n    while(1){\n\
    \      int rev=pos-1-vs[cur].len;\n      if(rev>=0&&s[rev]==ch) break;\n     \
    \ cur=vs[cur].suf;\n    }\n\n    if(vs[cur].nxt.count(ch)){\n      ptr=vs[cur].nxt[ch];\n\
    \      vs[ptr].cnt++;\n      return false;\n    }\n    ptr=n++;\n\n    vs[ptr]=node(vs[cur].len+2,-1,pos-vs[cur].len-1,1);\n\
    \    vs[cur].nxt[ch]=ptr;\n\n    if(vs[ptr].len==1){\n      vs[ptr].suf=1;\n \
    \     return true;\n    }\n\n    while(1){\n      cur=vs[cur].suf;\n      int\
    \ rev=pos-1-vs[cur].len;\n      if(rev>=0&&s[rev]==ch){\n        vs[ptr].suf=vs[cur].nxt[ch];\n\
    \        break;\n      }\n    }\n    return true;\n  }\n\n  void calc_order(){\n\
    \    ord.clear();\n    ord.push_back(0);\n    ord.push_back(1);\n    for(int i=0;i<(int)ord.size();i++)\n\
    \      for(auto &p:vs[ord[i]].nxt) ord.push_back(p.second);\n  }\n\n  void calc_count(){\n\
    \    for(int i=(int)ord.size()-1;i>=0;i--)\n      vs[vs[ord[i]].suf].cnt+=vs[ord[i]].cnt;\n\
    \  }\n\n  size_t size()const{return n;}\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nstruct PalindromicTree{\n  struct node{\n    map<char, int>\
    \ nxt;\n    int len,suf,app,cnt;\n    node(){}\n    node(int len,int suf,int app,int\
    \ cnt)\n      :len(len),suf(suf),app(app),cnt(cnt){}\n  };\n  vector<node> vs;\n\
    \  vector<int> ord;\n  int n,ptr;\n\n  PalindromicTree(){}\n  PalindromicTree(const\
    \ string &s)\n    :vs(s.size()+10),n(2),ptr(1){\n\n    vs[0]=node(-1,0,-1,0);\n\
    \    vs[1]=node( 0,0,-1,0);\n\n    for(int i=0;i<(int)s.size();i++) add_char(s,i);\n\
    \    calc_order();\n    calc_count();\n  }\n\n  bool add_char(const string &s,int\
    \ pos){\n    char ch=s[pos];\n    int cur=ptr;\n    while(1){\n      int rev=pos-1-vs[cur].len;\n\
    \      if(rev>=0&&s[rev]==ch) break;\n      cur=vs[cur].suf;\n    }\n\n    if(vs[cur].nxt.count(ch)){\n\
    \      ptr=vs[cur].nxt[ch];\n      vs[ptr].cnt++;\n      return false;\n    }\n\
    \    ptr=n++;\n\n    vs[ptr]=node(vs[cur].len+2,-1,pos-vs[cur].len-1,1);\n   \
    \ vs[cur].nxt[ch]=ptr;\n\n    if(vs[ptr].len==1){\n      vs[ptr].suf=1;\n    \
    \  return true;\n    }\n\n    while(1){\n      cur=vs[cur].suf;\n      int rev=pos-1-vs[cur].len;\n\
    \      if(rev>=0&&s[rev]==ch){\n        vs[ptr].suf=vs[cur].nxt[ch];\n       \
    \ break;\n      }\n    }\n    return true;\n  }\n\n  void calc_order(){\n    ord.clear();\n\
    \    ord.push_back(0);\n    ord.push_back(1);\n    for(int i=0;i<(int)ord.size();i++)\n\
    \      for(auto &p:vs[ord[i]].nxt) ord.push_back(p.second);\n  }\n\n  void calc_count(){\n\
    \    for(int i=(int)ord.size()-1;i>=0;i--)\n      vs[vs[ord[i]].suf].cnt+=vs[ord[i]].cnt;\n\
    \  }\n\n  size_t size()const{return n;}\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: string/palindromictree.cpp
  requiredBy: []
  timestamp: '2020-02-15 16:13:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2292.test.cpp
  - test/yukicoder/0399.test.cpp
documentation_of: string/palindromictree.cpp
layout: document
redirect_from:
- /library/string/palindromictree.cpp
- /library/string/palindromictree.cpp.html
title: string/palindromictree.cpp
---
