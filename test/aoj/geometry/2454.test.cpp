#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2454"
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

#define ERROR "1e-6"

// segmentArrangement
signed main(){
  int n,m;
  cin>>n>>m;
  vector<Segment> ss(n);
  Polygon ps(m);
  for(int i=0;i<n;i++) cin>>ss[i];
  for(int i=0;i<m;i++) cin>>ps[i];
  map<Point, int> mp;
  for(int i=0;i<m;i++) mp[ps[i]]=i;
  Point s,g;
  cin>>s>>g;
  ps.emplace_back(s);
  ps.emplace_back(g);

  auto H=segmentArrangement(ss,ps);
  vector< vector< pair<int, double> > > G(H.size());
  for(int i=0;i<(int)H.size();i++)
    for(int j:H[i]) G[i].emplace_back(j,abs(ps[i]-ps[j]));

  double ans=0,tmp=0;
  for(int i=0;i<n;i++) ans+=abs(ss[i].p1-ss[i].p2);

  vector<int> used(G.size(),0);
  queue<int> q;
  for(int i=0;i<(int)G.size();i++)
    if(ps[i]==g) {used[i]=1;q.emplace(i);}

  while(!q.empty()){
    int v=q.front();q.pop();
    if(ps[v]==s){
      cout<<(int)-1<<endl;
      return 0;
    }
    if(mp.count(ps[v])) continue;
    for(int u:H[v]){
      if(!used[u]){
        used[u]=1;
        q.emplace(u);
      }
    }
  }

  for(int i=0;i<(int)G.size();i++)
    if(ps[i]==s) q.emplace(i);

  while(!q.empty()){
    int v=q.front();q.pop();
    for(auto &e:G[v]){
      int u=e.first;
      double &c=e.second;
      if(used[v]&&used[u]) continue;
      if(c==0) continue;
      tmp+=c;c=0;
      q.emplace(u);
    }
  }
  tmp/=2;

  cout<<fixed<<setprecision(12)<<ans-tmp<<endl;
  return 0;
}
