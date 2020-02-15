#define PROBLEM "https://yukicoder.me/problems/2600"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../datastructure/absolutesum.cpp"
#undef call_from_test

signed main(){
  using ll = long long;

  int n;
  cin>>n;
  vector<ll> ys(n);
  for(int i=0;i<n;i++) cin>>ys[i];
  sort(ys.begin(),ys.end());
  if(ys.front()==ys.back()){
    cout<<1<<endl;
    return 0;
  }

  AbsoluteSum<ll> as;
  vector<ll> dp(n,0);
  for(int i=0;i<n;i++){
    as.insert(ys[i]);
    dp[i]+=as.value();
  }
  for(int i=0;i<n;i++){
    as.erase(ys[i]);
    dp[i]+=as.value();
  }

  cout<<*min_element(dp.begin(),dp.end())<<endl;
  return 0;
}
