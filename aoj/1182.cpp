#include<bits/stdc++.h>
using namespace std;
struct edge{int t,d,c;};
struct st{
  int p,d,c,a;
  st(int p,int d,int c,int a):p(p),d(d),c(c),a(a){}
  bool operator<(const st& s)const{
    return a>s.a;
  }
};


int n,m,c,sa,g;
int p[30];
int q[105][55],r[105][55];
int cost[30][30000];
int dp[105][30][30000];
vector<edge> v[105];

bool used[105];

void dfs(int u){
  if(used[u]) return;
  used[u]=true;
  for(int i=0;i<v[u].size();i++) dfs(v[u][i].t);
}

bool check(){
  memset(used,0,sizeof(used));
  dfs(sa);
  return used[g];
}

int main(){
  while(cin>>n>>m>>c>>sa>>g,n){
    sa--;g--;
    int i,j,k,inf=1<<28;
    int x,y,a,b;
    for(i=0;i<105;i++) v[i].clear();
    for(i=0;i<m;i++){
      cin>>x>>y>>a>>b;
      x--;y--;b--;
      v[x].push_back((edge){y,a,b});
      v[y].push_back((edge){x,a,b});
    }
    memset(p,0,sizeof(p));
    memset(q,0,sizeof(q));
    memset(r,0,sizeof(r));
    for(i=0;i<c;i++) cin>>p[i];
    for(i=0;i<c;i++){
      for(j=1;j<p[i];j++) cin>>q[i][j];
      q[i][p[i]]=inf;
      for(j=0;j<p[i];j++) cin>>r[i][j];
    }
    memset(cost,0,sizeof(cost));
    for(i=0;i<c;i++){
      k=0;
      for(j=0;j<30000-1;j++){
	if(q[i][k]<=j) k++;
	cost[i][j+1]=cost[i][j]+r[i][k-1];
	//if(j<40) cout << i << ":" << j << ":" << cost[i][j] << endl;
      }
    }

    
    if(check()){
      memset(dp,-1,sizeof(dp));
      priority_queue<st> qu;
      qu.push(st(sa,0,c,0));
      while(!qu.empty()){
	st s=qu.top();qu.pop();
	if(s.d>20000) continue;
	if(~dp[s.p][s.c][s.d]&&dp[s.p][s.c][s.d]<=s.a) continue;
	dp[s.p][s.c][s.d]=s.a;
	//cout <<s.p<<":"<<s.c<<":"<<s.d<<":"<<s.a<<endl;
	if(s.p==g) break;
	for(i=0;i<v[s.p].size();i++){
	  if(v[s.p][i].c==s.c){
	    if(s.d+v[s.p][i].d<=20000)
	      qu.push(st(v[s.p][i].t,s.d+v[s.p][i].d,v[s.p][i].c,
			 s.a+cost[v[s.p][i].c][s.d+v[s.p][i].d]
			 -cost[v[s.p][i].c][s.d]));
	  }else{
	    qu.push(st(v[s.p][i].t,v[s.p][i].d,v[s.p][i].c,
		       s.a+cost[v[s.p][i].c][v[s.p][i].d]));
	  }
	}
      }
    }
    int ans=-1;
    for(i=0;i<c;i++)
      for(j=0;j<30000;j++)
	if(!~ans||(~dp[g][i][j]&&dp[g][i][j]<ans)) ans=dp[g][i][j];
    cout << ans << endl;
  }
  return 0;
}
