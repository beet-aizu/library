#define PROBLEM "https://yukicoder.me/problems/4918"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/tuple.cpp"
#include "../../tools/chminmax.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  auto [as, bs]=read_tuple<int, int>(m);

  vector G(n,vector(n,n));

  for(int i=0;i<n;i++) G[i][i]=0;

  for(int i=0;i<m;i++){
    as[i]--;bs[i]--;
    G[as[i]][bs[i]]=1;
    G[bs[i]][as[i]]=1;
  }

  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        chmin(G[i][j],G[i][k]+G[k][j]);

  int ans=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<i;j++)
      for(int k=0;k<j;k++)
        if(G[i][j]!=2 and G[i][k]!=2 and G[j][k]!=2) ans++;

  cout<<ans<<endl;
  return 0;
}
