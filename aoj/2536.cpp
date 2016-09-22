#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
#define INF (1<<21)
#define WHITE 0
#define GRAY  1
#define BLACK 2
int M[MAX][MAX];
int n,x;
int prim(){
  vector<int> v;
  int u,minv;
  int d[MAX],p[MAX],color[MAX];
  for(int i=0;i<n;i++){
    d[i]=INF;
    p[i]=-1;
    color[i]=WHITE;
  }
  d[0]=0;
  while(1){
    minv=INF;
    u=-1;
    for(int i=0;i<n;i++){
      if(minv>d[i]&&color[i]!=BLACK){
	u=i;
	minv=d[i];
      }
    }
    if(u==-1) break;
    color[u]=BLACK;
    for(int i=0;i<n;i++){
      if(color[i]!=BLACK&&M[u][i]!=INF){
	if(d[i]>M[u][i]){
	  d[i]=M[u][i];
	  p[i]=u;
	  color[i]=GRAY;
	}
      }
    }
  }
  for(int i=0;i<n;i++){
    if(~p[i]) v.push_back(M[i][p[i]]);
  }
  sort(v.begin(),v.end());
  if(v.size()%2) return v[v.size()/2];
  return (v[v.size()/2]+v[v.size()/2-1])/2;
}
int main(){
  while(cin>>n>>x,n||x){
    int s,t,c;
    for(int i=0;i<MAX;i++){
      for(int j=0;j<MAX;j++){
	M[i][j]=INF;
      }
    }
    for(int i=0;i<x;i++){
      cin>>s>>t>>c;
      M[s-1][t-1]=c;
      M[t-1][s-1]=c;
    }
    cout << prim() << endl;
  }
  return 0;
}
