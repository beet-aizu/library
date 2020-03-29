#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3143"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../toptree/farthest.cpp"
#include "../../toptree/toptree.cpp"
#undef call_from_test

const int MAX = 2e5 + 100;
Vertex* vs[MAX];
int as[MAX],bs[MAX],ds[MAX],ans[MAX],idx[MAX]={};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  const size_t LIM = 1e6;
  using Cluster = Farthest<long long>;
  TopTree<Vertex, Cluster, LIM> G(Cluster(0,-1,-1));

  int n;
  cin>>n;

  for(int i=0;i<n;i++) vs[i]=G.create();

  for(int i=1;i<n;i++){
    cin>>as[i]>>bs[i]>>ds[i];
    as[i]--;bs[i]--;
    idx[as[i]]+=i;
    idx[bs[i]]+=i;
    G.link(vs[as[i]],Cluster(ds[i],as[i],bs[i]),vs[bs[i]]);
  }

  const long long INF = 1e12;
  auto cut=[&](int k)->void{
    G.set_edge(vs[as[k]],vs[bs[k]],Cluster(-INF,as[k],bs[k]));
  };
  auto link=[&](int k)->void{
    G.set_edge(vs[as[k]],vs[bs[k]],Cluster(ds[k],as[k],bs[k]));
  };

  int q;
  cin>>q;

  int cur=0;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;

    if(t==1){
      int x;
      cin>>x;
      x--;
      cur=x;
    }
    if(t==2){
      int y;
      cin>>y;
      idx[as[y]]-=y;
      idx[bs[y]]-=y;
      cut(y);
    }
    if(t==3){
      int z;
      cin>>z;
      idx[as[z]]+=z;
      idx[bs[z]]+=z;
      link(z);
    }

    auto dist=G.get_subtree(vs[cur]).md.dist;
    if(dist==0){
      cout<<1<<" "<<cur+1<<newl;
      continue;
    }

    int num=0;
    while(1){
      auto res=G.get_subtree(vs[cur]).md;
      if(dist!=res.dist) break;
      ans[num++]=res.idx;
      cut(idx[res.idx]);
    }

    sort(ans,ans+num);
    cout<<num;
    for(int i=0;i<num;i++) cout<<" "<<ans[i]+1;
    cout<<newl;

    for(int i=0;i<num;i++) link(idx[ans[i]]);
  }
  return 0;
}
