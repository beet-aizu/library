// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2313

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../maxflow/dinic.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,e,q;
  cin>>n>>e>>q;
  Dinic<int, true> G(n);
  vector< map<int, int> > I(n);
  for(int i=0;i<e;i++){
    int f,t;
    cin>>f>>t;
    f--;t--;
    I[f][t]=G.add_edge(f,t,1);
    I[t][f]=G.add_edge(t,f,1);
  }

  vector<int> ms(q),as(q),bs(q);
  for(int i=0;i<q;i++){
    cin>>ms[i]>>as[i]>>bs[i];
    as[i]--;bs[i]--;
    if(I[as[i]].count(bs[i])) continue;
    I[as[i]][bs[i]]=G.add_edge(as[i],bs[i],0);
    I[bs[i]][as[i]]=G.add_edge(bs[i],as[i],0);
  }

  int res=G.flow(0,n-1);
  for(int i=0;i<q;i++){
    if(ms[i]==1){
      res+=G.link(0,n-1,as[i],I[as[i]][bs[i]],1);
      res+=G.link(0,n-1,bs[i],I[bs[i]][as[i]],1);
    }
    if(ms[i]==2){
      res-=G.cut(0,n-1,as[i],I[as[i]][bs[i]]);
      res-=G.cut(0,n-1,bs[i],I[bs[i]][as[i]]);
    }
    cout<<res<<"\n";
  }
  return 0;
}
