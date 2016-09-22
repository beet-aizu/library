#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,s,g;
  while(cin>>n>>m,n||m){
    cin>>s>>g;
    s--;g--;
    int d[n][n],c[n][n];
    memset(d,-1,sizeof(d));
    memset(c,-1,sizeof(c));
    int i,j,k,l,x,y;
    for(i=0;i<m;i++){
      cin>>x>>y>>j>>k;
      x--;y--;
      d[x][y]=d[y][x]=j;
      c[x][y]=c[y][x]=k;
    }
    double v[n][50][n];
    double inf=1<<28,p,ans=inf;
    for(i=0;i<n;i++) for(j=0;j<50;j++) for(k=0;k<n;k++) v[i][j][k]=inf;
    typedef pair<int,int> PPP;
    typedef pair<int,PPP> P;
    typedef pair<double,P> PP;
    priority_queue<PP,vector<PP>,greater<PP> > q;
    q.push(PP(0,P(s,PPP(1,-1))));
    while(!q.empty()){
      x=q.top().second.first;
      y=q.top().second.second.first;
      k=q.top().second.second.second;
      p=q.top().first;q.pop();
      if(v[x][y][k]<=p) continue;
      v[x][y][k]=p;
      if(x==g&&y==1) break;
      for(i=0;i<n;i++){
	if(!~d[x][i]||i==k) continue;
	for(j=-1;j<=1;j++){
	  if(k==-1&&j!=0) continue;
	  if(y+j<=0||c[x][i]<y+j) continue;
	  q.push(PP(p+(double)d[x][i]/(y+j),P(i,PPP(y+j,x))));
	}
      }
    }
    for(i=0;i<n;i++) ans=min(ans,v[g][1][i]);
    if(ans!=inf) printf("%.8f\n",ans);
    else printf("unreachable\n");
  }
  return 0;
}
