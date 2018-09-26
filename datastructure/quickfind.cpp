#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct QuickFind{
  int n;
  vector<int> r,p;
  vector<vector<int> > v;
  QuickFind(){}
  QuickFind(int sz):n(sz),r(sz),p(sz),v(sz){
    for(int i=0;i<n;i++){
      r[i]=1,p[i]=i;
      v[i].resize(1,i);
    }
  }
  bool same(int x,int y){
    return p[x]==p[y];
  }
  void unite(int x,int y){
    x=p[x];y=p[y];
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    for(int i=0;i<(int)v[y].size();i++){
      p[v[y][i]]=x;
      v[x].push_back(v[y][i]);
    }
    v[y].clear();
  }
};
//END CUT HERE

signed main(){
  int n,q;
  cin>>n>>q;
  QuickFind qf(n);
  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c) cout<<qf.same(x,y)<<endl;
    else qf.unite(x,y);
  }
  return 0;
}
/*
  verified on 2017/10/29
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp
*/
