#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct RollingHash{
  typedef unsigned long long ull;
  string S;
  ull B;
  int len;
  vector<ull> hash,p;
  RollingHash(){}
  RollingHash(string S_,ull B_=1000000007LL):
    S(S_),B(B_),len(S.length()),hash(len+1),p(len+1){
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
  verified on 2017/10/29
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp
*/
