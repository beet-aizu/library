#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
const int MAX = 2002;
using BS = bitset<MAX*2>;
using mat = vector<BS>;

void gauss(mat &v){
  int n=v.size();
  for(int i=0;i<n;i++){
    for(int k=i;k<n;k++){
      if(v[k][i]){
        swap(v[i],v[k]);
        break;
      }
    }
    for(int k=0;k<n;k++)
      if(i!=k and v[k][i]) v[k]^=v[i];
  }
}

int mrank(mat v,int m){
  int n=v.size();
  int r=0,c=0;
  for(int i=0;i<n;i++){
    int s=-1;
    while(c<m){
      for(int j=i;j<n;j++){
        if(v[j][c]){
          s=j;
          break;
        }
      }
      if(~s) break;
      c++;
    }
    if(c>=m) break;

    swap(v[i],v[s]);
    for(int j=0;j<n;j++)
      if(i!=j and v[j][c]) v[j]^=v[i];

    r++;c++;
  }
  return r;
}

mat mul(const mat &a,const mat &b){
  int n=a.size();
  vector<vector<int> > tmp(n,vector<int>(n,0));
  mat res(n,BS(0));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      for(int k=0;k<n;k++)
        tmp[i][j]+=(a[i][k]&b[k][j]);

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      res[i][j]=tmp[i][j]&1;

  return res;
}

mat mat_pow(mat v,long long k){
  int n=v.size();
  mat res(n,BS(0));
  for(int i=0;i<n;i++)
    res[i][i]=1;
  while(k){
    if(k&1) res=mul(res,v);
    v=mul(v,v);
    k>>=1;
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#undef call_from_test

signed CFR382_D(){
  int n,m;
  cin>>n>>m;
  mat v(n,BS(0));
  for(int i=0;i<n;i++) v[i][n+i]=1;
  vector<int> as(m),bs(m);
  for(int i=0;i<m;i++){
    cin>>as[i]>>bs[i];
    as[i]--;bs[i]--;
    v[as[i]][bs[i]]=1;
  }
  gauss(v);
  for(int i=0;i<m;i++)
    cout<<(v[bs[i]][as[i]+n]?"NO":"YES")<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/12/17
  http://codeforces.com/contest/736/problem/D
*/

signed ARC054_D(){
  int n;
  cin>>n;
  mat v(n,BS(0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      char c;
      cin>>c;
      v[i][j]=c-'0';
    }
  }
  int ans=mrank(v,n);
  cout<<(ans==n?"Odd":"Even")<<endl;
  return 0;
}
/*
  verified on 2019/12/17
  https://atcoder.jp/contests/arc054/tasks/arc054_c
*/

signed main(){
  //CFR382_D();
  //ARC054_D();
  return 0;
}

#endif
