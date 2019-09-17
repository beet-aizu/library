#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2432"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../matrix/squarematrix.cpp"
#undef call_from_test

#define IGNORE

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  const int MAX = 160;
  const int INF = 1e8;

  struct M{
    int v;
    M(){*this=add_identity();}
    M(int v):v(v){}
    M operator+(const M &a)const{return M(max(v,a.v));}
    M operator*(const M &a)const{return M(v+a.v);}
    static M add_identity(){return M(-INF);}
    static M mul_identity(){return M(0);}
  };
  using SM = SquareMatrix<M, MAX>;

  int n,m,k;
  cin>>n>>m>>k;
  vector<SM> vs(1),ws(1);

  for(int i=0;i<n;i++){
    vs[0][i][i]=0;
    ws[0][i][i]=0;
  }

  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    chmax(vs[0][a][b].v,c);
  }

  for(int t=0;t<20;t++){
    SM tv=vs[t]*vs[t];
    SM tw=vs[t]*ws[t];
    vs.emplace_back(tv);
    ws.emplace_back(tw);
  }

  auto len=[&](SM &sm)->int{
             int res=0;
             for(int i=0;i<n;i++)
               for(int j=0;j<n;j++)
                 chmax(res,sm[i][j].v);
             return res;
           };

  if(len(vs.back())<k){
    cout<<-1<<endl;
    return 0;
  }

  int ans=0;
  SM res(ws[0]);
  for(int t=20;t>=0;t--){
    SM tmp=res*ws[t];
    SM nxt=res*vs[t];
    if(len(tmp)<k){
      res.dat=nxt.dat;
      ans+=1<<t;
    }
  }
  cout<<ans<<endl;
  if(ans>100) return 0;

  int dp[MAX][MAX];
  int pr[MAX][MAX];
  for(int i=0;i<MAX;i++){
    for(int j=0;j<MAX;j++){
      dp[i][j]=-INF;
      pr[i][j]=-1;
    }
  }
  for(int v=0;v<n;v++) dp[0][v]=0;
  for(int i=0;i<ans;i++){
    for(int v=0;v<n;v++){
      for(int u=0;u<n;u++){
        if(dp[i+1][u]<dp[i][v]+vs[0][v][u].v){
          dp[i+1][u]=dp[i][v]+vs[0][v][u].v;
          pr[i+1][u]=v;
        }
      }
    }
  }
  int pos=0;
  for(int v=0;v<n;v++)
    if(dp[ans][v]>dp[ans][pos]) pos=v;

  vector<int> vx;
  for(int i=ans;i>=0;i--){
    vx.emplace_back(pos);
    pos=pr[i][pos];
  }
  reverse(vx.begin(),vx.end());
  for(int i=0;i<=ans;i++){
    if(i) cout<<" ";
    cout<<vx[i];
  }
  cout<<endl;
  return 0;
}
