#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2725"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/convexhulltrick.cpp"
#undef call_from_test

signed main(){
  using ll = long long;

  int n,x;
  scanf("%d %d",&n,&x);
  vector<ll> t(n),p(n),f(n);
  for(int i=0;i<n;i++) scanf("%lld %lld %lld",&t[i],&p[i],&f[i]);

  using T = tuple<ll, ll, ll>;
  vector<T> vt(n);
  for(int i=0;i<n;i++) vt[i]=T(f[i],p[i],t[i]);
  sort(vt.begin(),vt.end());
  for(int i=0;i<n;i++) tie(f[i],p[i],t[i])=vt[i];

  vector<ConvexHullTrick<ll, false> > vh(x+1);

  ll ans=0;
  for(int i=0;i<n;i++){
    for(int j=x;j>t[i];j--){
      if(vh[j-t[i]].empty()) continue;
      ll val=vh[j-t[i]].queryMonotoneInc(f[i])+p[i]-f[i]*f[i];
      vh[j].addLine(2*f[i],val-f[i]*f[i]);
      ans=max(ans,val);
    }
    vh[t[i]].addLine(2*f[i],p[i]-f[i]*f[i]);
    ans=max(ans,p[i]);
  }

  printf("%lld\n",ans);
  return 0;
}
