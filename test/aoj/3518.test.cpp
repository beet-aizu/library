#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3518"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../segtree/basic/ushi.cpp"
#include "../../segtree/2d/ushi.cpp"
#include "../../tools/chminmax.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  map<pair<int, int>, int> mp;
  for(int i=0;i<m;i++){
    int y,x,a;
    cin>>y>>x>>a;
    mp[{y,x}]=a;
  }

  const int INF = 1e9+7;
  using P = pair<int, int>;
  auto f1=[&](int a,int b){return min(a,b);};
  auto f2=[&](int a,int b){return a+b;};
  auto f=[&](P a,P b){return P(f1(a.first,b.first),f2(a.second,b.second));};

  SegmentTree2D<int, SegmentTree<P>> seg(f,P(INF,0));

  for(auto[pos,a]:mp){
    auto[y,x]=pos;
    seg.preupdate(y,x);
  }
  seg.build();

  for(auto[pos,a]:mp){
    auto[y,x]=pos;
    seg.update(y,x,P(a,1));
  }

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    using ll = long long;
    ll u,d,l,r;
    cin>>u>>d>>l>>r;
    d++;r++;
    P res=seg.query(u,d,l,r);
    ll num=(d-u)*(r-l);
    if(res.second<num) chmin(res.first,0);
    cout<<res.first<<'\n';
  }
  return 0;
}
