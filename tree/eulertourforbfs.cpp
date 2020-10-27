#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "levelancestor.cpp"
#undef call_from_test

#endif

//BEGIN CUT HERE
struct EulerTourForBFS : LevelAncestor{
  using super = LevelAncestor;
  vector<int> ls;
  vector<vector<int>> H;
  EulerTourForBFS(int n):super(n),ls(n),H(n){}

  using super::par;
  using super::dep;
  void build(int r=0){
    super::build(r);
    int pos=0;
    queue<int> que;
    que.emplace(r);
    while(!que.empty()){
      int v=que.front();que.pop();
      ls[v]=pos++;
      H[dep[v]].emplace_back(v);
      for(int u:super::G[v]){
        if(u==par[0][v]) continue;
        que.emplace(u);
      }
    }
  }

  int idx(int v){return ls[v];}

  int find(int v,int d,int a){
    int l=-1,r=H[d].size();
    while(l+1<r){
      int m=(l+r)>>1;
      int p=super::up(H[d][m],d-dep[v]);
      if(ls[v]+a<=ls[p]) r=m;
      else l=m;
    }
    return ls[H[d][0]]+r;
  }

  template<typename F>
  void exec(int v,int d,F f){
    if(dep[v]+d>=(int)H.size()) return;
    if(H[dep[v]+d].empty()) return;
    int l=find(v,dep[v]+d,0);
    int r=find(v,dep[v]+d,1);
    if(l<r) f(l,r);
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
