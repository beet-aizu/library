#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2212"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../string/trie.cpp"
#include "../../string/ahocorasick.cpp"
#undef call_from_test

int dp[111][55][55];
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int h,w;
  while(cin>>h>>w,h){
    vector<string> ss(h);
    for(int i=0;i<h;i++) cin>>ss[i];
    int p;
    cin>>p;
    vector<string> ps(p);
    for(int i=0;i<p;i++) cin>>ps[i];
    auto conv=
      [&](char c){
        if(c=='U') return 0;
        if(c=='R') return 1;
        if(c=='D') return 2;
        if(c=='L') return 3;
        return -1;
      };
    AhoCorasick<4> aho(conv);
    for(int i=0;i<p;i++) aho.add(ps[i],i);
    aho.build(false);

    memset(dp,-1,sizeof(dp));
    using T = tuple<int, int, int>;
    queue<T> que;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(ss[i][j]=='S'){
          dp[0][i][j]=0;
          que.emplace(0,i,j);
        }
      }
    }

    string base="URDL";
    int dy[]={-1,0,1,0};
    int dx[]={0,1,0,-1};
    auto in=[&](int y,int x){return 0<=y&&y<h&&0<=x&&x<w;};

    int ans=-1;
    while(!que.empty()){
      int p,y,x;
      tie(p,y,x)=que.front();que.pop();
      if(ss[y][x]=='G'){
        ans=dp[p][y][x];
        break;
      }
      for(int k=0;k<4;k++){
        int ny=y+dy[k],nx=x+dx[k];
        if(!in(ny,nx)||ss[ny][nx]=='#') continue;
        char c=base[k];
        int q=aho.move(p,c);
        if(aho.count(q)) continue;
        if(~dp[q][ny][nx]) continue;
        dp[q][ny][nx]=dp[p][y][x]+1;
        que.emplace(q,ny,nx);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
