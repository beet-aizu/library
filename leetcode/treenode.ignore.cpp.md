---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"leetcode/treenode.ignore.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n/**\n * @ignore\n */\n\n//BEGIN CUT HERE\n\nstruct TreeNode\
    \ {\n  int val;\n  TreeNode *left;\n  TreeNode *right;\n  TreeNode(int x) : val(x),\
    \ left(NULL), right(NULL) {}\n};\n\nint dfs(TreeNode* v,int &k,vector<vector<int>\
    \ > &G,vector<int> &x){\n  if(!v) return -1;\n  int s=k++;\n  x.emplace_back(v->val);\n\
    \  G.emplace_back(vector<int>());\n  int a=dfs(v->left,k,G,x);\n  int b=dfs(v->right,k,G,x);\n\
    \  if(~a){\n    G[s].emplace_back(a);\n    G[a].emplace_back(s);\n  }\n  if(~b){\n\
    \    G[s].emplace_back(b);\n    G[b].emplace_back(s);\n  }\n  return s;\n}\n\n\
    void build(TreeNode* v,vector<vector<int> > &G,vector<int> &x){\n  assert(G.empty());\n\
    \  int k=0;\n  dfs(v,k,G,x);\n}\n\n//END CUT HERE\n\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n\n/**\n * @ignore\n */\n\n\
    //BEGIN CUT HERE\n\nstruct TreeNode {\n  int val;\n  TreeNode *left;\n  TreeNode\
    \ *right;\n  TreeNode(int x) : val(x), left(NULL), right(NULL) {}\n};\n\nint dfs(TreeNode*\
    \ v,int &k,vector<vector<int> > &G,vector<int> &x){\n  if(!v) return -1;\n  int\
    \ s=k++;\n  x.emplace_back(v->val);\n  G.emplace_back(vector<int>());\n  int a=dfs(v->left,k,G,x);\n\
    \  int b=dfs(v->right,k,G,x);\n  if(~a){\n    G[s].emplace_back(a);\n    G[a].emplace_back(s);\n\
    \  }\n  if(~b){\n    G[s].emplace_back(b);\n    G[b].emplace_back(s);\n  }\n \
    \ return s;\n}\n\nvoid build(TreeNode* v,vector<vector<int> > &G,vector<int> &x){\n\
    \  assert(G.empty());\n  int k=0;\n  dfs(v,k,G,x);\n}\n\n//END CUT HERE\n\n//INSERT\
    \ ABOVE HERE\nsigned main(){\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: leetcode/treenode.ignore.cpp
  requiredBy: []
  timestamp: '2020-09-04 08:31:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: leetcode/treenode.ignore.cpp
layout: document
redirect_from:
- /library/leetcode/treenode.ignore.cpp
- /library/leetcode/treenode.ignore.cpp.html
title: leetcode/treenode.ignore.cpp
---
