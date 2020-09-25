// verification-helper: PROBLEM https://yukicoder.me/problems/1973

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../math/kitamasa.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using M = Mint<int, 17>;
  const int n = 4;
  vector<M> as(n,0),cs(n,1);
  as[n-1]=1;
  Kitamasa<M> fib(cs);

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    long long p;
    cin>>p;
    cout<<fib.calc(as,p-1)<<"\n";
  }
  return 0;
}
