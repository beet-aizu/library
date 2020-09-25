#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2290"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mincostflow/primaldual.cpp"
#include "../../tools/chminmax.cpp"
#include "../../vector/identity.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,v,xleft,xright;
  cin>>n>>v>>xleft>>xright;

  int S=n+n,T=n+n+1,L=n+n+2,R=n+n+3;
  PrimalDual<int, int> G(n+n+4);

  G.add_edge(S,L,1,0);
  G.add_edge(L,T,1,0);

  G.add_edge(S,R,1,0);
  G.add_edge(R,T,1,0);

  vector<int> xs(n),ts(n),ps(n);
  for(int i=0;i<n;i++){
    cin>>xs[i]>>ts[i]>>ps[i];

    if(abs(xs[i]-xleft)<=ts[i]*v)
      G.add_edge(L,i,1,0);

    if(abs(xs[i]-xright)<=ts[i]*v)
      G.add_edge(R,i,1,0);
  }

  auto init=[&](auto &h)->void{
    fill(h.begin(),h.end(),0);

    auto ord=identity(n);
    sort(ord.begin(),ord.end(),
         [&](int i,int j){return ts[i]<ts[j];});

    auto add_edge=[&](int u,int v,int f,int c){
      G.add_edge(u,v,f,c);
      chmin(h[v],h[u]+c);
    };

    for(int i=0;i<n;i++){
      int x=ord[i];
      add_edge(x,n+x,1,-ps[x]);
      for(int j=i+1;j<n;j++){
        int y=ord[j];
        if(abs(xs[x]-xs[y])<=(ts[y]-ts[x])*v)
          add_edge(n+x,y,1,0);
      }
      add_edge(n+x,T,1,0);
    }
  };
  assert(G.build(S,T,2,init));
  cout<<-G.get_cost()<<endl;
  return 0;
}
