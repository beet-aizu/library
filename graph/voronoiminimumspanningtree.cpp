#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct VoronoiMST{
  int n;
  using E = pair<int, T>;
  using P = pair<T, int>;
  vector<vector<E> > G;
  VoronoiMST(vector<T> &x){
    n=x.size();
    G.assign(n<<1,vector<E>());
    for(int i=0;i<n;i++) G[i].emplace_back(n+i,x[i]);
  }
  void add_edge(int u,int v,T c){
    G[u+n].emplace_back(v+n,c);
    G[v+n].emplace_back(u+n,c);
  }
  vector<vector<E> > build(){
    priority_queue<P, vector<P>, greater<P> > pq;
    const T INF = numeric_limits<T>::max();
    vector<T> dist(n<<1,INF);
    vector<int> from(n<<1,-1);
    for(int i=0;i<n;i++){
      dist[i]=0;from[i]=i;
      pq.emplace(dist[i],i);
    }
    while(!pq.empty()){
      T d;
      int v;
      tie(d,v)=pq.top();pq.pop();
      if(dist[v]<d) continue;
      for(E e:G[v]){
        int u=e.first;
        T c=e.second;
        if(dist[u]<=dist[v]+c) continue;
        dist[u]=dist[v]+c;
        from[u]=from[v];
        pq.emplace(dist[u],u);
      }
    }
    vector<vector<E> > H(n);
    for(int v=0;v<(n<<1);v++){
      for(E e:G[v]){
        int u=e.first;
        T c=e.second;
        if(from[v]==from[u]) continue;
        int x=from[v],y=from[u];
        T z=dist[v]+dist[u]+c;
        H[x].emplace_back(y,z);
        H[y].emplace_back(x,z);
      }
    }
    return H;
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "kruskal.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed CF17FINAL_J(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  int n;
  cin>>n;
  vector<ll> x(n);
  for(int i=0;i<n;i++) cin>>x[i];
  VoronoiMST<ll> vo(x);
  for(int i=1;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    vo.add_edge(a,b,c);
  }
  auto G=vo.build();
  Kruskal<ll> ks(n);
  for(int v=0;v<n;v++){
    for(auto e:G[v]){
      int u=e.first;
      ll c=e.second;
      if(v<u) ks.add_edge(v,u,c);
    }
  }
  cout<<ks.build()<<endl;
  return 0;
}
/*
  verified on 2020/05/07
  https://atcoder.jp/contests/cf17-final/tasks/cf17_final_j
*/
signed main(){
  CF17FINAL_J();
  return 0;
}
#endif
