// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2948

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/independentset.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  while(cin>>n>>m,n){
    vector< vector<int> > as(n,vector<int>(m));
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        cin>>as[i][j];

    IndependentSet G(m);
    for(int a=0;a<m;a++){
      for(int b=0;b<a;b++){
        int ng=0;
        for(int i=0;i<n;i++){
          for(int j=0;j<i;j++){
            if(as[i][a]==as[j][a]) continue;
            if(as[i][b]==as[j][b]) continue;
            if((as[i][a]>as[j][a])^(as[i][b]>as[j][b])) ng=1;
            if(ng) break;
          }
          if(ng) break;
        }

        if(ng) G.add_edge(a,b);
      }
    }

    cout<<G.build()<<endl;
  }
  return 0;
}
