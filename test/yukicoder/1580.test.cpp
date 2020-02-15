#define PROBLEM "https://yukicoder.me/problems/1580"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/convertbase.cpp"
#undef call_from_test

signed main(){
  long long p;
  cin>>p;
  auto ans=convert_base(p,7LL);
  for(auto x:ans) cout<<x;
  cout<<endl;
  return 0;
}
