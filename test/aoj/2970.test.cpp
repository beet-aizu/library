// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2970

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/drop.cpp"
#include "../../math/extgcd.cpp"
#include "../../mod/inverse.cpp"
#include "../../math/linearcongruence.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<int> ps(n),qs(n);
  for(int i=0;i<n;i++) cin>>ps[i],ps[i]--;
  for(int i=0;i<n;i++) cin>>qs[i],qs[i]--;

  using ll = long long;
  vector<ll> A,B,M;

  vector<int> used(n,0);
  for(int i=0;i<n;i++){
    if(used[i]) continue;
    int pos=i;
    vector<int> vs,ws;
    while(!used[pos]){
      vs.emplace_back(pos);
      ws.emplace_back(ps[pos]);
      used[pos]=1;
      pos=qs[pos];
    }
    {
      auto as=vs,bs=ws;
      sort(as.begin(),as.end());
      sort(bs.begin(),bs.end());
      if(as!=bs) drop(-1);
    }

    int m=vs.size();
    for(int j=0;j<m;j++)
      ws.emplace_back(int(ws[j]));

    for(int j=0;j<m;j++){
      if(ws[j]!=vs[0]) continue;
      for(int k=0;k<m;k++)
        if(ws[j+k]!=vs[k]) drop(-1);

      A.emplace_back(1);
      B.emplace_back(j);
      M.emplace_back(m);
    }
  }

  auto res=linear_congruence(A,B,M);
  if(res.second<0) drop(-1);
  cout<<res.first<<endl;
  return 0;
}
