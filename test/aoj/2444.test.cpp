#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2444"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../string/rollinghash.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  const int MOD = 1e9+7;
  const int B1 = 1e8+7;
  const int B2 = 1777771;
  RollingHash<int, MOD, B1> rh1(s);
  RollingHash<int, MOD, B2> rh2(s);

  int l=0,r=1;
  set<pair<int, int>> sp;
  for(int i=0;i<m;i++){
    string t;
    cin>>t;
    if(t=="L++") l++;
    if(t=="L--") l--;
    if(t=="R++") r++;
    if(t=="R--") r--;
    sp.emplace(rh1.find(l,r),rh2.find(l,r));
  }

  cout<<sp.size()<<endl;
  return 0;
}
