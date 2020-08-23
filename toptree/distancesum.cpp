#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "toptree.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE

template<typename T, size_t LIM>
struct DistanceSum{
  struct Vertex{
    void* handle;
    T color;
    Vertex(T color=0):handle(nullptr),color(color){}
  };

  struct Cluster{
    struct pi{
      T cnt;
      Vertex* ptr;
      pi():cnt(-1),ptr(nullptr){}
      pi(T cnt,Vertex* ptr):cnt(cnt),ptr(ptr){}
      bool operator<(const pi &o)const{return cnt<o.cnt;}
    };

    T len,cnt,chd,ans;
    T sum_l,sum_r;
    pi md;

    Cluster(T len=0):len(len),cnt(0),chd(0),ans(0),sum_l(0),sum_r(0){}

    void toggle(){swap(sum_l,sum_r);}

    static Cluster compress(Cluster x,Vertex *v,Cluster y){
      Cluster nxt;
      nxt.len=x.len+y.len;
      nxt.cnt=x.cnt+x.chd+(v->color)+y.cnt;
      nxt.chd=0;
      assert(y.chd==0);

      nxt.ans=x.sum_l+y.sum_r;

      nxt.sum_l+=x.sum_l;
      nxt.sum_l+=y.sum_l;
      nxt.sum_l+=(x.cnt+x.chd+(v->color))*y.len;

      nxt.sum_r+=x.sum_r;
      nxt.sum_r+=y.sum_r;
      nxt.sum_r+=(x.chd+(v->color)+y.cnt)*x.len;

      nxt.md=pi(nxt.cnt,v);

      return nxt;
    }

    static Cluster rake(Cluster x,Cluster y){
      Cluster nxt;
      nxt.len=x.len;
      nxt.cnt=x.cnt;
      nxt.chd=x.chd+y.cnt+y.chd;

      nxt.ans=x.sum_l+y.sum_l;

      nxt.sum_l+=x.sum_l;
      nxt.sum_l+=y.sum_l;

      nxt.sum_r+=x.sum_r;
      nxt.sum_r+=y.sum_l;

      nxt.md=max(x.md,y.md);

      return nxt;
    }
  };

  TopTree<Vertex, Cluster, LIM> G;
  using Type = typename decltype(G)::Type;

  Vertex* centroid(Vertex* v){
    auto rt=G.expose(v);
    if(rt->type==Type::Edge) return v;

    auto cc=rt;
    Vertex* ctr=nullptr;

    T lv=0,rv=0,sum=rt->dat.cnt;
    while(cc->type==Type::Compress){
      G.propagate(cc);

      auto ll=cc->ch[0];
      if((ll->dat.cnt+lv)*2>sum){
        assert(ll->type!=Type::Edge);
        rv+=cc->dat.md.cnt-ll->dat.cnt;
        cc=ll;
        continue;
      }

      auto rr=cc->ch[1];
      if((rr->dat.cnt+rv)*2>sum){
        assert(rr->type!=Type::Edge);
        lv+=cc->dat.md.cnt-rr->dat.cnt;
        cc=rr;
        continue;
      }

      auto mm=cc->q;
      if(mm and mm->dat.md.cnt*2>sum){
        assert(mm->type!=Type::Edge);
        rv+=lv;lv=0;
        rv+=cc->dat.md.cnt-mm->dat.md.cnt;
        cc=(decltype(cc))mm->dat.md.ptr->handle;
        continue;
      }

      ctr=cc->dat.md.ptr;
      break;
    }
    return ctr;
  }
  Vertex* create(T color){return G.create(Vertex(color));}
  void link(Vertex* u,Cluster w,Vertex* v){G.link(u,Cluster(w),v);}
  void cut(Vertex* u,Vertex* v){G.cut(u,v);}
  void set_vertex(Vertex* u,T color){G.set_vertex(u,Vertex(color));}
  T query(Vertex* v){return G.get_subtree(v).ans;}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
