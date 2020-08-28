#define PROBLEM "https://yukicoder.me/problems/4271"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../polynomial/recursivesequence.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int k,n,m;
  cin>>k>>n>>m;

  using M = Mint<int>;
  vector<M> as(k),cs(k);
  for(int i=0;i<k;i++) cin>>as[i].v;
  for(int i=0;i<k;i++) cin>>cs[i].v;

  RecursiveSequence<M> rs(n);
  for(int i=0;i<m;i++){
    int l,r;
    cin>>l>>r;
    rs.query(l,r);
  }

  auto ss=rs.build(as,cs);
  for(int i=0;i<n;i++) cout<<ss[i]<<newl;
  return 0;
}
