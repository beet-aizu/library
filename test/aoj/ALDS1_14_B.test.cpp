// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../string/rollinghash.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  string t,p;
  cin>>t>>p;
  using ll = long long;
  const ll MOD = 1e9+7;
  const ll B = 1777771;
  using RH = RollingHash<ll, MOD, B>;

  RH rt(t),rp(p);
  for(int i=0;i<(int)t.size()-(int)p.size()+1;i++)
    if(rt.find(i,i+p.size())==rp.find(0,p.size())) cout<<i<<"\n";

  cout<<flush;
  return 0;
}
