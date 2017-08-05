#include<bits/stdc++.h>
using namespace std;
#define int long long
//BEGIN CUT HERE
typedef pair<int,int> P;
vector<int> dijkstra(int s,vector<vector<P> > & G){
  int n=G.size();
  int INF=1LL<<55LL;
  vector<int> d(n,INF);
  priority_queue<P,vector<P>,greater<P> > q;
  d[s]=0;
  q.push(P(d[s],s));
  while(!q.empty()){
    P p=q.top();q.pop();
    int v=p.second;
    if(d[v]<p.first) continue;
    for(P e:G[v]){
      int u=e.first,c=e.second;
      if(d[u]>d[v]+c){
	d[u]=d[v]+c;
	q.push(P(d[u],u));
      }
    }
  }
  return d;
}
//END CUT HERE

signed main(){
  int n,l;
  cin>>n>>l;
  vector<vector<P> > G(l+1);
  for(int i=0;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    G[a].push_back(P(b,c));
  }
  for(int i=0;i<l;i++)
    G[i+1].push_back(P(i,0));
  cout<<dijkstra(0,G)[l]<<endl;
  return 0;
}

/*
verified on 2017/08/05
http://arc026.contest.atcoder.jp/tasks/arc026_3
*/
