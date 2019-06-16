#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
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
//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  string t,p;
  cin>>t>>p;
  using ll = long long;
  const ll MOD = 1e9+7;
  const ll B = 1777771;
  using RH = RollingHash<ll, MOD, B>;
  RH rt(t),rp(p);
  for(int i=0;i<(int)t.size()-(int)p.size()+1;i++){
    if(rt.find(i,i+p.size())==rp.find(0,p.size())) cout<<i<<"\n";
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/16
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp
*/
