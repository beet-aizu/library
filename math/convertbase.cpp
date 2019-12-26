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

// verify positive base
signed YUKI_499(){
  long long p;
  cin>>p;
  auto ans=convert_base(p,7LL);
  for(auto x:ans) cout<<x;
  cout<<endl;
  return 0;
}
/*
  verified on 2019/12/26
  https://yukicoder.me/problems/no/499
*/

signed main(){
  //YUKI_499();
  return 0;
}
#endif
