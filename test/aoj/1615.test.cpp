#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../maxflow/dinic.cpp"
#include "../../maxflow/leastflow.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  while(cin>>n>>m,n){
    vector<int> xs(m),ys(m);
    for(int i=0;i<m;i++) cin>>xs[i]>>ys[i],xs[i]--,ys[i]--;

    for(int d=0;d<=n;d++){
      for(int l=n-d;l>=0;l--){
        int r=l+d;

        int S=n+m,T=n+m+1;
        LeastFlow<int> G(n+m+2);

        for(int i=0;i<m;i++){
          G.add_edge(S,i,1,1);
          G.add_edge(i,m+ys[i],0,1);
          G.add_edge(i,m+xs[i],0,1);
        }

        for(int i=0;i<n;i++)
          G.add_edge(m+i,T,l,r);

        if(G.flow(S,T)==m){
          cout<<l<<" "<<r<<endl;
          goto END;
        }
      }
    }
  END:
    ;
  }
  return 0;
}
