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
int n,m,c,s,g;
int p[30];
int q[105][55],r[105][55];
int cost[30][30000];
int dp[105];
int e[105][105];
vector<edge> v[105];

void calc(){
  int i,j,k;
  for(k=0;k<n;k++){
    bool used[105];
    //cout << "k:" << k << endl;
    for(j=0;j<c;j++){
      //cout << "j:" << j << endl;
      memset(used,0,sizeof(used));
      priority_queue<st> qu;
      qu.push(st(k,0,j,0));
      while(!qu.empty()){
	st ss=qu.top();qu.pop();
	if(used[ss.p]) continue;
	used[ss.p]=true;	
	//cout <<ss.p<<":"<<ss.c<<":"<<ss.d<<":"<<ss.a<<endl;
	if(!~e[k][ss.p]||e[k][ss.p]>ss.a) e[k][ss.p]=ss.a;
	for(i=0;i<v[ss.p].size();i++){
	  if(v[ss.p][i].c==ss.c){
	    qu.push(st(v[ss.p][i].t,ss.d+v[ss.p][i].d,v[ss.p][i].c,
		       ss.a+cost[v[ss.p][i].c][ss.d+v[ss.p][i].d]
		       -cost[v[ss.p][i].c][ss.d]));
	  }
	}
      }
    }
  }
}

int main(){
  while(cin>>n>>m>>c>>s>>g,n){
    s--;g--;
    int i,j,k,inf=1<<28;
    int x,y,a,b;
    for(i=0;i<105;i++) v[i].clear();
    memset(e,-1,sizeof(e));
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
      }
    }
    
    calc();
    
    memset(dp,-1,sizeof(dp));
    typedef pair<int,int> P;
    priority_queue<P> q;
    q.push(P(0,s));
    while(!q.empty()){
      P p=q.top();q.pop();
      //cout << p.first << ":" << p.second << endl;
      if(~dp[p.second]&&dp[p.second]<=p.first) continue;
      dp[p.second]=p.first;
      for(i=0;i<n;i++){
	if(e[p.second][i]>0&&(!~dp[i]||p.first+e[p.second][i]<dp[i]))
	  q.push(P(p.first+e[p.second][i],i));
      }
    }
    cout << dp[g] << endl;
  }
  return 0;
}
