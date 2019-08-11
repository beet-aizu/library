#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct QuickFind{
  int n;
  vector<int> r,p;
  vector<vector<int> > v;
  QuickFind(){}
  QuickFind(int sz):n(sz),r(sz,1),p(sz),v(sz){
    iota(p.begin(),p.end(),0);
    for(int i=0;i<n;i++) v[i].assign(1,i);
  }
  int find(int x) const{return p[x];}
  bool same(int x,int y) const{
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=p[x];y=p[y];
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    for(int e:v[y]){
      p[e]=x;
      v[x].push_back(e);
    }
    v[y].clear();
    v[y].shrink_to_fit();
  }
  const vector<int>& elements(int x) const{return v[x];}
};
//END CUT HERE

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
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
  verified on 2019/08/11
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp
*/
