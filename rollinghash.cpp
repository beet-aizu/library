#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef unsigned long long ull;
struct RollingHash{
  string S;
  ull B;
  vector<ull> hash,p;
  int len;
  RollingHash(){}
  RollingHash(string S,ull B=1000000007LL):S(S),B(B){init();};
  void init(){
    len=S.length();
    hash.resize(len+1);
    p.resize(len+1);
    hash[0]=0;p[0]=1;
    for(int i=0;i<len;i++){
      hash[i+1]=hash[i]*B+S[i];
      p[i+1]=p[i]*B;
    }
  }
  //S[l,r)
  ull find(int l,int r){
    return hash[r]-hash[l]*p[r-l];
  }
};
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
verified on 2017/04/28
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
*/
