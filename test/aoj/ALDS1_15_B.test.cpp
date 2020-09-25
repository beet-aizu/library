// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_B
// verification-helper: ERROR 1e-6

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/precision.cpp"
#undef call_from_test

signed main(){
  using D = double;

  int n,w;
  cin>>n>>w;
  vector<D> vs(n),ws(n);
  for(int i=0;i<n;i++) cin>>vs[i]>>ws[i];

  using P = pair<D, int>;
  vector<P> vp;
  for(int i=0;i<n;i++)
    vp.emplace_back(vs[i]/ws[i],i);

  sort(vp.rbegin(),vp.rend());

  D ans=0,res=w;
  for(auto p:vp){
    D amount=min(ws[p.second],res);
    res-=amount;
    ans+=amount*p.first;
  }

  cout<<ans<<endl;
  return 0;
}
