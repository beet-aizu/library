---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"bbst/pb_ds_tree.cpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include<ext/pb_ds/tree_policy.hpp>\n#include<ext/pb_ds/tag_and_trait.hpp>\nusing\
    \ namespace __gnu_pbds;\ntemplate <typename T>\nusing gtree = tree<T, null_type,\
    \ less<T>, rb_tree_tag,\n                   tree_order_statistics_node_update>;\n\
    // usage:\n// find_by_order(int k):\n// return the iterator of k-th smallest element\
    \ (0-indexed)\n// order_of_key(T key):  return the index of key in tree\n//END\
    \ CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\n#include<ext/pb_ds/assoc_container.hpp>\n#include<ext/pb_ds/tree_policy.hpp>\n\
    #include<ext/pb_ds/tag_and_trait.hpp>\nusing namespace __gnu_pbds;\ntemplate <typename\
    \ T>\nusing gtree = tree<T, null_type, less<T>, rb_tree_tag,\n               \
    \    tree_order_statistics_node_update>;\n// usage:\n// find_by_order(int k):\n\
    // return the iterator of k-th smallest element (0-indexed)\n// order_of_key(T\
    \ key):  return the index of key in tree\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3117.test.cpp
    title: test/aoj/3117.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0563.test.cpp
    title: test/aoj/0563.test.cpp
  isVerificationFile: false
  path: bbst/pb_ds_tree.cpp
  requiredBy: []
  timestamp: '2019-12-26 22:03:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - test/aoj/3117.test.cpp
  - test/aoj/0563.test.cpp
documentation_of: bbst/pb_ds_tree.cpp
layout: document
redirect_from:
- /library/bbst/pb_ds_tree.cpp
- /library/bbst/pb_ds_tree.cpp.html
title: bbst/pb_ds_tree.cpp
---
