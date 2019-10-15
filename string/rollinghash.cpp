#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#endif
//BEGIN CUT HERE
template<typename T,T MOD,T B>
struct RollingHash{
  vector<T> hash,p;
  RollingHash(){}
  RollingHash(const string &s){
    int n=s.size();
    hash.assign(n+1,0);
    p.assign(n+1,1);
    for(int i=0;i<n;i++){
      hash[i+1]=(hash[i]*B+s[i])%MOD;
      p[i+1]=p[i]*B%MOD;
    }
  }
  //S[l, r)
  T find(int l,int r){
    T res=hash[r]+MOD-hash[l]*p[r-l]%MOD;
    return res>=MOD?res-MOD:res;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
