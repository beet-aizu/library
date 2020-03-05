#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/sparsetable.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto f=[](int a,int b){return min(a,b);};
  SparseTable<int> rmq(f);
  rmq.build(as);

  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    cout<<rmq.query(l,r)<<"\n";
  }
  cout<<flush;
  return 0;
}
