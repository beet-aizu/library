#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/sparsetable.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,l;
  cin>>n>>l;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto f=[](int a,int b){return min(a,b);};
  SparseTable<int> st(f);
  st.build(as);

  for(int i=0;i+l<=n;i++){
    if(i) cout<<" ";
    cout<<st.query(i,i+l);
  }
  cout<<endl;
  return 0;
}
