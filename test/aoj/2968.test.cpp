// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2968

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../tools/chminmax.cpp"
#include "../../math/factorize.cpp"
#include "../../vector/compress.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  auto as=read(n);

  vector<int> ps;
  for(auto a:as)
    for(auto[p,_]:factorize(a))
      ps.emplace_back(p);

  long long ans=0;
  for(int p:compress(ps)){
    long long res=0;
    for(int a:as)
      if(a%p==0) res+=a;
    chmax(ans,res);
  }

  cout<<ans<<endl;
  return 0;
}
