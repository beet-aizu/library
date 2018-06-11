#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

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
      chmax(res,(i-j)*sp.top().second);
      sp.pop();
    }
    if(sp.top().second<v[i]) sp.emplace(j,v[i]);
  }
  while(!sp.empty()){
    chmax(res,(n-sp.top().first)*sp.top().second);
    sp.pop();
  }
  return res;
}

//END CUT HERE
//INSERT ABOVE HERE
signed DPL_3_C(){
  Int n;
  cin>>n;
  vector<Int> v(n);
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
