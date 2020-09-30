// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3168

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../tools/chminmax.cpp"
#include "../../matching/bipartite.cpp"
#undef call_from_test

const int MAX = 303;
int G[MAX][MAX]={};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,lim;
  cin>>n>>m>>lim;

  auto cs=read<char>(n);

  const int INF = 1e9;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      G[i][j]=INF;

  for(int i=0;i<n;i++) G[i][i]=0;

  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a][b]=G[b][a]=1;
  }

  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        chmin(G[i][j],G[i][k]+G[k][j]);

  auto check=[&](int i,int j){
    int x=cs[i]-'a';
    int y=cs[j]-'a';
    return (((x+1)%26==y or (y+1)%26==x) and G[i][j]<=lim);
  };

  Bipartite bm(n);
  for(int i=0;i<n;i++)
    for(int j=0;j<i;j++)
      if(check(i,j)) bm.add_edge(i,j);

  cout<<bm.build()<<endl;
  return 0;
}
