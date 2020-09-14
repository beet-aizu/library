---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2674.count.test.cpp
    title: test/aoj/2674.count.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"segtree/count/static.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename Key>\nstruct\
    \ SegmentTree{\n  using P = pair<int, Key>;\n  int n;\n  vector< vector<Key> >\
    \ dat;\n  SegmentTree(){}\n  SegmentTree(int n,vector<P> vs):n(n){\n    dat.assign(n<<1,vector<Key>());\n\
    \    for(auto p:vs)\n      dat[p.first+n].emplace_back(p.second);\n\n    for(int\
    \ i=0;i<n;i++)\n      sort(dat[i+n].begin(),dat[i+n].end());\n\n    for(int i=n-1;i;i--){\n\
    \      merge(dat[(i<<1)|0].begin(),dat[(i<<1)|0].end(),\n            dat[(i<<1)|1].begin(),dat[(i<<1)|1].end(),\n\
    \            back_inserter(dat[i]));\n    }\n  }\n\n  // [a, b) * [c, d)\n  inline\
    \ int query(int a,int b,Key c,Key d){\n    int res=0;\n    auto calc=[a,b,c,d](vector<Key>\
    \ &xs){\n      auto latte=lower_bound(xs.begin(),xs.end(),d);\n      auto malta=lower_bound(xs.begin(),xs.end(),c);\n\
    \      return int(latte-malta);\n    };\n    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){\n\
    \      if(l&1) res+=calc(dat[l++]);\n      if(r&1) res+=calc(dat[--r]);\n    }\n\
    \    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename Key>\nstruct SegmentTree{\n  using P = pair<int,\
    \ Key>;\n  int n;\n  vector< vector<Key> > dat;\n  SegmentTree(){}\n  SegmentTree(int\
    \ n,vector<P> vs):n(n){\n    dat.assign(n<<1,vector<Key>());\n    for(auto p:vs)\n\
    \      dat[p.first+n].emplace_back(p.second);\n\n    for(int i=0;i<n;i++)\n  \
    \    sort(dat[i+n].begin(),dat[i+n].end());\n\n    for(int i=n-1;i;i--){\n   \
    \   merge(dat[(i<<1)|0].begin(),dat[(i<<1)|0].end(),\n            dat[(i<<1)|1].begin(),dat[(i<<1)|1].end(),\n\
    \            back_inserter(dat[i]));\n    }\n  }\n\n  // [a, b) * [c, d)\n  inline\
    \ int query(int a,int b,Key c,Key d){\n    int res=0;\n    auto calc=[a,b,c,d](vector<Key>\
    \ &xs){\n      auto latte=lower_bound(xs.begin(),xs.end(),d);\n      auto malta=lower_bound(xs.begin(),xs.end(),c);\n\
    \      return int(latte-malta);\n    };\n    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){\n\
    \      if(l&1) res+=calc(dat[l++]);\n      if(r&1) res+=calc(dat[--r]);\n    }\n\
    \    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/count/static.cpp
  requiredBy: []
  timestamp: '2020-09-03 00:55:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2674.count.test.cpp
documentation_of: segtree/count/static.cpp
layout: document
redirect_from:
- /library/segtree/count/static.cpp
- /library/segtree/count/static.cpp.html
title: segtree/count/static.cpp
---
