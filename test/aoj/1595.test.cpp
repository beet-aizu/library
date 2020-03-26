#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tree/rerooting.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  auto f1=[&](int a,int b){return max(a,b);};
  auto f2=[&](int a,int b){return a+b;};
  ReRooting<int, int> G(n,f1,f2,0);
  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    G.add_edge(u,v,1);
  }
  auto ans=G.build();
  for(int a:ans) cout<<(n-1)*2-a<<"\n";
  cout<<flush;
  return 0;
}
