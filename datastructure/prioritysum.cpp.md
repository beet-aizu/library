---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc074/tasks/arc074_b
    - https://codeforces.com/contest/1119/problem/F
  bundledCode: "#line 1 \"datastructure/prioritysum.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n//BEGIN CUT HERE\n// return sum of top K element (default:\
    \ maximum)\ntemplate<typename T, T identity, typename V=vector<T>,\n         typename\
    \ C1=less<T>, typename C2=greater<T> >\nstruct PrioritySum{\n  size_t num;\n \
    \ T sum;\n  priority_queue<T, V, C1> pq1;\n  priority_queue<T, V, C2> pq2;\n \
    \ PrioritySum():num(0),sum(identity){}\n  PrioritySum(size_t num):num(num),sum(identity){}\n\
    \n  void resolve(){\n    assert(size()>=num);\n    while(pq2.size()<num){\n  \
    \    sum+=pq1.top();\n      pq2.emplace(pq1.top());\n      pq1.pop();\n    }\n\
    \    while(pq2.size()>num){\n      sum-=pq2.top();\n      pq1.emplace(pq2.top());\n\
    \      pq2.pop();\n    }\n    if(pq1.empty()||pq2.empty()) return;\n    while(C2()(pq1.top(),pq2.top())){\n\
    \      T t1=pq1.top();pq1.pop();\n      T t2=pq2.top();pq2.pop();\n      sum+=t1;\n\
    \      sum-=t2;\n      pq1.emplace(t2);\n      pq2.emplace(t1);\n    }\n  }\n\n\
    \  T query(){resolve();return sum;}\n\n  void push(const T &x){pq1.emplace(x);}\n\
    \  void expand(){num++;}\n  void shrink(){assert(num);num--;}\n\n  size_t size()const{return\
    \ pq1.size()+pq2.size();}\n};\ntemplate<typename T>\nusing MaximumSum=PrioritySum<T,\
    \ T(0), vector<T>, less<T>, greater<T> >;\ntemplate<typename T>\nusing MinimumSum=PrioritySum<T,\
    \ T(0), vector<T>, greater<T>, less<T> >;\n\n//END CUT HERE\n\nstruct FastIO{\n\
    \  FastIO(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n  }\n}fastio_beet;\n\
    \ntemplate<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}\n\
    template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}\n\
    \n//INSERT ABOVE HERE\nsigned ARC074_D(){\n  using ll = long long;\n\n  int n;\n\
    \  cin>>n;\n  vector<ll> a(3*n);\n  for(int i=0;i<3*n;i++) cin>>a[i];\n\n  MaximumSum<ll>\
    \ ps1(n);\n  vector<ll> dp1(3*n);\n  for(int i=0;i<3*n;i++){\n    if(i>=n) dp1[i]=ps1.query();\n\
    \    ps1.push(a[i]);\n  }\n\n  MinimumSum<ll> ps2(n);\n  vector<ll> dp2(3*n);\n\
    \  for(int i=3*n-1;i>=0;i--){\n    ps2.push(a[i]);\n    if(i<=2*n) dp2[i]=ps2.query();\n\
    \  }\n\n  ll ans=dp1[n]-dp2[n];\n  for(int i=n;i<=2*n;i++) chmax(ans,dp1[i]-dp2[i]);\n\
    \n  cout<<ans<<endl;\n  return 0;\n}\n/*\n  verified on 2019/04/09\n  https://atcoder.jp/contests/arc074/tasks/arc074_b\n\
    */\n\nsigned CGR002_F(){\n  using ll = long long;\n  using P = pair<ll, ll>;\n\
    \  int n;\n  cin>>n;\n  vector<vector<P> > G(n);\n  for(int i=1;i<n;i++){\n  \
    \  ll a,b,c;\n    cin>>a>>b>>c;\n    a--;b--;\n    G[a].emplace_back(b,c);\n \
    \   G[b].emplace_back(a,c);\n  }\n\n  auto cmp=[&](P a,P b){\n             return\
    \ G[a.first].size()>G[b.first].size();\n           };\n  for(auto &v:G)\n    sort(v.begin(),v.end(),cmp);\n\
    \n  vector<vector<int> > alive(n),death(n);\n  for(int i=0;i<n;i++){\n    for(int\
    \ j=0;j<=(int)G[i].size();j++)\n      alive[j].emplace_back(i);\n    death[G[i].size()].emplace_back(i);\n\
    \  }\n\n  vector<MinimumSum<ll> > ms(n);\n\n  vector<int> par(n,-1),cst(n,0),children(n,0);\n\
    \  auto dfs=\n    [&](int v,int p,auto func)->void{\n      for(auto e:G[v]){\n\
    \        ll u=e.first,c=e.second;\n        if(u==p) continue;\n        par[u]=v;\n\
    \        cst[u]=c;\n        children[v]++;\n        func(u,v,func);\n      }\n\
    \    };\n  dfs(0,-1,dfs);\n\n  const ll INF = 1e18;\n\n  vector<int> used(n,0),dead(n,0);\n\
    \  auto dfs2=\n    [&](int v,int p,int t,auto func)->P{\n      used[v]=1;\n  \
    \    vector<ll> res;\n      ll sum=0;\n      for(auto e:G[v]){\n        ll u=e.first,c=e.second;\n\
    \        if(u==p) continue;\n        if(dead[u]) break;\n        P tmp=func(u,v,t,func);\n\
    \        sum+=tmp.second;\n        res.emplace_back((tmp.first+c)-tmp.second);\n\
    \      }\n      sort(res.begin(),res.end());\n\n      ll x=INF,y=INF,z=0;\n  \
    \    int num=children[v]-t;\n      assert(num>=-1);\n      for(int i=0;i<=(int)res.size();i++){\n\
    \        int j=max(num-i,0);\n        if(j<=(int)ms[v].size()){\n          while((int)ms[v].num<j)\
    \ ms[v].expand();\n          while((int)ms[v].num>j) ms[v].shrink();\n       \
    \   chmin(x,sum+z+ms[v].query());\n        }\n        int k=max(num-i+1,0);\n\
    \        if(k<=(int)ms[v].size()){\n          while((int)ms[v].num<k) ms[v].expand();\n\
    \          while((int)ms[v].num>k) ms[v].shrink();\n          chmin(y,sum+z+ms[v].query());\n\
    \        }\n        if(i<(int)res.size()) z+=res[i];\n      }\n      return P(x,y);\n\
    \    };\n\n  for(int t=0;t<n;t++){\n    if(t) cout<<\" \";\n    ll res=0;\n  \
    \  for(int v:alive[t]){\n      if(used[v]) continue;\n      int u=v;\n      while(~par[u]&&!dead[par[u]])\
    \ u=par[u];\n      P tmp=dfs2(u,par[u],t,dfs2);\n      res+=min(tmp.first+cst[u],tmp.second);\n\
    \    }\n\n    cout<<res;\n    for(int v:alive[t]) used[v]=0;\n    for(int v:death[t]){\n\
    \      dead[v]=1;\n      for(auto e:G[v])\n        if(e.first==par[v])\n     \
    \     ms[e.first].push(e.second);\n    }\n  }\n  cout<<endl;\n  return 0;\n}\n\
    /*\n  verified on 2019/04/10\n  https://codeforces.com/contest/1119/problem/F\n\
    */\n\nsigned main(){\n  //ARC074_D();\n  //CGR002_F();\n  return 0;\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n//BEGIN CUT HERE\n// return\
    \ sum of top K element (default: maximum)\ntemplate<typename T, T identity, typename\
    \ V=vector<T>,\n         typename C1=less<T>, typename C2=greater<T> >\nstruct\
    \ PrioritySum{\n  size_t num;\n  T sum;\n  priority_queue<T, V, C1> pq1;\n  priority_queue<T,\
    \ V, C2> pq2;\n  PrioritySum():num(0),sum(identity){}\n  PrioritySum(size_t num):num(num),sum(identity){}\n\
    \n  void resolve(){\n    assert(size()>=num);\n    while(pq2.size()<num){\n  \
    \    sum+=pq1.top();\n      pq2.emplace(pq1.top());\n      pq1.pop();\n    }\n\
    \    while(pq2.size()>num){\n      sum-=pq2.top();\n      pq1.emplace(pq2.top());\n\
    \      pq2.pop();\n    }\n    if(pq1.empty()||pq2.empty()) return;\n    while(C2()(pq1.top(),pq2.top())){\n\
    \      T t1=pq1.top();pq1.pop();\n      T t2=pq2.top();pq2.pop();\n      sum+=t1;\n\
    \      sum-=t2;\n      pq1.emplace(t2);\n      pq2.emplace(t1);\n    }\n  }\n\n\
    \  T query(){resolve();return sum;}\n\n  void push(const T &x){pq1.emplace(x);}\n\
    \  void expand(){num++;}\n  void shrink(){assert(num);num--;}\n\n  size_t size()const{return\
    \ pq1.size()+pq2.size();}\n};\ntemplate<typename T>\nusing MaximumSum=PrioritySum<T,\
    \ T(0), vector<T>, less<T>, greater<T> >;\ntemplate<typename T>\nusing MinimumSum=PrioritySum<T,\
    \ T(0), vector<T>, greater<T>, less<T> >;\n\n//END CUT HERE\n\nstruct FastIO{\n\
    \  FastIO(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n  }\n}fastio_beet;\n\
    \ntemplate<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}\n\
    template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}\n\
    \n//INSERT ABOVE HERE\nsigned ARC074_D(){\n  using ll = long long;\n\n  int n;\n\
    \  cin>>n;\n  vector<ll> a(3*n);\n  for(int i=0;i<3*n;i++) cin>>a[i];\n\n  MaximumSum<ll>\
    \ ps1(n);\n  vector<ll> dp1(3*n);\n  for(int i=0;i<3*n;i++){\n    if(i>=n) dp1[i]=ps1.query();\n\
    \    ps1.push(a[i]);\n  }\n\n  MinimumSum<ll> ps2(n);\n  vector<ll> dp2(3*n);\n\
    \  for(int i=3*n-1;i>=0;i--){\n    ps2.push(a[i]);\n    if(i<=2*n) dp2[i]=ps2.query();\n\
    \  }\n\n  ll ans=dp1[n]-dp2[n];\n  for(int i=n;i<=2*n;i++) chmax(ans,dp1[i]-dp2[i]);\n\
    \n  cout<<ans<<endl;\n  return 0;\n}\n/*\n  verified on 2019/04/09\n  https://atcoder.jp/contests/arc074/tasks/arc074_b\n\
    */\n\nsigned CGR002_F(){\n  using ll = long long;\n  using P = pair<ll, ll>;\n\
    \  int n;\n  cin>>n;\n  vector<vector<P> > G(n);\n  for(int i=1;i<n;i++){\n  \
    \  ll a,b,c;\n    cin>>a>>b>>c;\n    a--;b--;\n    G[a].emplace_back(b,c);\n \
    \   G[b].emplace_back(a,c);\n  }\n\n  auto cmp=[&](P a,P b){\n             return\
    \ G[a.first].size()>G[b.first].size();\n           };\n  for(auto &v:G)\n    sort(v.begin(),v.end(),cmp);\n\
    \n  vector<vector<int> > alive(n),death(n);\n  for(int i=0;i<n;i++){\n    for(int\
    \ j=0;j<=(int)G[i].size();j++)\n      alive[j].emplace_back(i);\n    death[G[i].size()].emplace_back(i);\n\
    \  }\n\n  vector<MinimumSum<ll> > ms(n);\n\n  vector<int> par(n,-1),cst(n,0),children(n,0);\n\
    \  auto dfs=\n    [&](int v,int p,auto func)->void{\n      for(auto e:G[v]){\n\
    \        ll u=e.first,c=e.second;\n        if(u==p) continue;\n        par[u]=v;\n\
    \        cst[u]=c;\n        children[v]++;\n        func(u,v,func);\n      }\n\
    \    };\n  dfs(0,-1,dfs);\n\n  const ll INF = 1e18;\n\n  vector<int> used(n,0),dead(n,0);\n\
    \  auto dfs2=\n    [&](int v,int p,int t,auto func)->P{\n      used[v]=1;\n  \
    \    vector<ll> res;\n      ll sum=0;\n      for(auto e:G[v]){\n        ll u=e.first,c=e.second;\n\
    \        if(u==p) continue;\n        if(dead[u]) break;\n        P tmp=func(u,v,t,func);\n\
    \        sum+=tmp.second;\n        res.emplace_back((tmp.first+c)-tmp.second);\n\
    \      }\n      sort(res.begin(),res.end());\n\n      ll x=INF,y=INF,z=0;\n  \
    \    int num=children[v]-t;\n      assert(num>=-1);\n      for(int i=0;i<=(int)res.size();i++){\n\
    \        int j=max(num-i,0);\n        if(j<=(int)ms[v].size()){\n          while((int)ms[v].num<j)\
    \ ms[v].expand();\n          while((int)ms[v].num>j) ms[v].shrink();\n       \
    \   chmin(x,sum+z+ms[v].query());\n        }\n        int k=max(num-i+1,0);\n\
    \        if(k<=(int)ms[v].size()){\n          while((int)ms[v].num<k) ms[v].expand();\n\
    \          while((int)ms[v].num>k) ms[v].shrink();\n          chmin(y,sum+z+ms[v].query());\n\
    \        }\n        if(i<(int)res.size()) z+=res[i];\n      }\n      return P(x,y);\n\
    \    };\n\n  for(int t=0;t<n;t++){\n    if(t) cout<<\" \";\n    ll res=0;\n  \
    \  for(int v:alive[t]){\n      if(used[v]) continue;\n      int u=v;\n      while(~par[u]&&!dead[par[u]])\
    \ u=par[u];\n      P tmp=dfs2(u,par[u],t,dfs2);\n      res+=min(tmp.first+cst[u],tmp.second);\n\
    \    }\n\n    cout<<res;\n    for(int v:alive[t]) used[v]=0;\n    for(int v:death[t]){\n\
    \      dead[v]=1;\n      for(auto e:G[v])\n        if(e.first==par[v])\n     \
    \     ms[e.first].push(e.second);\n    }\n  }\n  cout<<endl;\n  return 0;\n}\n\
    /*\n  verified on 2019/04/10\n  https://codeforces.com/contest/1119/problem/F\n\
    */\n\nsigned main(){\n  //ARC074_D();\n  //CGR002_F();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/prioritysum.cpp
  requiredBy: []
  timestamp: '2019-12-17 21:51:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/prioritysum.cpp
layout: document
redirect_from:
- /library/datastructure/prioritysum.cpp
- /library/datastructure/prioritysum.cpp.html
title: datastructure/prioritysum.cpp
---
