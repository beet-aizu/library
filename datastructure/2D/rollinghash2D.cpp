#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct RollingHash2D{
  typedef unsigned long long ull;
  
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
  
  vector<string> S;
  int h,w,r,c;
  ull B;
  vector<ull> p;
  vector<vector<ull> > hash;
  vector<RollingHash> rh;
  RollingHash2D(){}
  RollingHash2D(vector<string> S_,int r_,int c_,ull B_=1000000009LL):
    S(S_),h(S_.size()),w(S_[0].size()),r(r_),c(c_),B(B_),
    p(h+1),hash(h+1,vector<ull>(w-c+1,0)),rh(h){
    for(int i=0;i<h;i++) rh[i]=RollingHash(S[i]);
    p[0]=1;
    for(int i=0;i<h;i++) p[i+1]=p[i]*B;
    for(int j=0;j<w-c+1;j++){
      hash[0][j]=0;		    
      for(int i=0;i<h;i++)
        hash[i+1][j]=hash[i][j]*B+rh[i].find(j,j+c);
    }
  }
  //[i,i+r) * [j,j+c)
  ull find(int i,int j){
    return hash[i+r][j]-hash[i][j]*p[r];
  }
};
//END CUT HERE

signed main(){
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++) cin>>s[i];
  int r,c;
  cin>>r>>c;
  vector<string> t(r);
  for(int i=0;i<r;i++) cin>>t[i];
  RollingHash2D srh(s,r,c);
  RollingHash2D trh(t,r,c);
  for(int i=0;i<h-r+1;i++){
    for(int j=0;j<w-c+1;j++){
      if(srh.find(i,j)==trh.find(0,0)) cout<<i<<" "<<j<<endl;
    }
  }
  return 0;
}

/*
  verified on 2017/10/29
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C
*/
