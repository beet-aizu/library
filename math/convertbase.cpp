#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
vector<T> convert_base(T x,T b){
  vector<T> res;
  T t=1,k=abs(b);
  while(x){
    res.emplace_back((x*t)%k);
    if(res.back()<0) res.back()+=k;
    x-=res.back()*t;
    x/=k;
    t*=b/k;
  }
  if(res.empty()) res.emplace_back(0);
  reverse(res.begin(),res.end());
  return res;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed ABC105_C(){
  long long p;
  cin>>p;
  auto ans=convert_base(p,-2LL);
  for(auto x:ans) cout<<x;
  cout<<endl;
  return 0;
}
/*
  verified on 2019/03/31
  https://atcoder.jp/contests/abc105/tasks/abc105_c
*/

signed YUKI_499(){
  long long p;
  cin>>p;
  auto ans=convert_base(p,7LL);
  for(auto x:ans) cout<<x;
  cout<<endl;
  return 0;
}
/*
  verified on 2019/03/31
  https://yukicoder.me/problems/no/499
*/

signed YUKI_782(){
  long long t,b;
  cin>>t>>b;
  while(t--){
    long long p;
    cin>>p;
    auto ans=convert_base(p,b);
    for(auto x:ans) cout<<x;
    cout<<endl;
  }
  return 0;
}
/*
  verified on 2019/03/31
  https://yukicoder.me/problems/no/782
*/

signed main(){
  //ABC105_C();
  //YUKI_499();
  //YUKI_782();
  return 0;
}
#endif
