#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 414514
set<int> G[MAX];
int indeg[MAX];
bool V[MAX];
vector<int> p;
void bfs(int s){
  queue<int> q;
  q.push(s);
  V[s]=1;
  while(!q.empty()){
    int u=q.front();q.pop();
    p.push_back(u);
    for(int v:G[u]){
      indeg[v]--;
      if(indeg[v]==0&&!V[v]){
	V[v]=1;
	q.push(v);
      }
    }
  }
}
void tsort(int n){
  memset(V,0,sizeof(V));
  memset(indeg,0,sizeof(indeg));
  for(int u=0;u<n;u++)
    for(int v:G[u])
      indeg[v]++;
  for(int u=0;u<n;u++)
    if(indeg[u]==0&&!V[u]) bfs(u);

  if((int)p.size()!=n){
    cout<<-1<<endl;
    return;
  }
  for(int i=0;i<n;i++)
    cout<<p[i]<<endl;
}

signed main(){
  int n,e;
  cin>>n>>e;
  for(int i=0;i<e;i++){
    int s,t;
    cin>>s>>t;
    G[s].insert(t);
  }
  tsort(n);
  return 0;
}

/*
verified on 2017/04/28
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp
*/
