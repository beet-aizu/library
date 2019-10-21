#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1312"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../string/rollinghash.cpp"
#include "../../string/rectanglehash.cpp"
#undef call_from_test

int conv(char c){
  if(isupper(c)) return c-'A';
  if(islower(c)) return 26+c-'a';
  if(isdigit(c)) return 52+c-'0';
  if(c=='+') return 62;
  if(c=='/') return 63;
  assert(0);
}

vector<string> decode(vector<string> vs,int h,int w){
  vector<string> rs(h,string(w,'$'));
  for(int i=0;i<h;i++)
    for(int j=0;j<(int)vs[i].size();j++)
      for(int k=0;k<6&&j*6+k<w;k++)
        rs[i][j*6+k]=char('0'+((conv(vs[i][j])>>(5-k))&1));
  return rs;
}

signed main(){
  int w,h,p;
  while(cin>>w>>h>>p,w){
    vector<string> ss(h);
    for(int i=0;i<h;i++) cin>>ss[i];

    vector<string> ts(p);
    for(int i=0;i<p;i++) cin>>ts[i];

    const int MOD = 1e9+7;
    const int B1 = 1777771;
    const int B2 = 1e8+7;
    auto srh=rectangle_hash<int, MOD, B1, B2>(decode(ss,h,w),p,p);

    vector< vector<int> > found(h,vector<int>(w,0));

    auto pat=decode(ts,p,p);
    for(int rev=0;rev<2;rev++){
      for(int rot=0;rot<4;rot++){
        auto tmp(pat);
        for(int i=0;i<p;i++)
          for(int j=0;j<p;j++)
            pat[i][j]=tmp[j][p-(i+1)];

        auto val=rectangle_hash<int, MOD, B1, B2>(pat,p,p)[0][0];

        for(int i=0;i<h-p+1;i++)
          for(int j=0;j<w-p+1;j++)
            if(srh[i][j]==val) found[i][j]=1;
      }

      for(auto &s:pat)
        reverse(s.begin(),s.end());
    }

    int cnt=0;
    for(int i=0;i<h-p+1;i++)
      for(int j=0;j<w-p+1;j++)
        if(found[i][j]) cnt++;

    cout<<cnt<<"\n";
  }
  cout<<flush;
  return 0;
}
