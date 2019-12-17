#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "rollinghash.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename T,T MOD,T B1,T B2>
auto rectangle_hash(vector<string> vs,int r,int c){
  vector< RollingHash<T, MOD, B1> > hs;
  for(string s:vs) hs.emplace_back(s);

  int h=vs.size(),w=vs[0].size();
  vector< vector<T> > res(h-r+1,vector<T>(w-c+1));

  for(int j=0;j+c<=w;j++){
    vector<T> ts(h);
    for(int i=0;i<h;i++)
      ts[i]=hs[i].find(j,j+c);

    RollingHash<T, MOD, B2> rh(ts);
    for(int i=0;i+r<=h;i++)
      res[i][j]=rh.find(i,i+r);
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
