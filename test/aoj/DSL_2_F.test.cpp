// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../segtree/basic/chien.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  auto f=[](int a,int b){return min(a,b);};
  auto g=[](int a,int b){(void)a;return b;};
  SegmentTree<int, int> seg(f,g,g,INT_MAX,-1);
  seg.build(vector<int>(n,INT_MAX));

  for(int i=0;i<q;i++){
    int c;
    cin>>c;
    if(c==0){
      int s,t,x;
      cin>>s>>t>>x;
      seg.update(s,t+1,x);
    }
    if(c==1){
      int s,t;
      cin>>s>>t;
      cout<<seg.query(s,t+1)<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
