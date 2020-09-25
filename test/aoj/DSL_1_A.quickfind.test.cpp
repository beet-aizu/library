// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/quickfind.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  QuickFind qf(n);
  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c==0) qf.unite(x,y);
    if(c==1) cout<<qf.same(x,y)<<"\n";
  }
  cout<<flush;
  return 0;
}
