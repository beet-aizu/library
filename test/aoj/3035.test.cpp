#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3035"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../segtree/basic/chien.cpp"
#undef call_from_test

signed main(){
  using ll = long long;

  struct T{
    ll w,x,y,z;
    T(ll w,ll x,ll y,ll z):w(w),x(x),y(y),z(z){}
  };

  auto f=
    [](T a,T b){
      ll cw=min(a.w,b.w);
      ll cx=(a.w==b.w?a.x+b.x:(a.w<b.w?a.x:b.x));
      ll cy=max(a.y,b.y);
      ll cz=(a.y==b.y?a.z+b.z:(a.y>b.y?a.z:b.z));
      return T(cw,cx,cy,cz);
    };
  auto g=
    [](T a,ll b){
      return T(a.w+b,a.x,a.y+b,a.z);
    };
  auto h=[](ll a,ll b){return a+b;};

  int H,W,Q;
  cin>>H>>W>>Q;
  vector<T> A,B;
  for(int i=0;i<H;i++){
    int v;
    cin>>v;
    A.emplace_back(v,1,v,1);
  }
  for(int i=0;i<W;i++){
    int v;
    cin>>v;
    B.emplace_back(v,1,v,1);
  }

  const ll INF = 1e17;
  T ti(INF,0,-INF,0);
  SegmentTree<T, ll> segY(f,g,h,ti,0);
  SegmentTree<T, ll> segX(f,g,h,ti,0);
  segY.build(A);
  segX.build(B);

  auto calc=
    [](int t,T a,T b,ll p,ll q){
      ll res=t==3?
        min({a.w*b.w,a.w*b.y,a.y*b.w,a.y*b.y}):
        max({a.w*b.w,a.w*b.y,a.y*b.w,a.y*b.y});
      ll cnt=0;
      ll n=p-(!a.w?a.x:!a.y?a.z:0ll);
      ll m=q-(!b.w?b.x:!b.y?b.z:0ll);
      if(res==0) cnt=p*q-n*m;
      else{
        if(a.w==a.y) a.z=0;
        if(b.w==b.y) b.z=0;
        if(res==a.w*b.w) cnt+=a.x*b.x;
        if(res==a.w*b.y) cnt+=a.x*b.z;
        if(res==a.y*b.w) cnt+=a.z*b.x;
        if(res==a.y*b.y) cnt+=a.z*b.z;
      }
      cout<<res<<" "<<cnt<<"\n";
    };

  for(int i=0;i<Q;i++){
    int t;
    cin>>t;
    if(t==1){
      int a,b,v;
      cin>>a>>b>>v;
      segY.update(--a,b,v);
    }
    if(t==2){
      int c,d,v;
      cin>>c>>d>>v;
      segX.update(--c,d,v);
    }
    if(t==3||t==4){
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      T y=segY.query(--a,b);
      T x=segX.query(--c,d);
      calc(t,y,x,b-a,d-c);
    }
  }
  cout<<flush;
  return 0;
}
