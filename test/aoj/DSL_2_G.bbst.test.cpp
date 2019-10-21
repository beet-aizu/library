#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../bbst/basic/chien.cpp"
#undef call_from_test

signed main(){
  using ll = long long;
  int n,q;
  cin>>n>>q;

  using P = pair<ll, ll>;
  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,ll b){return P(a.first+b*a.second,a.second);};
  auto h=[](ll a,ll b){return a+b;};
  RBST<P, ll> rbst(f,g,h,P(0,0),0);
  vector<P> vs(n,P(0,1));
  auto rt=rbst.build(vs);

  for(int i=0;i<q;i++){
    int c;
    cin>>c;
    if(c==0){
      int s,t,x;
      cin>>s>>t>>x;
      s--;
      rt=rbst.update(rt,s,t,x);
    }
    if(c==1){
      int s,t;
      cin>>s>>t;
      s--;
      cout<<rbst.query(rt,s,t).first<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
