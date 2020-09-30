// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3506

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../vector/compress.cpp"
#include "../../graph/rangetorange.cpp"
#include "../../graph/dijkstra.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<int> xs(n),ys(n);
  for(int i=0;i<n;i++) cin>>xs[i]>>ys[i];

  // [0n, 1n) : original
  // [1n, 2n) : x-axis
  // [2n, 3n) : y-axis
  const int m = 3 * n;
  RangeToRange R(m);
  Dijkstra<int> D(m*3+4*n);

  auto f0=[&](int u,int v){D.add_edge(u,v,0);};
  auto f1=[&](int u,int v){D.add_edge(u,v,1);};
  R.init(f0);

  // swap(xs,ys);
  for(int k=1;k<=2;k++){
    auto cx=compress(xs);
    auto dx=dict(cx);

    vector<int> tx(n);
    for(int i=0;i<n;i++) tx[i]=dx[xs[i]];

    map<int, int> ls,rs;
    for(int i=0;i<n;i++) ls[ys[i]]=rs[ys[i]]=tx[i];
    for(int i=0;i<n;i++){
      chmin(ls[ys[i]],tx[i]);
      chmax(rs[ys[i]],tx[i]);
    }

    // connect
    for(int i=0;i<n;i++){
      D.add_edge(m+k*n+tx[i],m+i,0);
      D.add_edge(m+i,m+k*n+tx[i],0);
    }

    // add point
    for(int i=0;i<n;i++){
      R.add_edge(i,i+1,k*n+ls[ys[i]],k*n+rs[ys[i]]+1,f0,f1);
      R.add_edge(k*n+ls[ys[i]],k*n+rs[ys[i]]+1,i,i+1,f0,f1);
    }

    swap(xs,ys);
  }

  D.build(m);
  cout<<(~D.bs[m+n-1]?D[m+n-1]:-1)<<endl;
  return 0;
}
