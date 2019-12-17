#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template <typename T>
vector<T> dijkstra(int s,vector< vector< pair<int, T> > > & G){
  const T INF = numeric_limits<T>::max();
  using P = pair<T, int>;
  int n=G.size();
  vector<T> ds(n,INF);
  vector<int> bs(n,-1);
  priority_queue<P, vector<P>, greater<P> > pq;
  ds[s]=0;
  pq.emplace(ds[s],s);
  while(!pq.empty()){
    P p=pq.top();pq.pop();
    int v=p.second;
    if(ds[v]<p.first) continue;
    for(auto& e:G[v]){
      int u=e.first;
      T c=e.second;
      if(ds[u]>ds[v]+c){
        ds[u]=ds[v]+c;
        bs[u]=v;
        pq.emplace(ds[u],u);
      }
    }
  }
  return ds;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  int n,l;
  scanf("%d %d",&n,&l);

  using P = pair<int, long long>;
  vector<vector<P> > G(l+1);
  for(int i=0;i<n;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    G[a].emplace_back(b,c);
  }

  for(int i=0;i<l;i++)
    G[i+1].emplace_back(i,0);

  printf("%lld\n",dijkstra(0,G)[l]);
  return 0;
}
/*
  verified on 2018/01/16
  https://atcoder.jp/contests/arc026/tasks/arc026_3
*/
#endif
