#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../flow/hopcroft_karp.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int L,R,M;
  cin>>L>>R>>M;
  BiMatch G(L,R);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    G.add_edge(a,b);
  }
  cout<<G.build()<<endl;
  for(int i=0;i<L;i++){
    if(~G.match[i])
      cout<<i<<" "<<G.match[i]-L<<"\n";
  }
  cout<<flush;
  return 0;
}
