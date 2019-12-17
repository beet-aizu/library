#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1069"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../tools/int128.cpp"
#undef call_from_test

using ll = __int128_t;

ll sqrt(ll x){
  assert(x>=0);
  if(x<=1) return x;
  ll l=0,r=x;
  while(l+1<r){
    ll m=(l+r)>>1;
    if(m<=x/m&&m*m<=x) l=m;
    else r=m;
  }
  return l;
}

signed main(){
  int n;
  while(cin>>n,n){
    int m=n*(n+1)/2;

    vector<ll> bs(m),es,os;
    for(int i=0;i<m;i++) cin>>bs[i];
    for(ll b:bs)
      ((b&1)?os:es).emplace_back(b);

    sort(es.begin(),es.end());
    sort(os.begin(),os.end());

    ll a=sqrt(es[0]*es[1]/os[0]);
    cout<<a<<endl;
    for(int i=0;i<n;i++){
      if(i) cout<<" ";
      cout<<es[i]/a;
    }
    cout<<endl;
  }
  return 0;
}
