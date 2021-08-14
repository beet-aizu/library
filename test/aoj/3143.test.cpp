// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3143

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../toptree/toptree.cpp"
#include "../../toptree/farthest.cpp"
#undef call_from_test

const int MAX = 2e5+100;
Vertex* vs[MAX];
int as[MAX],bs[MAX],ds[MAX];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  const size_t N = MAX;
  using Cluster = Farthest<long long>;
  TopTree<Vertex, Cluster, N> G;

  int n;
  cin>>n;

  for(int i=0;i<n;i++) vs[i]=G.create();

  for(int i=1;i<n;i++){
    cin>>as[i]>>bs[i]>>ds[i];
    as[i]--;bs[i]--;
    G.link(vs[as[i]],Cluster(ds[i],as[i],bs[i]),vs[bs[i]]);
  }

  auto cut=[&](int k)->void{
    G.cut(vs[as[k]],vs[bs[k]]);
  };
  auto link=[&](int k)->void{
    G.link(vs[as[k]],Cluster(ds[k],as[k],bs[k]),vs[bs[k]]);
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
      cut(y);
    }
    if(t==3){
      int z;
      cin>>z;
      link(z);
    }

    auto fs=get_all_farthests(G,vs[cur]);
    if(fs.empty()){
      cout<<1<<" "<<cur+1<<newl;
      continue;
    }

    sort(fs.begin(),fs.end());
    cout<<fs.size();
    for(int f:fs) cout<<" "<<f+1;
    cout<<newl;

    // amortization
    for(int f:fs) G.expose(vs[f]);
  }
  return 0;
}
