#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
template<typename TF,typename TC>
struct PrimalDual{
  struct edge{
    int to;
    TF cap;
    TC cost;
    int rev;
    edge(){}
    edge(int to,TF cap,TC cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
  };

  static const TC INF;
  vector<vector<edge>> G;
  vector<TC> h,dist;
  vector<int> prevv,preve;

  PrimalDual(){}
  PrimalDual(int n):G(n),h(n),dist(n),prevv(n),preve(n){}

  void add_edge(int u,int v,TF cap,TC cost){
    G[u].emplace_back(v,cap,cost,G[v].size());
    G[v].emplace_back(u,0,-cost,G[u].size()-1);
  }

  void dijkstra(int s){
    struct P{
      TC first;
      int second;
      P(TC first,int second):first(first),second(second){}
      bool operator<(const P&a) const{return a.first<first;}
    };
    priority_queue<P> que;
    fill(dist.begin(),dist.end(),INF);

    dist[s]=0;
    que.emplace(dist[s],s);
    while(!que.empty()){
      P p=que.top();que.pop();
      int v=p.second;
      if(dist[v]<p.first) continue;
      for(int i=0;i<(int)G[v].size();i++){
        edge &e=G[v][i];
        if(e.cap==0) continue;
        if(dist[v]+e.cost+h[v]-h[e.to]<dist[e.to]){
          dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
          prevv[e.to]=v;
          preve[e.to]=i;
          que.emplace(dist[e.to],e.to);
        }
      }
    }
  }

  TC flow(int s,int t,TF f,int &ok){
    TC res=0;
    fill(h.begin(),h.end(),0);
    while(f>0){
      dijkstra(s);
      if(dist[t]==INF){
        ok=0;
        return res;
      }

      for(int v=0;v<(int)h.size();v++)
        if(dist[v]<INF) h[v]=h[v]+dist[v];

      TF d=f;
      for(int v=t;v!=s;v=prevv[v])
        d=min(d,G[prevv[v]][preve[v]].cap);

      f-=d;
      res=res+h[t]*d;
      for(int v=t;v!=s;v=prevv[v]){
        edge &e=G[prevv[v]][preve[v]];
        e.cap-=d;
        G[v][e.rev].cap+=d;
      }
    }
    ok=1;
    return res;
  }
};
template<typename TF, typename TC> const TC PrimalDual<TF, TC>::INF = numeric_limits<TC>::max()/2;
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed SPOJ_GREED(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  auto solve=
    [](){
      int n;
      cin>>n;
      vector<int> cnt(n,0);
      for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x-1]++;
      }
      using ll = long long;
      const ll INF = 1<<28;
      int S=n,T=n+1;
      PrimalDual<ll, ll> G(n+2);

      int m;
      cin>>m;
      for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        G.add_edge(x,y,INF,1);
        G.add_edge(y,x,INF,1);
      }

      for(int i=0;i<n;i++){
        G.add_edge(S,i,cnt[i],0);
        G.add_edge(i,T,1,0);
      }

      int ok=0;
      ll res=G.flow(S,T,n,ok);
      assert(ok);
      cout<<res<<endl;
      return 0;

    };
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}
/*
  verified on 2019/07/05
  https://www.spoj.com/problems/GREED/
*/

signed geocon2013_B(){
  using D = double;

  int n;
  cin>>n;
  vector<D> xs(n),ys(n);
  for(int i=0;i<n;i++) cin>>xs[i]>>ys[i];

  vector<int> pos,neg;
  for(int i=0;i<n;i++){
    if(xs[i]>0) pos.emplace_back(i);
    if(xs[i]<0) neg.emplace_back(i);
  }

  int f=max(pos.size(),neg.size());
  if(f==0){
    cout<<0<<endl;
    return 0;
  }

  PrimalDual<int, D> G(n+3);
  int S=n,T=n+1,U=n+2;
  for(int z:pos) G.add_edge(S,z,1,0);
  for(int z:neg) G.add_edge(z,T,1,0);

  int dif=pos.size()-neg.size();
  if(dif>0){
    G.add_edge(U,T,dif,0);
    for(int p:pos)
      G.add_edge(p,U,1,abs(xs[p]));
  }
  if(dif<0){
    G.add_edge(S,U,-dif,0);
    for(int q:neg)
      G.add_edge(U,q,1,abs(xs[q]));
  }

  for(int p:pos)
    for(int q:neg)
      G.add_edge(p,q,1,
                 min(hypot(xs[p]+xs[q],ys[p]-ys[q]),abs(xs[p])+abs(xs[q])));

  int ok=0;
  D ans=G.flow(S,T,f,ok);
  assert(ok);
  cout<<fixed<<setprecision(12)<<ans<<endl;
  return 0;
}
/*
  verified on 2019/07/05
  https://atcoder.jp/contests/geocon2013/tasks/geocon2013_b
*/
signed main(){
  //SPOJ_GREED();
  //geocon2013_B();
  return 0;
}
#endif
