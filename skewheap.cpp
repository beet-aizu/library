#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T, typename E>
struct FGC{
  typedef function<T(T, E)> F;
  typedef function<E(E, E)> G;
  typedef function<bool(T,T)> C;
  F &f;
  G &g;
  C &c;
  FGC(F &f,G &g,C &c):f(f),g(g),c(c){}
};
template<typename T, typename E>
struct SkewHeap{
  SkewHeap *l,*r;
  T val;
  E add,e;
  FGC<T, E> &fgc;
  
  SkewHeap(T val,E e,FGC<T,E> &fgc):
    val(val),add(e),e(e),fgc(fgc){l=r=NULL;}
  
  void eval(){
    if(add==e) return;
    if(l) l->add=fgc.g(l->add,add);
    if(r) r->add=fgc.g(r->add,add);
    val=fgc.f(val,add);
    add=e;
  }
  
  T top(){
    return fgc.f(val,add);
  }
  
};

template<typename T, typename E>
SkewHeap<T, E>* meld(SkewHeap<T, E> *a,SkewHeap<T, E> *b){
  if(!a) return b;
  if(!b) return a;
  if(a->fgc.c(a->top(),b->top()))  swap(a,b);
  a->eval();
  a->r=meld(a->r,b);
  swap(a->l,a->r);
  return a;
}

template<typename T, typename E>
SkewHeap<T, E>* pop(SkewHeap<T, E>* a){
  a->eval();
  auto res=meld(a->l,a->r);
  free(a);
  return res;
};
//END CUT HERE

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using Heap = SkewHeap<int, int>;
  
  FGC<int, int>::F f=[](int a,int b){return a+b;};
  FGC<int, int>::G g=[](int a,int b){return a+b;};
  FGC<int, int>::C c=[](int a,int b){return a<b;};
  FGC<int, int> fgc(f,g,c);
  
  Heap* base = new Heap(0,0,fgc);
  string s;
  while(cin>>s,s!="end"){
    int x;
    if(s=="insert"){
      cin>>x;
      base=meld(base, new Heap(x,0,fgc));
    }
    if(s=="extract"){
      x=base->top();
      base=pop(base);
      cout<<x<<endl;
    }
  }
  return 0;
}
/*
  verified on 2018/01/04
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C&lang=jp
*/
