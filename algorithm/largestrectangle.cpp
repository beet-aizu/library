#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#endif
//BEGIN CUT HERE
template<typename T>
T largestrectangle(vector<T> &v){
  int n=v.size();
  T res=0;
  using P = pair<int, T>;
  stack<P> sp;
  sp.emplace(-1,T(0));
  for(int i=0;i<n;i++){
    int j=i;
    while(sp.top().second>v[i]){
      j=sp.top().first;
      res=max(res,(i-j)*sp.top().second);
      sp.pop();
    }
    if(sp.top().second<v[i]) sp.emplace(j,v[i]);
  }
  while(!sp.empty()){
    res=max(res,(n-sp.top().first)*sp.top().second);
    sp.pop();
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed DPL_3_C(){
  using ll = long long;
  ll n;
  cin>>n;
  vector<ll> v(n);
  for(Int i=0;i<n;i++) cin>>v[i];
  cout<<largestrectangle(v)<<endl;
  return 0;
}
/*
  verified on 2018/06/11
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C&lang=jp
*/

signed main(){
  DPL_3_C();
  return 0;
}
#endif
