#include<bits/stdc++.h>
using namespace std;
#define int long long
//BEGIN CUT HERE
struct QuickFind{
  vector<int> r,p;
  vector<vector<int> > v;
  QuickFind(){}
  QuickFind(int size){init(size);}
  void init(int size){
    r.resize(size,0);
    p.resize(size,0);
    v.resize(size);
    for(int i=0;i<size;i++){
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
verified on 2017/04/28
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp
*/
