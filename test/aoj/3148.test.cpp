// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3148

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../tools/drop.cpp"
#include "../../tree/rerooting.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  struct T{
    ll a,b,c;
    T(ll a,ll b,ll c):a(a),b(b),c(c){}
  };

  const ll INF = 1e9;
  auto fold=[&](T x,T y){
    vector<ll> vs({x.a,x.b,x.c,y.a,y.b,y.c});
    sort(vs.rbegin(),vs.rend());
    return T(vs[0],vs[1],vs[2]);
  };
  auto lift=[&](T x,ll y){
    chmax(x.a,0);
    x.a+=y;
    x.b=-INF;
    x.c=-INF;
    return x;
  };

  int n;
  cin>>n;
  if(n==1) drop(1);

  ReRooting<T, ll> G(n,fold,lift,T(-INF,-INF,-INF));
  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    G.add_edge(u,v,1);
  }
  auto res=G.build();

  string ans(n+1,'1');

  for(int i=0;i<n;i++){
    if(G.G[i].size()<3) continue;
    T v=res[i];
    ans[v.a+min({v.a-1,v.b,v.c})]='0';
  }

  for(int i=n-1;i>=0;i--)
    if(ans[i+1]=='0') ans[i]='0';

  ans[1]='1';
  ans[2]='1';
  cout<<ans.substr(1)<<endl;
  return 0;
}
