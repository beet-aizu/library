#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../polynomial/berlekampmassey.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  using M = Mint<int, 998244353>;
  vector<M> as(n);
  for(int i=0;i<n;i++) cin>>as[i].v;

  auto cs=berlekamp_massey(as);
  cs.pop_back();
  reverse(cs.begin(),cs.end());
  cout<<cs.size()<<endl;
  for(int i=0;i<(int)cs.size();i++){
    if(i) cout<<" ";
    cout<<-cs[i];
  }
  cout<<endl;
  return 0;
}
