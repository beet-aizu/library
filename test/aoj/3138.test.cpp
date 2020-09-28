// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3138

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/dice.cpp"
#include "../../tools/drop.cpp"
#undef call_from_test

int dp[100][200][200];
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int h,w;
  cin>>h>>w;
  vector<string> ss(h);
  for(int i=0;i<h;i++) cin>>ss[i];

  Die d;
  d.top()='1';
  d.bottom()='6';
  d.north()='5';
  d.south()='2';
  d.east()='3';
  d.west()='4';

  auto ds=makeDice(d);
  map<array<int, 6>, int> idx;
  for(int i=0;i<(int)ds.size();i++)
    idx[ds[i].fs]=i;

  memset(dp,0,sizeof(dp));
  using T = tuple<int, int, int>;
  queue<T> que;

  dp[idx[d.fs]][0][0]=1;
  que.emplace(idx[d.fs],0,0);

  while(!que.empty()){
    int k,i,j;
    tie(k,i,j)=que.front();que.pop();
    if(i==h-1 and j==w-1) drop("YES");
    d=ds[k];

    if(i+1<h){
      int ni=i+1,nj=j;
      Die nd(d);
      nd.roll('S');
      if(nd.bottom()==ss[ni][nj] and !dp[idx[nd.fs]][ni][nj]){
        dp[idx[nd.fs]][ni][nj]=1;
        que.emplace(idx[nd.fs],ni,nj);
      }
    }

    if(i-1>=0){
      int ni=i-1,nj=j;
      Die nd(d);
      nd.roll('N');
      if(nd.bottom()==ss[ni][nj] and !dp[idx[nd.fs]][ni][nj]){
        dp[idx[nd.fs]][ni][nj]=1;
        que.emplace(idx[nd.fs],ni,nj);
      }
    }

    if(j+1<w){
      int ni=i,nj=j+1;
      Die nd(d);
      nd.roll('E');
      if(nd.bottom()==ss[ni][nj] and !dp[idx[nd.fs]][ni][nj]){
        dp[idx[nd.fs]][ni][nj]=1;
        que.emplace(idx[nd.fs],ni,nj);
      }
    }

    if(j-1>=0){
      int ni=i,nj=j-1;
      Die nd(d);
      nd.roll('W');
      if(nd.bottom()==ss[ni][nj] and !dp[idx[nd.fs]][ni][nj]){
        dp[idx[nd.fs]][ni][nj]=1;
        que.emplace(idx[nd.fs],ni,nj);
      }
    }
  }

  drop("NO");
  return 0;
}
