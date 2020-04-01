#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct Vertex{
  void* handle;
  int color;
  Vertex(int color=0):handle(nullptr),color(color){}
};

template<typename T>
struct SteinerTree{
  T con,len,lf,rg,md,chd,ans;
  SteinerTree(T len=0):con(0),len(len),lf(0),rg(0),md(0),chd(0),ans(0){}
  void toggle(){return swap(lf,rg);}
  static SteinerTree compress(SteinerTree x,Vertex* v,SteinerTree y){
    if(x.chd){
      if(!x.con){
        x.con=1;
        x.lf=x.len;
        x.rg=0;
        x.md=x.chd;
      }else{
        x.ans+=x.md+x.rg+x.chd;
        x.md=x.rg=x.chd=0;
      }
    }

    if(!x.con and !(v->color) and !y.con)
      return SteinerTree(x.len+y.len);

    SteinerTree nxt;
    nxt.con=1;
    nxt.lf=x.con?x.lf:(v->color?x.len:x.len+y.lf);
    nxt.rg=y.con?y.rg:(v->color?y.len:y.len+x.rg);
    nxt.ans=x.ans+y.ans;
    if(x.con and (v->color or y.con)){
      nxt.ans+=x.md+x.rg;
      x.md=0;
    }
    if(y.con and (v->color or x.con)){
      nxt.ans+=y.md+y.lf;
      y.md=0;
    }
    nxt.md=x.md+y.md;
    return nxt;
  }

  static SteinerTree rake(SteinerTree x,SteinerTree y){
    x.chd+=y.chd+y.rg+y.md;
    x.ans+=y.ans;
    return x;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
