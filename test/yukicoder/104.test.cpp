#define PROBLEM "https://yukicoder.me/problems/104"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../mod/mint.cpp"
#include "../../polynomial/berlekampmassey.cpp"
#include "../../math/kitamasa.cpp"
#undef call_from_test

signed main(){
  long long n;
  int p,c;
  cin>>n>>p>>c;

  using M = Mint<int>;

  const int d = 1500;
  const int MAX = p+c+1;
  vector<vector<M>> cf(MAX,vector<M>(d,0));
  cf[0][0]=M(1);

  for(int v:{2,3,5,7,11,13}){
    vector<vector<M>> nx(MAX,vector<M>(d,0));
    for(int t=0;t<=p;t++)
      for(int i=0;i<d;i++)
        for(int j=0;t+j<=p&&i+v*j<d;j++)
          nx[t+j][i+v*j]+=cf[t][i];
    swap(cf,nx);
  }

  for(int v:{4,6,8,9,10,12}){
    vector<vector<M>> nx(MAX,vector<M>(d,0));
    for(int t=p;t<=p+c;t++)
      for(int i=0;i<d;i++)
        for(int j=0;t+j<=p+c&&i+v*j<d;j++)
          nx[t+j][i+v*j]+=cf[t][i];
    swap(cf,nx);
  }

  vector<M> dp(d*3,0),as(d*3,0);
  dp[0]=M(1);
  for(int i=0;i<(int)dp.size();i++){
    for(int j=0;j<d&&i+j<(int)dp.size();j++)
      dp[i+j]+=dp[i]*cf[p+c][j];

    for(int j=1;i+j<(int)dp.size();j++)
      as[i]+=dp[i+j];
  }
  as.resize(d*2);

  auto cs=berlekamp_massey(as);
  cs.pop_back();
  for(auto &c:cs) c*=-M(1);

  Kitamasa<M> kt(cs);
  as.resize(cs.size());
  cout<<kt.calc(as,n-1)<<endl;
  return 0;
}
