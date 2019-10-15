#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2292"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/palindromictree.cpp"
#include "../../string/rollinghash.cpp"
#undef call_from_test

signed main(){
  using ll = long long;
  string s,t;
  cin>>s>>t;

  PalindromicTree p1(s),p2(t);
  const int MOD = 1e9+7;
  const int BASE = 1777771;
  RollingHash<int, MOD, BASE> r1(s),r2(t);

  const int MAX = 5e5+100;
  map<int, int> m1[MAX];
  for(int i=0;i<(int)p1.n;i++){
    PalindromicTree::node& u=p1.v[i];
    if(u.app<0) continue;
    m1[u.len][r1.find(u.app,u.app+u.len)]=u.cnt;
  }

  ll ans=0;
  for(int i=0;i<(int)p2.n;i++){
    PalindromicTree::node& u=p2.v[i];
    int x=r2.find(u.app,u.app+u.len);
    if(u.app<0||!m1[u.len].count(x)) continue;
    ans+=(ll)m1[u.len][x]*u.cnt;
  }

  cout<<ans<<endl;
  return 0;
}
