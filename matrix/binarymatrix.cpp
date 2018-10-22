#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
const Int MAX = 2002;
using BS = bitset<MAX*2>;
using mat = vector<BS>;

void gauss(mat &v){
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
      if(i!=j&&v[j][c]) v[j]^=v[i];
    
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

mat mat_pow(mat v,int k){
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

signed CFR382_D(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  Int n,m;
  cin>>n>>m;
  mat v(n,BS(0));
  for(Int i=0;i<n;i++) v[i][n+i]=1;
  vector<Int> a(m),b(m);
  for(Int i=0;i<m;i++){
    cin>>a[i]>>b[i];
    a[i]--;b[i]--;
    v[a[i]][b[i]]=1;
  }
  gauss(v);
  for(Int i=0;i<m;i++)
    cout<<(v[b[i]][a[i]+n]?"NO":"YES")<<endl;
  return 0;
}
/*
  verified on 2018/01/22
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
  verified on 2018/01/22
  https://beta.atcoder.jp/contests/arc054/tasks/arc054_c
*/

signed AOJ_1308(){
  int m,n,d;
  while(cin>>m>>n>>d,m){
    vector<vector<int> > s(n,vector<int>(m));
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        cin>>s[i][j];

    mat v(n*m,BS(0));
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
    
    int a=mrank(v,n*m);
    int b=mrank(v,n*m+1);
    cout<<(a==b)<<endl;
  }
  return 0;
}
/*
  verified on 2018/01/23
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308
*/

signed AOJ_2624(){
  int n;
  cin>>n;
  mat v(n,BS(0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int k;
      cin>>k;
      v[i][j]=k;
    }
  }
  BS w;
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    w[i]=k;
  }
  int t;
  cin>>t;
  v=mat_pow(v,t);

  int a=mrank(v,n);
  for(int i=0;i<n;i++) v[i][n]=w[i];
  int b=mrank(v,n+1);

  if(a!=b){
    cout<<"none"<<endl;
    return 0;
  }

  if(a!=n){
    cout<<"ambiguous"<<endl;
    return 0;
  }
  
  gauss(v);
  for(int i=0;i<n;i++) cout<<v[i][n]<<" \n"[i==n-1];
  
  return 0;
}
/*
  verified on 2018/01/22
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624
*/



signed main(){
  //CFR382_D();
  //ARC054_D();
  AOJ_1308();
  //AOJ_2624();
  return 0;
}
