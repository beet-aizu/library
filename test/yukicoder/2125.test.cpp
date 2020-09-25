// verification-helper: PROBLEM https://yukicoder.me/problems/2125

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/bigint.cpp"
#include "../../datastructure/binaryindexedtree.cpp"
#undef call_from_test

using ll = long long;
const int MAX = 1e5+100;
ll dp[MAX];
pair<bigint, bigint> dfs(int l,int r){
  if(l+1>=r) return make_pair(bigint(dp[l]),bigint(l+1));
  int m=(l+r)>>1;
  auto v=dfs(l,m);
  auto t=dfs(m,r);
  t.first*=v.second;
  t.first+=v.first;
  t.second*=v.second;
  return t;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<int> ps(n);
  for(int i=0;i<n;i++) cin>>ps[i];
  BIT<ll> bit(n);
  for(int i=0;i<n;i++) bit.add(ps[i],1);
  for(int i=0;i<n;i++){
    dp[n-(i+1)]=bit.query(0,ps[i]);
    bit.add(ps[i],-1);
  }
  cout<<bigint(dfs(0,n).first+1)<<endl;
  return 0;
}
