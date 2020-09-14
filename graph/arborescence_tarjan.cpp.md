---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_B.tarjan.test.cpp
    title: test/aoj/GRL_2_B.tarjan.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"graph/arborescence_tarjan.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct Arborescence{\n\
    \  struct SkewHeap{\n    using P = pair<T, int>;\n    const P INF;\n    const\
    \ T add_identity;\n    SkewHeap(T inf):INF(inf,-1),add_identity(0){}\n\n    struct\
    \ Node{\n      Node *l,*r;\n      P val;\n      T add;\n      Node(P val,T add):val(val),add(add){l=r=nullptr;}\n\
    \    };\n\n    P reflect(P x,T y){return P(x.first+y,x.second);}\n\n    void eval(Node\
    \ *a){\n      if(a==nullptr) return;\n      if(a->add==add_identity) return;\n\
    \      if(a->l) a->l->add+=a->add;\n      if(a->r) a->r->add+=a->add;\n      a->val=reflect(a->val,a->add);\n\
    \      a->add=add_identity;\n    }\n\n    P top(Node *a){\n      return a?reflect(a->val,a->add):INF;\n\
    \    }\n\n    P snd(Node *a){\n      eval(a);\n      return a?min(top(a->l),top(a->r)):INF;\n\
    \    }\n\n    Node* add(Node *a,T d){\n      if(a) a->add+=d;\n      return a;\n\
    \    }\n\n    Node* push(T v,int i){\n      return new Node(P(v,i),add_identity);\n\
    \    }\n\n    Node* meld(Node *a,Node *b){\n      if(!a||!b) return a?a:b;\n \
    \     if(top(b)<top(a)) swap(a,b);\n      eval(a);\n      a->r=meld(a->r,b);\n\
    \      swap(a->l,a->r);\n      return a;\n    }\n\n    Node* pop(Node* a){\n \
    \     eval(a);\n      auto res=meld(a->l,a->r);\n      delete a;\n      return\
    \ res;\n    }\n  };\n\n  struct UnionFind{\n    vector<int> r,p;\n    UnionFind(){}\n\
    \    UnionFind(int sz):r(sz,1),p(sz,0){iota(p.begin(),p.end(),0);}\n    int find(int\
    \ x){\n      return (x==p[x]?x:p[x]=find(p[x]));\n    }\n    bool same(int x,int\
    \ y){\n      return find(x)==find(y);\n    }\n    void unite(int x,int y){\n \
    \     x=find(x);y=find(y);\n      if(x==y) return;\n      r[x]+=r[y];\n      p[y]=x;\n\
    \    }\n  };\n\n  struct edge{\n    int from,to;\n    T cost;\n    edge(){}\n\
    \    edge(int from,int to,T cost):from(from),to(to),cost(cost){}\n  };\n\n  int\
    \ n;\n  vector<edge> es;\n\n  Arborescence(int n):n(n){};\n\n  void add_edge(int\
    \ from,int to,T cost){\n    es.emplace_back(from,to,cost);\n  }\n\n  T build(int\
    \ r){\n    UnionFind uf(n);\n    const T INF = numeric_limits<T>::max()/2;\n \
    \   SkewHeap hp(INF);\n    vector<typename SkewHeap::Node*> come(n,nullptr);\n\
    \    vector<int> used(n,0),from(n,-1);\n    vector<T> cost(n,-1);\n\n    used[r]=2;\n\
    \    for(int i=0;i<(int)es.size();i++){\n      edge &e=es[i];\n      come[e.to]=hp.meld(come[e.to],hp.push(e.cost,i));\n\
    \    }\n\n    T res=0;\n    for(int i=0;i<n;i++){\n      if(used[i]) continue;\n\
    \      int v=i;\n      vector<int> l;\n      while(used[v]!=2){\n        used[v]=1;\n\
    \        l.emplace_back(v);\n        if(!come[v]) return T(-1);\n        from[v]=uf.find(es[come[v]->val.second].from);\n\
    \        cost[v]=hp.top(come[v]).first;\n        come[v]=hp.pop(come[v]);\n  \
    \      if(from[v]==v) continue;\n\n        res+=cost[v];\n        if(used[from[v]]==1){\n\
    \          int p=v;\n          do{\n            if(come[p]!=nullptr) hp.add(come[p],-cost[p]);\n\
    \            if(p!=v){\n              uf.unite(v,p);\n              come[v]=hp.meld(come[v],come[p]);\n\
    \            }\n            p=uf.find(from[p]);\n          }while(p!=v);\n   \
    \     }else{\n          v=from[v];\n        }\n      }\n      for(int u:l) used[u]=2;\n\
    \    }\n    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT\
    \ ABOVE HERE\nsigned UVA_11183(){\n  using ll = long long;\n  int T;\n  cin>>T;\n\
    \  for(int t=1;t<=T;t++){\n    int n,m;\n    cin>>n>>m;\n    Arborescence<ll>\
    \ G(n);\n    for(int i=0;i<m;i++){\n      int s,t,w;\n      cin>>s>>t>>w;\n  \
    \    G.add_edge(s,t,w);\n    }\n    ll ans=G.build(0);\n    cout<<\"Case #\"<<t<<\"\
    : \";\n    if(ans<0) cout<<\"Possums!\"<<endl;\n    else cout<<ans<<endl;\n  }\n\
    \  return 0;\n}\n/*\n  verified on 2019/12/17\n  https://vjudge.net/problem/UVA-11183\n\
    */\n\n\nsigned main(){\n  //UVA_11183();\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nstruct Arborescence{\n  struct SkewHeap{\n\
    \    using P = pair<T, int>;\n    const P INF;\n    const T add_identity;\n  \
    \  SkewHeap(T inf):INF(inf,-1),add_identity(0){}\n\n    struct Node{\n      Node\
    \ *l,*r;\n      P val;\n      T add;\n      Node(P val,T add):val(val),add(add){l=r=nullptr;}\n\
    \    };\n\n    P reflect(P x,T y){return P(x.first+y,x.second);}\n\n    void eval(Node\
    \ *a){\n      if(a==nullptr) return;\n      if(a->add==add_identity) return;\n\
    \      if(a->l) a->l->add+=a->add;\n      if(a->r) a->r->add+=a->add;\n      a->val=reflect(a->val,a->add);\n\
    \      a->add=add_identity;\n    }\n\n    P top(Node *a){\n      return a?reflect(a->val,a->add):INF;\n\
    \    }\n\n    P snd(Node *a){\n      eval(a);\n      return a?min(top(a->l),top(a->r)):INF;\n\
    \    }\n\n    Node* add(Node *a,T d){\n      if(a) a->add+=d;\n      return a;\n\
    \    }\n\n    Node* push(T v,int i){\n      return new Node(P(v,i),add_identity);\n\
    \    }\n\n    Node* meld(Node *a,Node *b){\n      if(!a||!b) return a?a:b;\n \
    \     if(top(b)<top(a)) swap(a,b);\n      eval(a);\n      a->r=meld(a->r,b);\n\
    \      swap(a->l,a->r);\n      return a;\n    }\n\n    Node* pop(Node* a){\n \
    \     eval(a);\n      auto res=meld(a->l,a->r);\n      delete a;\n      return\
    \ res;\n    }\n  };\n\n  struct UnionFind{\n    vector<int> r,p;\n    UnionFind(){}\n\
    \    UnionFind(int sz):r(sz,1),p(sz,0){iota(p.begin(),p.end(),0);}\n    int find(int\
    \ x){\n      return (x==p[x]?x:p[x]=find(p[x]));\n    }\n    bool same(int x,int\
    \ y){\n      return find(x)==find(y);\n    }\n    void unite(int x,int y){\n \
    \     x=find(x);y=find(y);\n      if(x==y) return;\n      r[x]+=r[y];\n      p[y]=x;\n\
    \    }\n  };\n\n  struct edge{\n    int from,to;\n    T cost;\n    edge(){}\n\
    \    edge(int from,int to,T cost):from(from),to(to),cost(cost){}\n  };\n\n  int\
    \ n;\n  vector<edge> es;\n\n  Arborescence(int n):n(n){};\n\n  void add_edge(int\
    \ from,int to,T cost){\n    es.emplace_back(from,to,cost);\n  }\n\n  T build(int\
    \ r){\n    UnionFind uf(n);\n    const T INF = numeric_limits<T>::max()/2;\n \
    \   SkewHeap hp(INF);\n    vector<typename SkewHeap::Node*> come(n,nullptr);\n\
    \    vector<int> used(n,0),from(n,-1);\n    vector<T> cost(n,-1);\n\n    used[r]=2;\n\
    \    for(int i=0;i<(int)es.size();i++){\n      edge &e=es[i];\n      come[e.to]=hp.meld(come[e.to],hp.push(e.cost,i));\n\
    \    }\n\n    T res=0;\n    for(int i=0;i<n;i++){\n      if(used[i]) continue;\n\
    \      int v=i;\n      vector<int> l;\n      while(used[v]!=2){\n        used[v]=1;\n\
    \        l.emplace_back(v);\n        if(!come[v]) return T(-1);\n        from[v]=uf.find(es[come[v]->val.second].from);\n\
    \        cost[v]=hp.top(come[v]).first;\n        come[v]=hp.pop(come[v]);\n  \
    \      if(from[v]==v) continue;\n\n        res+=cost[v];\n        if(used[from[v]]==1){\n\
    \          int p=v;\n          do{\n            if(come[p]!=nullptr) hp.add(come[p],-cost[p]);\n\
    \            if(p!=v){\n              uf.unite(v,p);\n              come[v]=hp.meld(come[v],come[p]);\n\
    \            }\n            p=uf.find(from[p]);\n          }while(p!=v);\n   \
    \     }else{\n          v=from[v];\n        }\n      }\n      for(int u:l) used[u]=2;\n\
    \    }\n    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT\
    \ ABOVE HERE\nsigned UVA_11183(){\n  using ll = long long;\n  int T;\n  cin>>T;\n\
    \  for(int t=1;t<=T;t++){\n    int n,m;\n    cin>>n>>m;\n    Arborescence<ll>\
    \ G(n);\n    for(int i=0;i<m;i++){\n      int s,t,w;\n      cin>>s>>t>>w;\n  \
    \    G.add_edge(s,t,w);\n    }\n    ll ans=G.build(0);\n    cout<<\"Case #\"<<t<<\"\
    : \";\n    if(ans<0) cout<<\"Possums!\"<<endl;\n    else cout<<ans<<endl;\n  }\n\
    \  return 0;\n}\n/*\n  verified on 2019/12/17\n  https://vjudge.net/problem/UVA-11183\n\
    */\n\n\nsigned main(){\n  //UVA_11183();\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/arborescence_tarjan.cpp
  requiredBy: []
  timestamp: '2019-12-17 22:09:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_B.tarjan.test.cpp
documentation_of: graph/arborescence_tarjan.cpp
layout: document
redirect_from:
- /library/graph/arborescence_tarjan.cpp
- /library/graph/arborescence_tarjan.cpp.html
title: graph/arborescence_tarjan.cpp
---
