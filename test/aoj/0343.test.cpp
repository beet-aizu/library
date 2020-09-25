// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0343

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../vector/compress.cpp"
#include "../../datastructure/binaryindexedtree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;

  int n,c;
  cin>>n>>c;
  vector<int> ts(c),is(c),ps(c);
  for(int i=0;i<c;i++){
    cin>>ts[i]>>is[i];
    if(ts[i]==0) cin>>ps[i],is[i]--;
  }

  vector<ll> ss(n,0);

  using P = pair<ll, int>;
  vector<P> vp;
  for(int i=0;i<n;i++) vp.emplace_back(-ss[i],i);

  for(int i=0;i<c;i++){
    if(ts[i]==0){
      ss[is[i]]+=ps[i];
      vp.emplace_back(-ss[is[i]],is[i]);
    }
  }
  vp=compress(vp);
  auto dc=dict(vp);

  BIT<int> bit(vp.size());

  fill(ss.begin(),ss.end(),0);
  for(int i=0;i<n;i++) bit.add(dc[P(-ss[i],i)],+1);

  for(int i=0;i<c;i++){
    if(ts[i]==0){
      bit.add(dc[P(-ss[is[i]],is[i])],-1);
      ss[is[i]]+=ps[i];
      bit.add(dc[P(-ss[is[i]],is[i])],+1);
    }
    if(ts[i]==1){
      int k=bit.lower_bound(is[i])-1;
      cout<<vp[k].second+1<<' '<<-vp[k].first<<'\n';
    }
  }
  return 0;
}
