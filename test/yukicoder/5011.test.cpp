// verification-helper: PROBLEM https://yukicoder.me/problems/5011

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/quotients.cpp"
#include "../../mod/mint.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  ll n;
  cin>>n;

  using M = Mint<int>;
  M ans{0};

  for(auto[l,r]:quotients(n)){
    if(l==1) continue;

    ll d=n/l;
    if(d<l){
      ans+=M(n)*M(r-l+1);
      ans-=M(d)*M(l-1+r-1)*M(r-l+1)/M(2);
      continue;
    }

    for(ll i=l;i<=r;i++)
      for(ll t=n;t;t/=i) ans+=M(t%i);
  }

  cout<<ans<<endl;
  return 0;
}
