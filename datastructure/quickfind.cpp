#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct QuickFind{
  int n;
  vector<int> rs,ps;
  vector<vector<int> > vs;
  QuickFind(){}
  QuickFind(int sz):n(sz),rs(sz,1),ps(sz),vs(sz){
    iota(ps.begin(),ps.end(),0);
    for(int i=0;i<n;i++) vs[i].assign(1,i);
  }
  int find(int x) const{return ps[x];}
  bool same(int x,int y) const{
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=ps[x];y=ps[y];
    if(x==y) return;
    if(rs[x]<rs[y]) swap(x,y);
    rs[x]+=rs[y];
    for(int e:vs[y]){
      ps[e]=x;
      vs[x].push_back(e);
    }
    vs[y].clear();
    vs[y].shrink_to_fit();
  }
  const vector<int>& elements(int x) const{return vs[x];}
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
