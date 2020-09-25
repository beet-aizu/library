// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0425

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../algorithm/mo.cpp"
#include "../../vector/identity.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,k,q;
  cin>>n>>k>>q;
  vector<int> as(k),bs(k);
  for(int i=0;i<k;i++) cin>>as[i]>>bs[i],as[i]--,bs[i]--;

  vector<int> ord=identity(n);
  vector<int> pos=identity(n);
  auto moveL=
    [&](int i){
      int x=pos[as[i]],y=pos[bs[i]];
      swap(ord[x],ord[y]);
      swap(pos[ord[x]],pos[ord[y]]);
    };
  auto moveR=
    [&](int i){
      int x=as[i],y=bs[i];
      swap(ord[x],ord[y]);
      swap(pos[ord[x]],pos[ord[y]]);
    };
  Mo mo(q,400,moveL,moveR,moveL,moveR);

  vector<int> qs(q),ls(q),rs(q),xs(q);
  for(int i=0;i<q;i++){
    cin>>qs[i]>>ls[i]>>rs[i]>>xs[i];
    ls[i]--;xs[i]--;
    mo.add(ls[i],rs[i]);
  }
  mo.build();

  vector<int> ans(q,-1);
  for(int i=0;i<q;i++){
    int p=mo.process();
    if(qs[p]==1) ans[p]=ord[xs[p]]+1;
    if(qs[p]==2) ans[p]=pos[xs[p]]+1;
  }

  for(int a:ans) cout<<a<<"\n";
  cout<<flush;
  return 0;
}
