#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2871"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tree/eulertourforvertex.cpp"
#include "../../segtree/basic/chien.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  EulerTourForVertex et(n);
  for(int i=1;i<n;i++){
    int p;
    cin>>p;
    p--;
    et.add_edge(p,i);
  }
  et.build();

  vector<char> cs(n);
  for(int i=0;i<n;i++) cin>>cs[i];

  struct T{
    int sum,one;
    T(int sum,int one):sum(sum),one(one){}
  };
  using E = int;
  auto f=[](T a,T b){return T(a.sum+b.sum,a.one+b.one);};
  auto g=[](T a,E b){return T(a.sum,b?a.sum-a.one:a.one);};
  auto h=[](E a,E b){return a^b;};
  T ti(0,0);
  E ei(0);

  SegmentTree<T, E> seg(f,g,h,ti,ei);
  vector<T> vs(n,ti);
  for(int i=0;i<n;i++) vs[et.idx(i)]=T(1,cs[i]=='G');
  seg.build(vs);

  for(int i=0;i<q;i++){
    int v;
    cin>>v;
    v--;
    et.exec(v,[&](int l,int r){seg.update(l,r,1);});
    auto res=seg.query(0,n);
    cout<<(res.sum-res.one<res.one?"broccoli":"cauliflower")<<"\n";
  }
  cout<<flush;
  return 0;
}
