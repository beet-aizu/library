#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#endif
//BEGIN CUT HERE
struct Vertex{
  void* handle;
  Vertex():handle(nullptr){}
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
signed TKPPC2015_J(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  const size_t LIM = 1.8e6;
  using Cluster = Farthest<long long>;
  TopTree<Vertex, Cluster, LIM> G(Cluster(0,-1,-1));

  const int MAX = 5e5 + 100;
  vector<Vertex*> vs(MAX);
  int num=0;
  vs[num]=G.create(Vertex());
  num++;

  vector<int> ps(MAX);

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t,a,c;
    cin>>t>>a>>c;

    if(t==1){
      vs[num]=G.create(Vertex());
      ps[num]=a;
      G.link(vs[num],Cluster(c,num,ps[num]),vs[ps[num]]);
      num++;
    }

    if(t==2)
      G.set_edge(vs[a],vs[ps[a]],Cluster(c,a,ps[a]));

    if(t==3)
      cout<<G.expose(vs[a])->dat.md.dist<<newl;
  }

  return 0;
}

signed main(){
  KUPC2020_G();
  //TKPPC2015_J();
  return 0;
}
#endif
