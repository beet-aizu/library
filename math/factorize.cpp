#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T> 
map<T, int> factorize(T x){
  map<T, int> res;
  for(int i=2;i*i<=x;i++){
    while(x%i==0){
      x/=i;
      res[i]++;
    }
  }
  if(x!=1) res[x]++;
  return res;
}
//END CUT HERE
//INSERT ABOVE HERE
signed main(){
  int a,b;
  cin>>a>>b;
  map<int, int> m;
  for(int i=b+1;i<=a;i++){
    auto x=factorize(i);
    for(auto p:x) m[p.first]+=p.second;
  }
  const Int MOD = 1e9+7;
  Int ans=1;
  for(auto p:m) (ans*=(p.second+1))%=MOD;
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2018/01/29
  https://beta.atcoder.jp/contests/arc034/tasks/arc034_3
*/
