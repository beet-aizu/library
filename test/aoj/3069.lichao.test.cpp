#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3069"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../segtree/cht/lichao.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  int n,m,q;
  cin>>n>>m>>q;

  vector<ll> ds(n);
  for(int i=0;i<n;i++) cin>>ds[i];
  for(int i=0;i<n;i++) ds.emplace_back(int(ds[i]));
  for(int i=0;i<n;i++) ds.emplace_back(int(ds[i]));

  vector<ll> sm(n*3+1,0);
  for(int i=0;i<n*3;i++) sm[i+1]=sm[i]+ds[i];

  vector<char> cs(m);
  vector<int> bs(m),ts(m);
  for(int i=0;i<m;i++) cin>>cs[i]>>bs[i]>>ts[i],bs[i]--;

  vector< vector<ll> > G(n*3);
  vector<ll> xs(q),ys(q);
  for(int i=0;i<q;i++){
    cin>>xs[i]>>ys[i];
    xs[i]--,ys[i]--;
    xs[i]+=n,ys[i]+=n;
    G[xs[i]].emplace_back(i);
  }

  const ll INF = 1e18;
  vector<ll> R(n*3,INF),L(n*3,INF);
  int exR=0,exL=0;
  for(int i=0;i<m;i++){
    if(cs[i]=='R'){
      exR=1;
      chmin(R[bs[i]+n*0],ts[i]);
      chmin(R[bs[i]+n*1],ts[i]);
      chmin(R[bs[i]+n*2],ts[i]);
    }
    if(cs[i]=='L'){
      exL=1;
      chmin(L[bs[i]+n*0],ts[i]);
      chmin(L[bs[i]+n*1],ts[i]);
      chmin(L[bs[i]+n*2],ts[i]);
    }
  }

  vector<ll> ans(q,INF);

  // use R
  if(exR){
    LiChao<ll, true> cht(sm);
    for(int x=0;x<n*2;x++){
      if(R[x]!=INF) cht.addLine(R[x],-R[x]*sm[x]);
      for(int i:G[x]){
        int y=ys[i];
        if(x>y) y+=n;
        chmin(ans[i],cht.query(sm[y]));
      }
    }
  }

  // use L
  if(exL){
    LiChao<ll, true> cht(sm);
    for(int x=n*3-1;x>=n;x--){
      if(L[x]!=INF) cht.addLine(-L[x],L[x]*sm[x]);
      for(int i:G[x]){
        int y=ys[i];
        if(x<y) y-=n;
        chmin(ans[i],cht.query(sm[y]));
      }
    }
  }

  for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
  cout<<flush;
  return 0;
}
