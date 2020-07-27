#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/cartesiantree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n;
  cin>>n;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto ps=cartesian_tree(as);
  for(int i=0;i<n;i++){
    if(i) cout<<' ';
    cout<<(ps[i]<0?i:ps[i]);
  }
  cout<<newl;
  return 0;
}
