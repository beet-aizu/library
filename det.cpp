#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
const Int MAX = 2002;
using BS = bitset<MAX*2>;
void det(vector<BS> &v){
  int n=v.size();
  for(Int i=0;i<n;i++){
    for(Int k=i;k<n;k++){
      if(v[k][i]){
	swap(v[i],v[k]);
	break;
      }
    }
    for(Int k=0;k<n;k++)
      if(i!=k&&v[k][i]) v[k]^=v[i];
  }
}
//END CUT HERE
signed CFR382_D(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  Int n,m;
  cin>>n>>m;
  vector<BS> v(n,BS(0));
  for(Int i=0;i<n;i++) v[i][n+i]=1;
  vector<Int> a(m),b(m);
  for(Int i=0;i<m;i++){
    cin>>a[i]>>b[i];
    a[i]--;b[i]--;
    v[a[i]][b[i]]=1;
  }
  det(v);
  for(Int i=0;i<m;i++)
    cout<<(v[b[i]][a[i]+n]?"NO":"YES")<<endl;
  return 0;
}
/*
verified on 2018/01/09
http://codeforces.com/contest/736/problem/D
*/

signed ARC054_D(){
  int n;
  cin>>n;
  vector<BS> v(n,BS(0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      char c;
      cin>>c;
      v[i][j]=c-'0';
    }
  }
  det(v);
  int ans=1;
  for(int i=0;i<n;i++) ans&=v[i][i];
  cout<<(ans?"Odd":"Even")<<endl;
  return 0;
}
/*
verified on 2018/01/09
https://beta.atcoder.jp/contests/arc054/tasks/arc054_c
*/

signed AOJ_1308(){
  int m,n,d;
  while(cin>>m>>n>>d,m){
    vector<vector<int> > s(n,vector<int>(m));
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
	cin>>s[i][j];

    vector<BS> v(n*m,BS(0));
    auto idx=[&](int y,int x){return y*m+x;};
    auto in=[&](int y,int x){return 0<=y&&y<n&&0<=x&&x<m;};
    auto bfs=[&](int y,int x){
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
    
    auto u=v;
    det(v);
    int ans=1;
    for(int i=0;i<n*m;i++){
      int tmp=s[i/m][i%m];
      for(int j=0;j<n*m;j++) tmp+=u[i][j]&v[j][n*m];
      ans&=!(tmp&1);
    }
    cout<<ans<<endl;
  }
  return 0;
}
/*
verified on 2018/01/09
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308
*/

signed main(){
  //CFR382_D();
  //ARC054_D();
  AOJ_1308();
  return 0;
}
