// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/path.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  struct T{
    int sm,va,vi,vl,vr;
    T(int sm,int va,int vi,int vl,int vr):
      sm(sm),va(va),vi(vi),vl(vl),vr(vr){}
    T(){}
  };
  const int INF = 1e9;
  int ei=-INF;

  auto f=[&](T a,T b){
           T c;
           c.sm=a.sm+b.sm;
           c.va=a.va+b.va;
           c.vi=max({a.vi,b.vi,a.vr+b.vl});
           c.vl=max({a.vl,a.va+b.vl});
           c.vr=max({b.vr,a.vr+b.va});
           return c;
         };

  auto g=[&](T a,int b){
           if(b>=0) return T(a.sm,b*a.sm,b*a.sm,b*a.sm,b*a.sm);
           return T(a.sm,b*a.sm,b,b,b);
         };

  auto h=[&](int,int b){return b;};
  auto s=
    [&](T a){
      swap(a.vl,a.vr);
      return a;
    };

  using Node = NodeBase<T, int>;
  constexpr size_t LIM = 2e5+100;
  using LCT = Path<Node, LIM>;

  LCT lct(f,g,h,s,ei);

  vector<int> ws(n);
  for(int i=0;i<n;i++) cin>>ws[i];
  for(int i=0;i<n;i++) lct.create(g(T(1,0,0,0,0),ws[i]));

  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    lct.evert(lct[b]);
    lct.link(lct[a],lct[b]);
  }

  for(int i=0;i<q;i++){
    int t,a,b,c;
    cin>>t>>a>>b>>c;
    a--;b--;
    if(t==1){
      lct.evert(lct[a]);
      lct.update(lct[b],c);
    }
    if(t==2){
      lct.evert(lct[a]);
      auto res=lct.query(lct[b]);
      cout<<max({res.va,res.vi,res.vl,res.vr})<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
