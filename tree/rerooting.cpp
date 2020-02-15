#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Data, typename T>
struct ReRooting{
  struct Node{
    int to,rev;
    Data data;
    Node(int to,int rev,Data data):to(to),rev(rev),data(data){}
  };

  using F1 = function<T(T, T)>;
  using F2 = function<T(T, Data)>;

  vector<vector<Node> > G;
  vector<vector<T> > ld,rd;
  vector<int> lp,rp;

  const F1 f1;
  const F2 f2;
  const T id;

  ReRooting(int n,const F1 f1,const F2 f2,const T id):
    G(n),ld(n),rd(n),lp(n),rp(n),f1(f1),f2(f2),id(id){}

  void add_edge(int u,int v,Data d){
    G[u].emplace_back(v,(int)G[v].size(),d);
    G[v].emplace_back(u,(int)G[u].size()-1,d);
  }

  // p: idx for edge (not vertex)
  T dfs(int v,int p){
    while(lp[v]!=p&&lp[v]<(int)G[v].size()){
      auto &e=G[v][lp[v]];
      ld[v][lp[v]+1]=f1(ld[v][lp[v]],f2(dfs(e.to,e.rev),e.data));
      lp[v]++;
    }
    while(rp[v]!=p&&rp[v]>=0){
      auto &e=G[v][rp[v]];
      rd[v][rp[v]]=f1(rd[v][rp[v]+1],f2(dfs(e.to,e.rev),e.data));
      rp[v]--;
    }
    if(p<0) return rd[v][0];
    return f1(ld[v][p],rd[v][p+1]);
  }

  vector<T> build(){
    for(int i=0;i<(int)G.size();i++){
      ld[i].assign((int)G[i].size()+1,id);
      rd[i].assign((int)G[i].size()+1,id);
      lp[i]=0;
      rp[i]=(int)G[i].size()-1;
    }
    vector<T> res;
    for(int i=0;i<(int)G.size();i++){
      res.emplace_back(dfs(i,-1));
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE

// verify non-invertible
signed DP_V(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,m;
  cin>>n>>m;
  auto f1=[m](int a,int b)->int{return (long long)a*b%m;};
  auto f2=[m](int a,int d)->int{return (a+d)%m;};
  ReRooting<int, int> G(n,f1,f2,1);
  for(int i=1;i<n;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    G.add_edge(x,y,1);
  }
  auto ans=G.build();
  for(int x:ans) cout<<x<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/30
  https://atcoder.jp/contests/dp/tasks/dp_v
*/

signed main(){
  //DP_V();
  return 0;
}
#endif
