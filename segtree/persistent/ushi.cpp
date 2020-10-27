#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template <typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  F f;
  T ti;
  SegmentTree(F f,T ti):f(f),ti(ti){}

  struct Node{
    Node *l,*r;
    T dat;
    Node(T dat):dat(dat){l=r=nullptr;}
  };

  Node* clone(Node *a){
    return new Node(*a);
  }

  Node* reflect(Node *a){
    a->dat=f(a->l->dat,a->r->dat);
    return a;
  }

  int n,height;
  Node* build(const vector<T> &v){
    int n_=v.size();
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    vector<Node*> vs(n<<1);
    for(int i=0;i<n_;i++) vs[n+i]=new Node(v[i]);
    for(int i=n_;i<n;i++) vs[n+i]=new Node(ti);
    for(int i=n-1;i;i--){
      vs[i]=new Node(ti);
      vs[i]->l=vs[(i<<1)|0];
      vs[i]->r=vs[(i<<1)|1];
      reflect(vs[i]);
    }
    return vs[1];
  }

  Node* set_val(Node* t,int k,T x,int h){
    t=clone(t);
    if(h<0){
      t->dat=x;
      return t;
    }
    if((k>>h)&1) t->r=set_val(t->r,k,x,h-1);
    else t->l=set_val(t->l,k,x,h-1);
    return reflect(t);
  }

  T query(Node* t,int l,int r,int lb,int ub){
    if(r<=lb or ub<=l) return ti;
    if(l<=lb and ub<=r) return t->dat;
    int m=(lb+ub)>>1;
    return f(query(t->l,l,r,lb,m),query(t->r,l,r,m,ub));
  }

  Node* set_val(Node* t,int k,T x){
    return set_val(t,k,x,height-1);
  }

  T query(Node* t,int l,int r){
    return query(t,l,r,0,n);
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
