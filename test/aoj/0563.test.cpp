// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0563

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../bbst/pb_ds_tree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int w,h,n;
  cin>>w>>h>>n;
  vector<int> xs(n),ys(n);
  for(int i=0;i<n;i++) cin>>xs[i]>>ys[i];

  using P = pair<int, int>;
  gtree<P> gx,gy;
  for(int i=0;i<n;i++){
    gx.insert(P(xs[i],i));
    gy.insert(P(ys[i],i));
    gx.insert(P(xs[i],n+i));
    gy.insert(P(ys[i],n+i));
  }

  ll ans=1e18;
  int ax=-1,ay=-1;

  map<int, ll> mx,my;

  for(int i=0;i<n;i++){
    gx.erase(P(xs[i],i));
    gy.erase(P(ys[i],i));


    int tx=gx.find_by_order(n-1)->first;
    int ty=gy.find_by_order(n-1)->first;

    if(!mx.count(tx)){
      mx[tx]=0;
      for(int j=0;j<n;j++)
        mx[tx]+=abs(xs[j]-tx)*2;
    }

    if(!my.count(ty)){
      my[ty]=0;
      for(int j=0;j<n;j++)
        my[ty]+=abs(ys[j]-ty)*2;
    }

    ll res=mx[tx]+my[ty]-(abs(xs[i]-tx)+abs(ys[i]-ty));
    if((res< ans)||
       (res==ans&&tx< ax)||
       (res==ans&&tx==ax&&ty< ay)){
      ans=res;
      ax=tx;
      ay=ty;
    }


    gx.insert(P(xs[i],i));
    gy.insert(P(ys[i],i));
  }

  cout<<ans<<endl;
  cout<<ax<<" "<<ay<<endl;
  return 0;
}
