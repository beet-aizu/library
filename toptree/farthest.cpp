#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "toptree.cpp"
#undef call_from_test

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
  Farthest():lf(0,-1),rg(0,-1),len(0){}
  Farthest(T d,int f,int t):lf(d,t),rg(d,f),len(d){}
  Farthest(pi md,pi lf,pi rg,T len):md(md),lf(lf),rg(rg),len(len){}
  void toggle(){swap(lf,rg);}
  static Farthest compress(Farthest &x,Vertex*,Farthest &y){
    return Farthest(
      max(x.rg,y.lf),
      max(x.lf,y.lf+x.len),
      max(y.rg,x.rg+y.len),
      x.len+y.len);
  }
  static Farthest rake(Farthest &x,Farthest &y){
    return Farthest(pi(),max(x.lf,y.rg+x.len),max(x.rg,y.rg),x.len);
  }
};

template<typename T, size_t N>
vector<int> get_all_farthests(TopTree<Vertex, Farthest<T>, N> &G,Vertex* v){
  using TT = typename remove_reference<decltype(G)>::type;
  using Node = typename TT::Node;
  using Type = typename TT::Type;
  vector<int> fs;
  auto dist=G.get_subtree(v).md.dist;
  if(dist==T(0)) return {};
  auto dfs=[&](auto dfs,Node* rt,T d,bool left)->void{
    if(!rt) return;
    G.propagate(rt);

    auto cur=left?(rt->dat.lf):(rt->dat.rg);
    if(d+cur.dist!=dist) return;

    if(rt->type==Type::Edge){
      if(~cur.idx) fs.emplace_back(cur.idx);
      return;
    }
    if(rt->type==Type::Rake){
      assert(!left);
      dfs(dfs,rt->ch[0],d,false);
      dfs(dfs,rt->ch[1],d,false);
      return;
    }
    if(rt->type==Type::Compress){
      T mid=rt->ch[left?0:1]->dat.len;
      dfs(dfs,rt->ch[left?0:1],d,left);
      dfs(dfs,rt->ch[left?1:0],d+mid,left);
      dfs(dfs,rt->q,d+mid,false);
      return;
    }
    abort();
  };
  auto rt=G.expose(v);
  assert(rt->type==Type::Compress);
  dfs(dfs,rt->ch[0],T(0),false);
  dfs(dfs,rt->ch[1],T(0),true);
  dfs(dfs,rt->q,T(0),false);
  return fs;
}

//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
