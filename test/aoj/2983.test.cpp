#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2983"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../graph/maximalmatching.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  vector< vector<int> > L(m);
  for(int i=0;i<m;i++){
    int k;
    cin>>k;
    L[i].resize(k);
    for(int j=0;j<k;j++) cin>>L[i][j],L[i][j]--;
  }

  vector< vector<int> > G(n);
  for(int i=0;i<m;i++)
    for(int v:L[i]) G[v].emplace_back(i);

  int taken=0;
  vector<int> dead(m,0);
  for(int i=0;i<n;i++){
    if(G[i].size()<=1u){
      int flg=0;
      for(int g:G[i]) if(dead[g]) flg=1;
      if(flg) continue;
      taken++;
      for(int g:G[i]) dead[g]=1;
    }
  }

  vector< vector<int> > H(m);
  for(int i=0;i<n;i++){
    if(G[i].size()<=1u) continue;
    int x=G[i][0];
    int y=G[i][1];
    if(dead[x]||dead[y]) continue;
    H[x].emplace_back(y);
    H[y].emplace_back(x);
  }

  int ans=taken+maximal_matching(H);
  cout<<ans<<endl;
  return 0;
}
