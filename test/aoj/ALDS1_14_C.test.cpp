#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../string/rollinghash.cpp"
#include "../../string/rectanglehash.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int h,w;
  cin>>h>>w;
  vector<string> ss(h);
  for(int i=0;i<h;i++) cin>>ss[i];

  int r,c;
  cin>>r>>c;
  vector<string> ts(r);
  for(int i=0;i<r;i++) cin>>ts[i];

  const int MOD = 1e9+7;
  const int B1 = 1777771;
  const int B2 = 1e8+7;
  auto srh=rectangle_hash<int, MOD, B1, B2>(ss,r,c);
  auto trh=rectangle_hash<int, MOD, B1, B2>(ts,r,c);

  for(int i=0;i<h-r+1;i++)
    for(int j=0;j<w-c+1;j++)
      if(srh[i][j]==trh[0][0]) cout<<i<<" "<<j<<"\n";

  return 0;
}
