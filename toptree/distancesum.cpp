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
  // 0: dead, 1: alive
  int color;
  Vertex(int color=0):handle(nullptr),color(color){}
};

template<typename T>
struct DistanceSum{
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

  DistanceSum(T len=0):len(len),cnt(0),chd(0),ans(0),sum_l(0),sum_r(0){}

  void toggle(){swap(sum_l,sum_r);}

  static DistanceSum compress(
    const DistanceSum& x,Vertex *v,const DistanceSum& y){
    DistanceSum nxt;
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

  static DistanceSum rake(const DistanceSum& x,const DistanceSum& y){
    DistanceSum nxt;
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

template<typename T, size_t N>
Vertex* centroid(TopTree<Vertex, DistanceSum<T>, N> &G, Vertex* v){
  using TT = typename remove_reference<decltype(G)>::type;
  using Node = typename TT::Node;
  using Type = typename TT::Type;

  Node* rt=G.expose(v);
  if(rt->type==Type::Edge) return v;

  Node* cc=rt;
  Vertex* ctr=nullptr;

  T lv=0,rv=0,sum=rt->dat.cnt;
  while(cc->type==Type::Compress){
    G.propagate(cc);

    Node* ll=cc->ch[0];
    if((ll->dat.cnt+lv)*2>sum){
      assert(ll->type!=Type::Edge);
      rv+=cc->dat.md.cnt-ll->dat.cnt;
      cc=ll;
      continue;
    }

    Node* rr=cc->ch[1];
    if((rr->dat.cnt+rv)*2>sum){
      assert(rr->type!=Type::Edge);
      lv+=cc->dat.md.cnt-rr->dat.cnt;
      cc=rr;
      continue;
    }

    Node* mm=cc->q;
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

//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
