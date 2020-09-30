// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3198

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../matching/bipartite.cpp"
#undef call_from_test

const int MAX = 5050;
int ex[MAX][MAX]={};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;

  Bipartite G(n+n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    ex[a][b]=1;
    G.add_edge(0+a,n+b);
  }

  int res=G.build();

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;

    if(ex[x][y])
      res-=G.cut_edge(0+x,n+y);
    else
      G.add_edge(0+x,n+y);

    ex[x][y]^=1;

    res+=G.build();
    cout<<(res==n?"Yes":"No")<<'\n';
  }
  return 0;
}
