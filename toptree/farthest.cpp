#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#endif
//BEGIN CUT HERE
struct Vertex{
  void* handle;
  int idx;
  Vertex(int idx=-1):handle(nullptr),idx(idx){}
};

template<typename T>
struct Farthest{
  struct pi{
    T dist;
    int idx;
    pi():dist(0),idx(-1){}
    pi(T dist,int idx):dist(dist),idx(idx){}
    bool operator<(const pi &o)const{return dist<o.dist;}
    pi operator+(const T e)const{return pi(dist+e,idx);}
  };
  pi md,lf,rg;
  T len;
  Farthest(){}
  Farthest(T d,int f,int t):lf(d,t),rg(d,f),len(d){}
  Farthest(pi md,pi lf,pi rg,T len):
    md(md),lf(lf),rg(rg),len(len){}
  void toggle(){swap(lf,rg);}
  static Farthest compress(Farthest &x,Vertex*,Farthest &y){
    return Farthest(
      max(x.rg,y.lf),
      max(x.lf,y.lf+x.len),
      max(y.rg,x.rg+y.len),
      x.len+y.len);
  }
  static Farthest rake(Farthest &x,Farthest &y,Vertex*){
    return Farthest(pi(),max(x.lf,y.rg+x.len),max(x.rg,y.rg),x.len);
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "toptree.cpp"
#undef call_from_test

//INSERT ABOVE HERE
const int MAX = 2e5 + 100;
Vertex* vs[MAX];
int as[MAX],bs[MAX],ds[MAX],ans[MAX],idx[MAX]={};

signed KUPC2020_G(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  const size_t LIM = 1.8e6;
  using Cluster = Farthest<long long>;
  TopTree<Vertex, Cluster, LIM> G(Cluster(0,-1,-1));

  int n;
  cin>>n;

  for(int i=0;i<n;i++)
    vs[i]=G.create(Vertex(i));

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

    auto dist=G.expose(vs[cur])->dat.md.dist;
    if(dist==0){
      cout<<1<<" "<<cur+1<<newl;
      continue;
    }

    int num=0;
    while(1){
      auto res=G.expose(vs[cur])->dat.md;
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

signed main(){
  KUPC2020_G();
  return 0;
}
#endif
