#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3117"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../bbst/pb_ds_tree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,k;
  cin>>n>>k;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i],as[i]-=k;

  using ll = long long;
  using P = pair<ll, int>;
  gtree<P> G;
  ll sum=0,ans=0;
  G.insert(P(sum,-1));
  for(int i=0;i<n;i++){
    sum+=as[i];
    G.insert(P(sum,i));
    ans+=G.order_of_key(P(sum,i));
  }
  cout<<ans<<endl;
  return 0;
}
