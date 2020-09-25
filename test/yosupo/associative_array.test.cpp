// verification-helper: PROBLEM https://judge.yosupo.jp/problem/associative_array

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/cc_hash.cpp"
#include "../../datastructure/pb_ds_cc_hash_table.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  using ll = long long;
  gmap<ll, ll, cc_hash<ll>> mp;

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      ll k,v;
      cin>>k>>v;
      mp[k]=v;
    }
    if(t==1){
      ll k;
      cin>>k;
      cout<<mp[k]<<newl;
    }
  }
  return 0;
}
