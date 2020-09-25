// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2975
// verification-helper: ERROR 1e-9

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/precision.cpp"
#include "../../tools/chminmax.cpp"
#include "../../datastructure/convexhulltrick.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  int zx,zv;
  cin>>zx>>zv;

  vector<int> xs(n),vs(n);
  for(int i=0;i<n;i++) cin>>xs[i]>>vs[i];

  for(int i=0;i<n;i++){
    xs[i]-=zx;
    vs[i]-=zv;
  }

  using D = double;
  const D INF = 1e10;
  vector<D> ans(n,INF);
  for(int i=0;i<n;i++){
    if(xs[i]==0) ans[i]=0;
    if((D)xs[i]*(D)vs[i]<0) chmin(ans[i],-(D)xs[i]/(D)vs[i]);
  }

  for(int uku=0;uku<2;uku++){
    for(int i=0;i<n;i++){
      xs[i]*=-1;
      vs[i]*=-1;
    }

    using P = pair<D, D>;
    vector<P> vp;
    int sp=0;
    for(int i=0;i<n;i++){
      if(xs[i]>=0) continue;
      if(vs[i]<=0) continue;
      vp.emplace_back(vs[i],xs[i]);
      chmax(sp,vs[i]);
    }
    if(vp.empty()) continue;

    sort(vp.begin(),vp.end());
    ConvexHullTrick<D, false> cht;
    for(auto p:vp) cht.addLine(p.first,p.second);

    for(int i=0;i<n;i++){
      if(xs[i]<=0) continue;
      if(sp<=vs[i]) continue;
      D L=0,R=INF;
      for(int k=0;k<80;k++){
        D M=(L+R)/2;
        if(cht.query(M)>=(D)vs[i]*M+(D)xs[i]) R=M;
        else L=M;
      }
      chmin(ans[i],R);
    }
  }

  cout<<fixed<<setprecision(12);
  for(int i=0;i<n;i++){
    if(ans[i]>=INF) cout<<-1<<"\n";
    else cout<<ans[i]<<"\n";
  }
  cout<<flush;
  return 0;
}
