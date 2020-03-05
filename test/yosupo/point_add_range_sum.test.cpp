#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/binaryindexedtree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  BIT<long long> bit(n);
  for(int i=0;i<n;i++) bit.add0(i,as[i]);

  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int p,x;
      cin>>p>>x;
      bit.add0(p,x);
    }
    if(t==1){
      int l,r;
      cin>>l>>r;
      cout<<bit.query0(l,r)<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
