#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../segtree/basic/chien.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  using P = pair<int, int>;
  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,int b){return P(a.second*b,a.second);};
  auto h=[](int a,int b){(void)a;return b;};

  SegmentTree<P, int> seg(f,g,h,P(0,0),-1010);
  seg.build(vector<P>(n,P(0,1)));

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
      cout<<seg.query(s,t+1).first<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
