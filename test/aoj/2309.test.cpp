// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2309
// verification-helper: ERROR 1e-6

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/precision.cpp"
#include "../../graph/stronglyconnectedcomponent.cpp"
#include "../../graph/arborescence_edmond.cpp"
#undef call_from_test

const int MAX = 111;
double v[MAX][MAX];
double c[MAX][MAX];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      cin>>v[i][j];

  for(int i=0;i<m;i++){
    c[i][i]=0;
    for(int j=0;j<n;j++) c[i][i]+=v[i][j]*v[i][j];
  }

  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      if(i==j) continue;
      if(c[j][j]==0){
        c[i][j]=c[i][i];
        continue;
      }
      double r=0;
      for(int k=0;k<n;k++)
        r+=v[i][k]*v[j][k];
      r/=c[j][j];
      c[i][j]=0;
      for(int k=0;k<n;k++)
        c[i][j]+=(v[i][k]-r*v[j][k])*(v[i][k]-r*v[j][k]);
    }
  }

  Arborescence<double> G(m+1);
  for(int i=0;i<m;i++){
    G.add_edge(m,i,c[i][i]);
    for(int j=0;j<m;j++){
      if(i==j) continue;
      G.add_edge(j,i,c[i][j]);
    }
  }

  cout<<G.build(m)<<endl;
  return 0;
}
