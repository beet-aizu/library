#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../segtree/count/static.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int d;
  cin>>d;
  vector<int> xs(d);
  for(int i=0;i<d;i++) cin>>xs[i];

  using P = pair<int, int>;
  vector<P> vp;
  for(int i=0;i<d;i++) vp.emplace_back(i,xs[i]);
  SegmentTree<int> seg(d,vp);

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int l,r,e;
    cin>>l>>r>>e;
    l--;
    int a=min(xs[l],xs[r-1]);
    int b=max(xs[l],xs[r-1]);
    cout<<(r-l)-seg.query(l,r,a-e,b+e+1)<<"\n";
  }
  cout<<flush;
  return 0;
}
