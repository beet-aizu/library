---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/zalgorithm.cpp
    title: string/zalgorithm.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3081.test.cpp
    title: test/aoj/3081.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/runenumerate.test.cpp
    title: test/yosupo/runenumerate.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/run.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"zalgorithm.cpp\"\n#undef call_from_test\n\n\
    #endif\n//BEGIN CUT HERE\nnamespace Run{\n  using T = tuple<int, int, int>;\n\
    \  using P = pair<int, int>;\n  vector<vector<P>> run;\n\n  template<typename\
    \ C>\n  vector<T> sub(const vector<C> &xs,const vector<C> &ys){\n    auto ps=xs;\n\
    \    auto qs=ys;\n    reverse(ps.begin(),ps.end());\n    qs.insert(qs.end(),xs.begin(),xs.end());\n\
    \    qs.insert(qs.end(),ys.begin(),ys.end());\n    auto zp=zalgorithm(ps);\n \
    \   auto zq=zalgorithm(qs);\n    vector<T> res;\n    for(int i=0;i<(int)xs.size();i++){\n\
    \      int a=xs.size()-i;\n      int b=i-zp[a];\n      int c=max(0,(int)ys.size()-zq[ys.size()+i]);\n\
    \      if((int)(xs.size()+ys.size())-b-c>=2*a)\n        res.emplace_back(a,b,c);\n\
    \    }\n    return res;\n  }\n\n  template<typename C>\n  void dfs(int l,int r,const\
    \ vector<C> &cs){\n    if(l+1>=r) return;\n    int m=(l+r)>>1;\n    vector<C>\
    \ xs(cs.begin()+l,cs.begin()+m);\n    vector<C> ys(cs.begin()+m,cs.begin()+r);\n\
    \    {\n      auto zs=sub(xs,ys);\n      for(auto w:zs){\n        int a,b,c;\n\
    \        tie(a,b,c)=w;\n        run[a].emplace_back(l+b,r-c);\n      }\n    }\n\
    \    reverse(xs.begin(),xs.end());\n    reverse(ys.begin(),ys.end());\n    {\n\
    \      auto zs=sub(ys,xs);\n      for(auto w:zs){\n        int a,b,c;\n      \
    \  tie(a,b,c)=w;\n        run[a].emplace_back(l+c,r-b);\n      }\n    }\n    dfs(l,m,cs);\n\
    \    dfs(m,r,cs);\n  }\n\n  // return all t (not only minimal)\n  template<typename\
    \ C>\n  vector<vector<P>> enumerate(const vector<C> &cs){\n    int n=cs.size();\n\
    \    run.clear();\n    run.resize(n+1);\n    dfs(0,n,cs);\n\n    auto cmp=[&](P\
    \ a,P b){return P(a.first,-a.second)<P(b.first,-b.second);};\n    for(int i=1;i<=n;i++){\n\
    \      auto &rs=run[i];\n      sort(rs.begin(),rs.end(),cmp);\n      int mx=-1;\n\
    \      vector<P> tmp;\n      for(auto p:rs){\n        if(mx<p.second){\n     \
    \     tmp.emplace_back(p);\n          mx=p.second;\n        }\n      }\n     \
    \ rs=tmp;\n    }\n    return run;\n  }\n\n  vector<vector<P>> enumerate(string\
    \ ss){\n    return enumerate(vector<char>(ss.begin(),ss.end()));\n  }\n};\n//END\
    \ CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn:
  - string/zalgorithm.cpp
  isVerificationFile: false
  path: string/run.cpp
  requiredBy: []
  timestamp: '2021-03-04 17:00:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3081.test.cpp
  - test/yosupo/runenumerate.test.cpp
documentation_of: string/run.cpp
layout: document
redirect_from:
- /library/string/run.cpp
- /library/string/run.cpp.html
title: string/run.cpp
---
