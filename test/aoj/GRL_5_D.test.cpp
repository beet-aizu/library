// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tree/eulertourforedge.cpp"
#include "../../datastructure/binaryindexedtree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  EulerTourForEdge et(n);
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int c;
      cin>>c;
      et.add_edge(i,c);
    }
  }
  et.build();

  BIT<int> bit(2*n);
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int v,w;
      cin>>v>>w;
      auto g=[&](int k,int d){bit.add(k,d);};
      et.update(v,w,g);
    }
    if(t==1){
      int u;
      cin>>u;
      int res=0;
      et.query(0,u,[&](int l,int r){res+=bit.query(l,r);});
      cout<<res<<"\n";
    }
  }
  return 0;
}
