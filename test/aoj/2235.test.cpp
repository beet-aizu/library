// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2235

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/dynamicconnectivity.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  DynamicConnectivity dc(n,q);
  vector<int> ts(q),us(q),vs(q);
  for(int i=0;i<q;i++){
    cin>>ts[i]>>us[i]>>vs[i];
    if(ts[i]==1) dc.insert(i,us[i],vs[i]);
    if(ts[i]==2) dc.erase( i,us[i],vs[i]);
  }
  dc.build();
  auto f=
    [&](int x){
      if(x>=q||ts[x]!=3) return;
      cout<<(dc.puf.same(us[x],vs[x])?"YES":"NO")<<endl;
    };
  dc.exec(f);
  return 0;
}
