// verification-helper: PROBLEM https://yukicoder.me/problems/4872

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../vector/runlength.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  auto as=read(n);
  auto bs=read(n);

  vector<int> cs(n);
  for(int i=0;i<n;i++) cs[i]=as[i]^bs[i];

  int ans=0;
  for(auto[v,_]:runlength(cs)) ans+=v;

  cout<<ans<<endl;
  return 0;
}
