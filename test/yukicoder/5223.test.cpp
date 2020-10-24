// verification-helper: PROBLEM https://yukicoder.me/problems/5223

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../algorithm/mo.cpp"
#include "../../segtree/basic/lazy.cpp"
#include "../../datastructure/binaryindexedtree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,q;
  cin>>n>>q;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto f=[&](int a,int b){return min(a,b);};
  auto g=[&](int a,int b){return a+b;};
  int ti(1e9),ei(0);
  SegmentTree<int, int> seg(f,g,g,ti,ei);
  seg.build(vector<int>(n+2,0));

  BIT<int> bitL(n+2),bitR(n+2);

  using ll = long long;
  ll res=0;
  auto expandL=[&](int i){
    res-=bitL.query(as[i]+1,n+2);
    res-=bitR.query(0,as[i]);
    bitL.add(as[i],-1);
    seg.update(0,as[i],-1);
  };
  auto expandR=[&](int i){
    res-=bitL.query(as[i]+1,n+2);
    res-=bitR.query(0,as[i]);
    bitR.add(as[i],-1);
    seg.update(as[i]+1,n+2,-1);
  };
  auto shrinkL=[&](int i){
    res+=bitL.query(as[i]+1,n+2);
    res+=bitR.query(0,as[i]);
    bitL.add(as[i],+1);
    seg.update(0,as[i],+1);
  };
  auto shrinkR=[&](int i){
    res+=bitL.query(as[i]+1,n+2);
    res+=bitR.query(0,as[i]);
    bitR.add(as[i],+1);
    seg.update(as[i]+1,n+2,+1);
  };

  for(int i=n-1;i>=0;i--){
    res+=bitR.query(0,as[i]);
    bitR.add(as[i],+1);
    seg.update(as[i]+1,n+2,+1);
  }

  Mo mo(n,200,expandL,expandR,shrinkL,shrinkR);

  vector<int> ls,rs;
  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--;
    ls.emplace_back(l);
    rs.emplace_back(r);
    mo.add(l,r);
  }

  mo.build();
  vector<ll> ans(q,0);
  for(int i=0;i<q;i++){
    int k=mo.process();
    ans[k]=(rs[k]-ls[k])*seg.query(0,n+2)+res;
  }

  for(int i=0;i<q;i++) cout<<ans[i]<<newl;
  return 0;
}
