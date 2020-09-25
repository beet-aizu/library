// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0233

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/convertbase.cpp"
#undef call_from_test

signed main(){
  long long p;
  while(cin>>p,p){
    auto ans=convert_base(p,-10LL);
    for(auto x:ans) cout<<x;
    cout<<endl;
  }
  return 0;
}
