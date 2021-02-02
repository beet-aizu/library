---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combinatorics/partitiontable.cpp
    title: combinatorics/partitiontable.cpp
  - icon: ':heavy_check_mark:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_L
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_L
  bundledCode: "#line 1 \"test/aoj/DPL_5_L.test.cpp\"\n// verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_L\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"mod/mint.cpp\"\n\n#line\
    \ 3 \"mod/mint.cpp\"\nusing namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename\
    \ T, T MOD = 1000000007>\nstruct Mint{\n  static constexpr T mod = MOD;\n  T v;\n\
    \  Mint():v(0){}\n  Mint(signed v):v(v){}\n  Mint(long long t){v=t%MOD;if(v<0)\
    \ v+=MOD;}\n\n  Mint pow(long long k){\n    Mint res(1),tmp(v);\n    while(k){\n\
    \      if(k&1) res*=tmp;\n      tmp*=tmp;\n      k>>=1;\n    }\n    return res;\n\
    \  }\n\n  static Mint add_identity(){return Mint(0);}\n  static Mint mul_identity(){return\
    \ Mint(1);}\n\n  Mint inv(){return pow(MOD-2);}\n\n  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return\
    \ *this;}\n  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}\n\
    \  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}\n  Mint& operator/=(Mint\
    \ a){return (*this)*=a.inv();}\n\n  Mint operator+(Mint a) const{return Mint(v)+=a;}\n\
    \  Mint operator-(Mint a) const{return Mint(v)-=a;}\n  Mint operator*(Mint a)\
    \ const{return Mint(v)*=a;}\n  Mint operator/(Mint a) const{return Mint(v)/=a;}\n\
    \n  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}\n\n  bool operator==(const\
    \ Mint a)const{return v==a.v;}\n  bool operator!=(const Mint a)const{return v!=a.v;}\n\
    \  bool operator <(const Mint a)const{return v <a.v;}\n\n  static Mint comb(long\
    \ long n,int k){\n    Mint num(1),dom(1);\n    for(int i=0;i<k;i++){\n      num*=Mint(n-i);\n\
    \      dom*=Mint(i+1);\n    }\n    return num/dom;\n  }\n};\ntemplate<typename\
    \ T, T MOD> constexpr T Mint<T, MOD>::mod;\ntemplate<typename T, T MOD>\nostream&\
    \ operator<<(ostream &os,Mint<T, MOD> m){os<<m.v;return os;}\n//END CUT HERE\n\
    #ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n#line 1 \"combinatorics/partitiontable.cpp\"\
    \n\n#line 3 \"combinatorics/partitiontable.cpp\"\nusing namespace std;\n#endif\n\
    \n//BEGIN CUT HERE\ntemplate<typename M>\nstruct PartitionTable{\n  vector< vector<M>\
    \ > dp;\n  PartitionTable(int h,int w):dp(h+1,vector<M>(w+1,0)){\n    dp[0][0]=M(1);\n\
    \    for(int i=0;i<=h;i++){\n      for(int j=1;j<=w;j++){\n        dp[i][j]=dp[i][j-1];\n\
    \        if(i-j>=0) dp[i][j]+=dp[i-j][j];\n      }\n    }\n  }\n\n  // put n identical\
    \ balls into k identical boxes\n  M operator()(int n,int k){return dp[n][k];}\n\
    \n  // put n identical balls into some boxes\n  M operator()(int n){return dp[n][n];}\n\
    };\n//END CUT HERE\n\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n\
    #endif\n#line 9 \"test/aoj/DPL_5_L.test.cpp\"\n#undef call_from_test\n\nsigned\
    \ main(){\n  int n,k;\n  scanf(\"%d %d\",&n,&k);\n  PartitionTable<Mint<int>>\
    \ P(n,k);\n  printf(\"%d\\n\",k<=n?P(n-k,k).v:0);\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_L\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../mod/mint.cpp\"\n#include \"../../combinatorics/partitiontable.cpp\"\n\
    #undef call_from_test\n\nsigned main(){\n  int n,k;\n  scanf(\"%d %d\",&n,&k);\n\
    \  PartitionTable<Mint<int>> P(n,k);\n  printf(\"%d\\n\",k<=n?P(n-k,k).v:0);\n\
    \  return 0;\n}\n"
  dependsOn:
  - mod/mint.cpp
  - combinatorics/partitiontable.cpp
  isVerificationFile: true
  path: test/aoj/DPL_5_L.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 13:13:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_5_L.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_L.test.cpp
- /verify/test/aoj/DPL_5_L.test.cpp.html
title: test/aoj/DPL_5_L.test.cpp
---
