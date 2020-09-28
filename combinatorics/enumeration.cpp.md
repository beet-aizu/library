---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: combinatorics/bell.cpp
    title: combinatorics/bell.cpp
  - icon: ':heavy_check_mark:'
    path: combinatorics/bernoulli.cpp
    title: combinatorics/bernoulli.cpp
  - icon: ':heavy_check_mark:'
    path: combinatorics/partition.cpp
    title: combinatorics/partition.cpp
  - icon: ':heavy_check_mark:'
    path: combinatorics/stirling1st.cpp
    title: combinatorics/stirling1st.cpp
  - icon: ':heavy_check_mark:'
    path: combinatorics/stirling2nd.cpp
    title: combinatorics/stirling2nd.cpp
  - icon: ':heavy_check_mark:'
    path: combinatorics/surjection.cpp
    title: combinatorics/surjection.cpp
  - icon: ':heavy_check_mark:'
    path: graph/lowlink.cpp
    title: graph/lowlink.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/formalpowerseries.cpp
    title: polynomial/formalpowerseries.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2985.garner.test.cpp
    title: test/aoj/2985.garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2985.test.cpp
    title: test/aoj/2985.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3072.test.cpp
    title: test/aoj/3072.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_A.test.cpp
    title: test/aoj/DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_B.test.cpp
    title: test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_C.test.cpp
    title: test/aoj/DPL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_D.test.cpp
    title: test/aoj/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_F.test.cpp
    title: test/aoj/DPL_5_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_G.test.cpp
    title: test/aoj/DPL_5_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_H.test.cpp
    title: test/aoj/DPL_5_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_I.test.cpp
    title: test/aoj/DPL_5_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_J.test.cpp
    title: test/aoj/DPL_5_J.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_K.test.cpp
    title: test/aoj/DPL_5_K.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bernoulli_number.test.cpp
    title: test/yosupo/bernoulli_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/partition_function.test.cpp
    title: test/yosupo/partition_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_taylor_shift.test.cpp
    title: test/yosupo/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/sqrt_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_number_of_the_first_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0444.test.cpp
    title: test/yukicoder/0444.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2744.test.cpp
    title: test/yukicoder/2744.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2772.test.cpp
    title: test/yukicoder/2772.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"combinatorics/enumeration.cpp\"\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename\
    \ M_>\nclass Enumeration{\n  using M = M_;\nprotected:\n  static vector<M> fact,finv,invs;\n\
    public:\n  static void init(int n){\n    n=min<decltype(M::mod)>(n,M::mod-1);\n\
    \n    int m=fact.size();\n    if(n<m) return;\n\n    fact.resize(n+1,1);\n   \
    \ finv.resize(n+1,1);\n    invs.resize(n+1,1);\n\n    if(m==0) m=1;\n    for(int\
    \ i=m;i<=n;i++) fact[i]=fact[i-1]*M(i);\n    finv[n]=M(1)/fact[n];\n    for(int\
    \ i=n;i>=m;i--) finv[i-1]=finv[i]*M(i);\n    for(int i=m;i<=n;i++) invs[i]=finv[i]*fact[i-1];\n\
    \  }\n\n  static M Fact(int n){\n    init(n);\n    return fact[n];\n  }\n  static\
    \ M Finv(int n){\n    init(n);\n    return finv[n];\n  }\n  static M Invs(int\
    \ n){\n    init(n);\n    return invs[n];\n  }\n\n  static M C(int n,int k){\n\
    \    if(n<k||k<0) return M(0);\n    init(n);\n    return fact[n]*finv[n-k]*finv[k];\n\
    \  }\n\n  static M P(int n,int k){\n    if(n<k||k<0) return M(0);\n    init(n);\n\
    \    return fact[n]*finv[n-k];\n  }\n\n  // put n identical balls into k distinct\
    \ boxes\n  static M H(int n,int k){\n    if(n<0||k<0) return M(0);\n    if(!n&&!k)\
    \ return M(1);\n    init(n+k);\n    return C(n+k-1,n);\n  }\n};\ntemplate<typename\
    \ M>\nvector<M> Enumeration<M>::fact=vector<M>();\ntemplate<typename M>\nvector<M>\
    \ Enumeration<M>::finv=vector<M>();\ntemplate<typename M>\nvector<M> Enumeration<M>::invs=vector<M>();\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n\n//BEGIN CUT HERE\ntemplate<typename M_>\nclass Enumeration{\n\
    \  using M = M_;\nprotected:\n  static vector<M> fact,finv,invs;\npublic:\n  static\
    \ void init(int n){\n    n=min<decltype(M::mod)>(n,M::mod-1);\n\n    int m=fact.size();\n\
    \    if(n<m) return;\n\n    fact.resize(n+1,1);\n    finv.resize(n+1,1);\n   \
    \ invs.resize(n+1,1);\n\n    if(m==0) m=1;\n    for(int i=m;i<=n;i++) fact[i]=fact[i-1]*M(i);\n\
    \    finv[n]=M(1)/fact[n];\n    for(int i=n;i>=m;i--) finv[i-1]=finv[i]*M(i);\n\
    \    for(int i=m;i<=n;i++) invs[i]=finv[i]*fact[i-1];\n  }\n\n  static M Fact(int\
    \ n){\n    init(n);\n    return fact[n];\n  }\n  static M Finv(int n){\n    init(n);\n\
    \    return finv[n];\n  }\n  static M Invs(int n){\n    init(n);\n    return invs[n];\n\
    \  }\n\n  static M C(int n,int k){\n    if(n<k||k<0) return M(0);\n    init(n);\n\
    \    return fact[n]*finv[n-k]*finv[k];\n  }\n\n  static M P(int n,int k){\n  \
    \  if(n<k||k<0) return M(0);\n    init(n);\n    return fact[n]*finv[n-k];\n  }\n\
    \n  // put n identical balls into k distinct boxes\n  static M H(int n,int k){\n\
    \    if(n<0||k<0) return M(0);\n    if(!n&&!k) return M(1);\n    init(n+k);\n\
    \    return C(n+k-1,n);\n  }\n};\ntemplate<typename M>\nvector<M> Enumeration<M>::fact=vector<M>();\n\
    template<typename M>\nvector<M> Enumeration<M>::finv=vector<M>();\ntemplate<typename\
    \ M>\nvector<M> Enumeration<M>::invs=vector<M>();\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: combinatorics/enumeration.cpp
  requiredBy:
  - polynomial/formalpowerseries.cpp
  - combinatorics/partition.cpp
  - combinatorics/bernoulli.cpp
  - combinatorics/stirling1st.cpp
  - combinatorics/bell.cpp
  - combinatorics/surjection.cpp
  - combinatorics/stirling2nd.cpp
  - graph/lowlink.cpp
  timestamp: '2020-03-12 17:02:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_C.test.cpp
  - test/aoj/2985.garner.test.cpp
  - test/aoj/DPL_5_H.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_K.test.cpp
  - test/aoj/3072.test.cpp
  - test/aoj/DPL_5_I.test.cpp
  - test/aoj/DPL_5_E.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/2985.test.cpp
  - test/aoj/DPL_5_J.test.cpp
  - test/aoj/DPL_5_A.test.cpp
  - test/aoj/DPL_5_G.test.cpp
  - test/aoj/DPL_5_F.test.cpp
  - test/yukicoder/0444.test.cpp
  - test/yukicoder/2772.test.cpp
  - test/yukicoder/2744.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
  - test/yosupo/polynomial_interpolation.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/multipoint_evaluation.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - test/yosupo/bernoulli_number.test.cpp
  - test/yosupo/partition_function.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/polynomial_taylor_shift.test.cpp
  - test/yosupo/stirling_number_of_the_first_kind.test.cpp
documentation_of: combinatorics/enumeration.cpp
layout: document
redirect_from:
- /library/combinatorics/enumeration.cpp
- /library/combinatorics/enumeration.cpp.html
title: combinatorics/enumeration.cpp
---
