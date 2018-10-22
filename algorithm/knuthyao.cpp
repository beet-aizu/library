#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE

template<typename T,typename F>
T KnuthYao(int n,T INF,F cost){
  vector<vector<T> > dp(n+1,vector<T>(n+1,INF));
  vector<vector<int> > nx(n,vector<int>(n));
  for(int i=0;i<n;i++) dp[i][i]=0,nx[i][i]=i;
  for(int w=1;w<n;w++){
    for(int i=0;i+w<n;i++){
      int j=i+w;
      for(int r=nx[i][j-1];r<=nx[i+1][j];r++){
        T c=dp[i][r]+dp[r+1][j]+cost(i,r,j);
        if(dp[i][j]>c) dp[i][j]=c,nx[i][j]=r;
      }
    }
  }
  return dp[0][n-1];
}

signed AOJ_2488(){  
  Int n;
  cin>>n;
  vector<Int> x(n),y(n);
  for(Int i=0;i<n;i++) cin>>x[i]>>y[i];
  const Int INF = 1e18;
  auto calc=[&](int i,int r,int j){	      
              return r+1<n?x[r+1]-x[i]+y[r]-y[j]:INF;
            };
  cout<<KnuthYao(n,INF,calc)<<endl;
  return 0;
}
/*
  verified on 2018/09/30
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2488
*/

signed KUPC2012_J(){
  Int n;
  cin>>n;
  vector<Int> w(n);
  for(Int i=0;i<n;i++) cin>>w[i];
  vector<Int> s(n+1);
  for(Int i=0;i<n;i++) s[i+1]=s[i]+w[i];
  const Int INF =1e18;
  auto cost=[&](int i,int r,int j){return s[j+1]-s[i];};
  cout<<KnuthYao(n,INF,cost)<<endl;
  return 0;
}
/*
  verified on 2018/09/30
  https://beta.atcoder.jp/contests/kupc2012/tasks/kupc2012_10
*/

signed main(){
  //AOJ_2488();
  //KUPC2012_J();
  return 0;
}
