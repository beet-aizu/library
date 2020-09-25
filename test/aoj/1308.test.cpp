// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../linearalgebra/binarymatrix.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int m,n,d;
  while(cin>>m>>n>>d,m){
    vector<vector<int> > s(n,vector<int>(m));
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        cin>>s[i][j];

    mat v(n*m,BS(0));
    auto idx=[&](int y,int x){return y*m+x;};
    auto in=[&](int y,int x){return 0<=y&&y<n&&0<=x&&x<m;};

    auto bfs=
      [&](int y,int x){
        int z=idx(y,x);
        v[z][z]=1;
        v[z][n*m]=s[y][x];

        vector<vector<int> > dp(n,vector<int>(m,-1));
        using P = pair<int, int>;
        queue<P> q;
        dp[y][x]=0;
        q.emplace(y,x);
        int dy[]={0,0,1,-1};
        int dx[]={1,-1,0,0};
        while(!q.empty()){
          tie(y,x)=q.front();q.pop();
          if(dp[y][x]==d) v[z][idx(y,x)]=1;
          for(int k=0;k<4;k++){
            int ny=y+dy[k],nx=x+dx[k];
            if(!in(ny,nx)||~dp[ny][nx]) continue;
            dp[ny][nx]=dp[y][x]+1;
            q.emplace(ny,nx);
          }
        }
      };

    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        bfs(i,j);

    int a=mrank(v,n*m);
    int b=mrank(v,n*m+1);
    cout<<(a==b)<<endl;
  }
  return 0;
}
