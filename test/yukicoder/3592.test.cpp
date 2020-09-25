// verification-helper: PROBLEM https://yukicoder.me/problems/3592

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/weightedunionfind.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,q;
  cin>>n>>q;
  WeightedUnionFind<int> uf(n);

  vector<int> vs(n,0);
  auto add=[&](int a,int b){
    vs[uf.find(a)]+=b;
  };
  auto query=[&](int a){
    int r=uf.find(a);
    return uf.diff(a,r)+vs[r];
  };
  auto unite=[&](int a,int b){
    a=uf.find(a);
    b=uf.find(b);
    if(a==b) return;
    int x=query(a);
    int y=query(b);
    uf.unite(a,b,x-y);
  };

  for(int i=0;i<q;i++){
    int t,a,b;
    cin>>t>>a>>b;
    if(t==1){
      a--;b--;
      unite(a,b);
    }
    if(t==2){
      a--;
      add(a,b);
    }
    if(t==3){
      a--;
      cout<<query(a)<<newl;
    }
  }
  return 0;
}
