#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef unsigned long long ull;
struct RollingHash2D{
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
  vector<string> S;
  vector<RollingHash> rh;
  vector<vector<ull> > hash;
  vector<ull> p;
  int h,w,r,c;
  ull B;
  RollingHash2D(){}
  RollingHash2D(vector<string> S,int r,int c,ull B=1000000009LL):S(S),r(r),c(c),B(B){init();};
  void init(){
    h=S.size();
    w=S[0].size();
    hash.resize(h+1,vector<ull>(w-c+1,0));
    rh.resize(h);
    for(int i=0;i<h;i++) rh[i]=RollingHash(S[i]);
    p.resize(h+1);
    p[0]=1;
    for(int i=0;i<h;i++) p[i+1]=p[i]*B;
    for(int j=0;j<w-c+1;j++){
      hash[0][j]=0;		    
      for(int i=0;i<h;i++)
	hash[i+1][j]=hash[i][j]*B+rh[i].find(j,j+c);
    }
  }
  //S[l,r)
  ull find(int i,int j){
    return hash[i+r][j]-hash[i][j]*p[r];
  }
};
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
verified on 2017/06/22
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C
*/
