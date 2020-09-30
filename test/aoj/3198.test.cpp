// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3198

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../algorithm/offlineonline.cpp"
#include "../../datastructure/sparsetable.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,l;
  cin>>n>>l;
  auto as=read(n);

  auto f=[](int a,int b){return max(a,b);};
  SparseTable<int> st(f);
  st.build(as);

  using ll = long long;
  const ll INF = 1e18;
  auto dist=[&](int i,int j)->ll{
    return j-i<l?INF-ll(2e9)*(j-i):-st.query(i,j);
  };

  cout<<-OfflineOnline::solve<ll>(n,dist)<<endl;
  return 0;
}
