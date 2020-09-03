---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_integer
  bundledCode: "#line 1 \"test/yosupo/kth_root_integer.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/kth_root_integer\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"tools/int128.cpp\"\n\
    \n#line 3 \"tools/int128.cpp\"\nusing namespace std;\n/*\n  multiprecision:\n\
    \  #include <boost/multiprecision/cpp_int.hpp>\n  using ll = boost::multiprecision::cpp_int;\n\
    */\n#endif\n//BEGIN CUT HERE\n__int128_t abs128(__int128_t val){return val<0?-val:val;}\n\
    \nostream &operator<<(ostream &os,__int128_t val){\n  if(ostream::sentry(os)){\n\
    \    __uint128_t tmp=abs128(val);\n    char buf[64];\n    char *d=end(buf);\n\
    \    do{\n      --d;\n      *d=char(tmp%10+'0');\n      tmp/=10;\n    }while(tmp);\n\
    \    if(val<0) *--d='-';\n    int len=end(buf)-d;\n    if(os.rdbuf()->sputn(d,len)!=len){\n\
    \      os.setstate(ios_base::badbit);\n    }\n  }\n  return os;\n}\n\nistream\
    \ &operator>>(istream &is,__int128_t &val){\n  string s;\n  is>>s;\n  val=0;\n\
    \  for(int i=0;i<(int)s.size();i++)\n    if(isdigit(s[i])) val=val*10+s[i]-'0';\n\
    \  if(s[0]=='-') val*=-1;\n  return is;\n}\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 8 \"test/yosupo/kth_root_integer.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int T;\n  cin>>T;\n\n  using ll = __int128_t;\n  for(int t=0;t<T;t++){\n \
    \   ll A,K;\n    cin>>A>>K;\n\n    ll L=0,R=A+1;\n    while(L+1<R){\n      ll\
    \ M=(L+R)>>1;\n\n      ll res=1;\n      for(int i=0;i<K;i++){\n        res*=M;\n\
    \        if(res>A) break;\n      }\n\n      if(res<=A) L=M;\n      else R=M;\n\
    \    }\n\n    cout<<L<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\n\n\
    #include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tools/int128.cpp\"\n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n\n  int T;\n  cin>>T;\n\n  using ll = __int128_t;\n\
    \  for(int t=0;t<T;t++){\n    ll A,K;\n    cin>>A>>K;\n\n    ll L=0,R=A+1;\n \
    \   while(L+1<R){\n      ll M=(L+R)>>1;\n\n      ll res=1;\n      for(int i=0;i<K;i++){\n\
    \        res*=M;\n        if(res>A) break;\n      }\n\n      if(res<=A) L=M;\n\
    \      else R=M;\n    }\n\n    cout<<L<<\"\\n\";\n  }\n  cout<<flush;\n  return\
    \ 0;\n}\n"
  dependsOn:
  - tools/int128.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: tools/int128.cpp
    title: tools/int128.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/yosupo/kth_root_integer.test.cpp
  requiredBy: []
  timestamp: '2020-03-05 21:02:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/yosupo/kth_root_integer.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/kth_root_integer.test.cpp
- /verify/test/yosupo/kth_root_integer.test.cpp.html
title: test/yosupo/kth_root_integer.test.cpp
---
