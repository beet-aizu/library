#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2736"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../io/precision.cpp"
#include "../../mincostflow/primaldual.cpp"
#undef call_from_test

#define ERROR "1e-6"

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,p,s,t;
  cin>>n>>m>>p>>s>>t;
  s--;t--;
  PrimalDual<int, int> G(n);
  for(int i=0;i<m;i++){
    int v,u,d,c;
    cin>>v>>u>>d>>c;
    v--;u--;
    G.add_edge(v,u,c,d);
  }
  using D = double;
  D ans=1e18;
  D sum=0,cnt=0;
  int ok=1;
  while(1){
    sum+=G.flow(s,t,1,ok);
    cnt+=1;
    if(!ok) break;
    chmin(ans,(sum+p)/cnt);
  }
  cout<<ans<<endl;
  return 0;
}
