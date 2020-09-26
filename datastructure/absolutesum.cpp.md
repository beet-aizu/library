---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2600.test.cpp
    title: test/yukicoder/2600.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc127/tasks/abc127_f
  bundledCode: "#line 1 \"datastructure/absolutesum.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct AbsoluteSum{\n\
    \  multiset<T> lp,rp;\n  T sum;\n  AbsoluteSum():sum(0){}\n  T insert(T x){\n\
    \    if(lp.empty()){\n      lp.emplace(x);\n      rp.emplace(x);\n      return\
    \ T(0);\n    }\n    auto p=interval();\n    lp.emplace(x);\n    rp.emplace(x);\n\
    \    if(p.first<=x&&x<=p.second) return T(0);\n    if(*lp.rbegin()>*rp.begin()){\n\
    \      T a=*lp.rbegin();\n      T b=*rp.begin();\n      lp.erase(lp.find(a));\n\
    \      rp.erase(rp.find(b));\n      rp.emplace(a);\n      lp.emplace(b);\n   \
    \ }\n    T res=min(abs(p.first-x),abs(p.second-x));\n    sum+=res;\n    return\
    \ res;\n  }\n\n  T erase(T x){\n    assert(lp.count(x)+rp.count(x)>=2);\n    if(lp.count(x)&&rp.count(x)){\n\
    \      lp.erase(lp.find(x));\n      rp.erase(rp.find(x));\n      return T(0);\n\
    \    }\n    if(lp.count(x)){\n      lp.erase(lp.find(x));\n      lp.erase(lp.find(x));\n\
    \      lp.emplace(*rp.begin());\n      rp.erase(rp.begin());\n    }else{\n   \
    \   rp.erase(rp.find(x));\n      rp.erase(rp.find(x));\n      rp.emplace(*lp.rbegin());\n\
    \      lp.erase(lp.rbegin().base());\n    }\n    auto p=interval();\n    if(p.first<=x&&x<=p.second)\
    \ return T(0);\n    T res=min(abs(p.first-x),abs(p.second-x));\n    sum-=res;\n\
    \    return res;\n  }\n\n  pair<T, T> interval(){\n    assert(!lp.empty());\n\
    \    return make_pair(*lp.rbegin(),*rp.begin());\n  }\n\n  T value(){return sum;}\n\
    };\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\n// test interval()\n\
    signed ABC127_F(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int q;\n  cin>>q;\n\
    \  using ll = long long;\n  AbsoluteSum<ll> as;\n  ll sum=0;\n  for(int i=0;i<q;i++){\n\
    \    int t;\n    cin>>t;\n    if(t==1){\n      ll a,b;\n      cin>>a>>b;\n   \
    \   as.insert(a);\n      sum+=b;\n    }\n    if(t==2){\n      cout<<as.interval().first<<\"\
    \ \"<<sum+as.value()<<\"\\n\";\n    }\n  }\n  cout<<flush;\n  return 0;\n}\n/*\n\
    \  verified on 2019/06/19\n  https://atcoder.jp/contests/abc127/tasks/abc127_f\n\
    */\n\nsigned main(){\n  //ABC127_F();\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nstruct AbsoluteSum{\n  multiset<T> lp,rp;\n\
    \  T sum;\n  AbsoluteSum():sum(0){}\n  T insert(T x){\n    if(lp.empty()){\n \
    \     lp.emplace(x);\n      rp.emplace(x);\n      return T(0);\n    }\n    auto\
    \ p=interval();\n    lp.emplace(x);\n    rp.emplace(x);\n    if(p.first<=x&&x<=p.second)\
    \ return T(0);\n    if(*lp.rbegin()>*rp.begin()){\n      T a=*lp.rbegin();\n \
    \     T b=*rp.begin();\n      lp.erase(lp.find(a));\n      rp.erase(rp.find(b));\n\
    \      rp.emplace(a);\n      lp.emplace(b);\n    }\n    T res=min(abs(p.first-x),abs(p.second-x));\n\
    \    sum+=res;\n    return res;\n  }\n\n  T erase(T x){\n    assert(lp.count(x)+rp.count(x)>=2);\n\
    \    if(lp.count(x)&&rp.count(x)){\n      lp.erase(lp.find(x));\n      rp.erase(rp.find(x));\n\
    \      return T(0);\n    }\n    if(lp.count(x)){\n      lp.erase(lp.find(x));\n\
    \      lp.erase(lp.find(x));\n      lp.emplace(*rp.begin());\n      rp.erase(rp.begin());\n\
    \    }else{\n      rp.erase(rp.find(x));\n      rp.erase(rp.find(x));\n      rp.emplace(*lp.rbegin());\n\
    \      lp.erase(lp.rbegin().base());\n    }\n    auto p=interval();\n    if(p.first<=x&&x<=p.second)\
    \ return T(0);\n    T res=min(abs(p.first-x),abs(p.second-x));\n    sum-=res;\n\
    \    return res;\n  }\n\n  pair<T, T> interval(){\n    assert(!lp.empty());\n\
    \    return make_pair(*lp.rbegin(),*rp.begin());\n  }\n\n  T value(){return sum;}\n\
    };\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\n// test interval()\n\
    signed ABC127_F(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int q;\n  cin>>q;\n\
    \  using ll = long long;\n  AbsoluteSum<ll> as;\n  ll sum=0;\n  for(int i=0;i<q;i++){\n\
    \    int t;\n    cin>>t;\n    if(t==1){\n      ll a,b;\n      cin>>a>>b;\n   \
    \   as.insert(a);\n      sum+=b;\n    }\n    if(t==2){\n      cout<<as.interval().first<<\"\
    \ \"<<sum+as.value()<<\"\\n\";\n    }\n  }\n  cout<<flush;\n  return 0;\n}\n/*\n\
    \  verified on 2019/06/19\n  https://atcoder.jp/contests/abc127/tasks/abc127_f\n\
    */\n\nsigned main(){\n  //ABC127_F();\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/absolutesum.cpp
  requiredBy: []
  timestamp: '2020-02-15 16:16:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2600.test.cpp
documentation_of: datastructure/absolutesum.cpp
layout: document
redirect_from:
- /library/datastructure/absolutesum.cpp
- /library/datastructure/absolutesum.cpp.html
title: datastructure/absolutesum.cpp
---
