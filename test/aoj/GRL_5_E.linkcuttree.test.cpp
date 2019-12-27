#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/path.cpp"
#undef call_from_test

signed main(){
  using ll = long long;

  int n;
  cin>>n;

  using P = pair<ll, ll>;
  using Node = NodeBase<P, ll>;
  constexpr size_t LIM = 1e6;
  using LCT = Path<Node, LIM>;

  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,int b){return P(a.first+b*a.second,a.second);};
  auto h=[](ll a,ll b){return a+b;};
  LCT lct(f,g,h,P(0,0),0);

  for(int i=0;i<n;i++) lct.create(P(0,1));
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int c;
      cin>>c;
      lct.link(lct[i],lct[c]);
    }
  }

  int q;
  cin>>q;
  ll sum=0;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int a,b;
      cin>>a>>b;
      lct.update(lct[a],b);
      sum+=b;
    }
    if(t==1){
      int a;
      cin>>a;
      cout<<lct.query(lct[a]).first-sum<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
