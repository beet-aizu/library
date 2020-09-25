// verification-helper: PROBLEM https://yukicoder.me/problems/4706

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../toptree/toptree.cpp"
#undef call_from_test

struct Vertex{
  void* handle;
  Vertex():handle(nullptr){}
};

using ll = long long;
const ll INF = 1e9 + 10;
struct Cluster{
  ll len;
  ll lft,rgh,mid,ans;
  Cluster(ll len=INF):len(len),lft(len),rgh(len),mid(INF),ans(INF){}
  void toggle(){
    swap(lft,rgh);
  }
  static Cluster compress(Cluster x,Vertex *,Cluster y){
    Cluster nxt(x.len+y.len);
    nxt.lft=y.lft;
    nxt.rgh=x.rgh;
    nxt.ans=min({x.ans,y.ans,x.mid});
    return nxt;
  }
  static Cluster rake(Cluster x,Cluster y){
    x.mid=min({x.mid,y.mid,y.lft});
    return x;
  }
};


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  const size_t LIM = 1e6;
  TopTree<Vertex, Cluster, LIM> T;

  int n;
  cin>>n;

  vector<Vertex*> vs(n);
  for(int i=0;i<n;i++) vs[i]=T.create();

  for(int i=1;i<n;i++){
    int u,v,w;
    cin>>u>>v>>w;
    u--;v--;
    T.link(vs[u],Cluster(w),vs[v]);
  }

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    auto res=T.get_path(vs[x],vs[y]);
    ll ans=res.ans;

    chmin(ans,T.get_subtree(vs[x],vs[y]).lft);
    chmin(ans,T.get_subtree(vs[x],vs[y]).mid);
    chmin(ans,T.get_subtree(vs[y],vs[x]).lft);
    chmin(ans,T.get_subtree(vs[y],vs[x]).mid);

    if(ans==INF) cout<<-1<<newl;
    else cout<<res.len+2*ans<<newl;
  }
  return 0;
}
