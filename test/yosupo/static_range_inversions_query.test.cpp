// verification-helper: PROBLEM https://judge.yosupo.jp/problem/static_range_inversions_query

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../vector/compress.cpp"
#include "../../algorithm/mo.cpp"
#include "../../datastructure/binaryindexedtree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  auto as=read(n);
  auto dc=dict(compress(as));
  vector<int> cs(n);
  for(int i=0;i<n;i++) cs[i]=dc[as[i]];

  using ll = long long;
  ll res=0;
  vector<ll> ans(q);
  BIT<int> bit(n);
  auto expandL=[&](int i){bit.add(cs[i],+1);res+=bit.query(0,cs[i]);};
  auto expandR=[&](int i){bit.add(cs[i],+1);res+=bit.query(cs[i]+1,n);};
  auto shrinkL=[&](int i){bit.add(cs[i],-1);res-=bit.query(0,cs[i]);};
  auto shrinkR=[&](int i){bit.add(cs[i],-1);res-=bit.query(cs[i]+1,n);};

  Mo mo(n,400,expandL,expandR,shrinkL,shrinkR);
  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    mo.add(l,r);
  }
  mo.build();

  for(int i=0;i<q;i++){
    int k=mo.process();
    ans[k]=res;
  }

  for(auto a:ans) cout<<a<<'\n';
  return 0;
}
