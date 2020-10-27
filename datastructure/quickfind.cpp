#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct QuickFind{
  vector<int> rs,ps;
  vector< vector<int> > vs;
  QuickFind(int n):rs(n,1),ps(n),vs(n){
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
      vs[x].emplace_back(e);
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
