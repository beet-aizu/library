#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../toptree/toptree.cpp"
#undef call_from_test

struct Vertex{
  void* handle;
  int idx;
  Vertex(int idx=-1):handle(nullptr),idx(idx){}
};

struct Cluster{
  int ans,lf,rg,len;
  Cluster(){}
  Cluster(int l):ans(l),lf(l),rg(l),len(l){}
  Cluster(int ans,int lf,int rg,int len):
    ans(ans),lf(lf),rg(rg),len(len){}
  void toggle(){swap(lf,rg);}
  static Cluster compress(Cluster x,Vertex*,Cluster y){
    return Cluster(
      max(x.rg,y.lf),
      max(x.lf,x.len+y.lf),
      max(y.rg,y.len+x.rg),
      x.len+y.len);
  }
  static Cluster rake(Cluster x,Cluster y,Vertex*){
    return Cluster(0,max(x.lf,x.len+y.rg),max(x.rg,y.rg),x.len);
  }
};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  const size_t LIM = 1e6;
  TopTree<Vertex, Cluster, LIM> T(Cluster(0));

  int n;
  cin>>n;

  vector<Vertex*> vs(n);
  for(int i=0;i<n;i++) vs[i]=T.create(Vertex(i));

  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    T.link(vs[u],Cluster(1),vs[v]);
  }

  for(int i=0;i<n;i++)
    cout<<(n-1)*2-T.get_subtree(vs[i]).ans<<newl;

  return 0;
}
