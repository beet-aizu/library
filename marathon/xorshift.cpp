#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
int xor128(){
  static int x = 123456789;
  static int y = 362436069;
  static int z = 521288629;
  static int w = 88675123; 
  int t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}
//END CUT HERE
//INSERT ABOVE HERE
signed main(){
  return 0;
}
