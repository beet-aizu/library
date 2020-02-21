#define PROBLEM "https://yukicoder.me/problems/1937"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../datastructure/waveletmatrix.cpp"
#undef call_from_test

signed main(){
  using ll = long long;

  int n;
  cin>>n;

  vector<ll> as(n),ls(n),rs(n);
  for(int i=0;i<n;i++) cin>>as[i];
  for(int i=0;i<n;i++) cin>>ls[i]>>rs[i];

  const ll OFS = 2e9;
  vector<ll> bs(n),cs(n);
  for(int i=0;i<n;i++){
    as[i]+=OFS;
    bs[i]=as[i]-ls[i];
    cs[i]=as[i]+rs[i];
  }
  WaveletMatrix<ll, 40> wm1(bs),wm2(cs);

  ll ans=0;
  for(int i=0;i<n;i++){
    int x=lower_bound(as.begin(),as.end(),as[i]-ls[i])-as.begin();
    int y=upper_bound(as.begin(),as.end(),as[i]+rs[i])-as.begin();
    ans+=wm2.rangefreq(x,i,as[i],OFS*2);
    ans+=wm1.rangefreq(i+1,y,0,as[i]+1);
  }

  cout<<ans/2<<endl;
  return 0;
}
