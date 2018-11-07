#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct RollingHash{
  using ull = unsigned long long;
  vector<ull> hash,p;
  RollingHash(){}
  RollingHash(const string &s,ull B=1000000007LL){
    int n=s.size();
    hash.assign(n+1,0);
    p.assign(n+1,1);
    for(int i=0;i<n;i++){
      hash[i+1]=hash[i]*B+s[i];
      p[i+1]=p[i]*B;
    }
  }
  //S[l, r)
  ull find(int l,int r){
    return hash[r]-hash[l]*p[r-l];
  }
};
//END CUT HERE

signed main(){
  string t,p;
  cin>>t>>p;
  RollingHash rt(t),rp(p);
  for(int i=0;i<(int)(t.size()-p.size())+1;i++){
    if(rt.find(i,i+p.size())==rp.find(0,p.size())) cout<<i<<endl;
  }
  return 0;
}
/*
  verified on 2018/11/07
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp
*/
