#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1579"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../bbst/rbst/basic/base.cpp"
#include "../../bbst/rbst/basic/dual.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,a,d;
  cin>>n>>a>>d;

  using ll = long long;
  struct E{
    ll a,b,c;
    E(){}
    E(ll a,ll b,ll c):a(a),b(b),c(c){}
    bool operator!=(const E &o) const{
      return make_tuple(a,b,c)!=make_tuple(o.a,o.b,o.c);
    }
  };

  const ll MAX = 1e9;
  auto h=
    [](E a,E b){
      E c(a.a+a.b*(a.c+b.a),a.b*b.b,0);
      c.c=c.a/c.b+b.c;
      c.a%=c.b;
      if(c.b>MAX){
        c.a=max(0LL,MAX-(c.b-c.a));
        c.b=MAX;
      }
      return c;
    };
  E ei(0,1,0);

  using Node = NodeBase<E>;
  constexpr size_t LIM = 1e6;
  Dual<Node, LIM> G(h,ei);

  auto r=G.init(n);
  for(int i=0;i<n;i++){
    int v=a+d*i;
    r=G.update(r,i,i+1,E(0,1,v));
  }

  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    int x,y,z;
    cin>>x>>y>>z;
    y--;
    if(x==0) r=G.toggle(r,y,z);
    if(x==1) r=G.update(r,y,z,E(0,1,1));
    if(x==2) r=G.update(r,y,z,E(0,2,0));
  }

  int k;
  cin>>k;
  k--;
  cout<<G.get_val(r,k).c<<endl;
  return 0;
}
