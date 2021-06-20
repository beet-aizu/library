// verification-helper: PROBLEM https://yukicoder.me/problems/22

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/bitvector.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,s,x,y,z;
  cin>>n>>s>>x>>y>>z;
  int q;
  cin>>q;
  BitVector bv(n+1);
  int a=s;
  for(int i=1;i<=n;i++){
    bv.set(i,a&1);
    a=(1LL*x*a+y)%z;
  }
  for(int i=0;i<q;i++){
    int s,t,u,v;
    cin>>s>>t>>u>>v;
    auto p=bv.get(s,t+1),q=bv.get(u,v+1);
    for(int i=0;i<(int)p.dat.size();i++) p.dat[i]^=q.dat[i];
    bv.set(u,v+1,p);
  }
  for(int i=1;i<=n;i++) cout<<(bv.get(i)?"O":"E");
  cout<<endl;
  return 0;
}
