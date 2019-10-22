#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../linkcuttree/path.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;
  using LCT = LinkCutTree<int, int>;
  LCT::F f=[](int a,int b){return a+b;};
  LCT lct(f,f,f,0,0);

  vector<LCT::Node*> vs(n);
  for(int i=0;i<n;i++) vs[i]=lct.create(i,0);
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int c;
      cin>>c;
      lct.link(vs[i],vs[c]);
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
      lct.expose(vs[a]);
      vs[a]->val=f(vs[a]->val,b);
    }
    if(t==1){
      int a;
      cin>>a;
      cout<<lct.query(vs[a])<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
