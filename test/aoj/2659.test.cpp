// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2659

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/extgcd.cpp"
#include "../../mod/inverse.cpp"
#include "../../math/linearcongruence.cpp"
#undef call_from_test

int r[111][111];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,d;
  cin>>n>>m>>d;
  vector<int> a(m);
  for(int i=0;i<m;i++) cin>>a[i];

  for(int i=0;i<d;i++)
    for(int j=0;j<m;j++)
      cin>>r[i][j];

  using ll = long long;
  ll ans=n;

  for(int i=0;i<d;i++){
    vector<ll> A,B,M;

    for(int j=0;j<m;j++){
      if(r[i][j]<0) continue;
      A.emplace_back(1);
      B.emplace_back(r[i][j]);
      M.emplace_back(a[j]);
    }
    auto p=linear_congruence(A,B,M);
    if(p.second<0){
      ans=-1;
      break;
    }
    if(p.second<0) p.first+=p.second;
    ans=(ans-p.first)/p.second*p.second+p.first;
  }

  cout<<ans<<endl;
  return 0;
}
