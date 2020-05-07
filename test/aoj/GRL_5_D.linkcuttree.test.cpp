#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/path.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  using Node = NodeBase<int, int>;
  constexpr size_t LIM = 1e5+100;
  using LCT = Path<Node, LIM>;

  auto f=[](int a,int b){return a+b;};
  LCT lct(f,f,f,0);

  for(int i=0;i<n;i++) lct.create(0);
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
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int a,b;
      cin>>a>>b;
      lct.expose(lct[a]);
      lct[a]->val+=b;
      lct.pushup(lct[a]);
    }
    if(t==1){
      int a;
      cin>>a;
      cout<<lct.query(lct[a])<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
