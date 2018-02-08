#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T, typename E>
struct SkewHeap{
  typedef function<T(T, E)> F;
  typedef function<E(E, E)> G;
  typedef function<bool(T,T)> C;
  F f;
  G g;
  C c;
  E e;
  SkewHeap(F f,G g,C c,E e):f(f),g(g),c(c),e(e){}

  struct Node{
    Node *l,*r;
    T val;
    E add;
    Node(T val,E add):val(val),add(add){l=r=NULL;}
  };

  void eval(Node *a){
    if(a->add==e) return;
    if(a->l) a->l->add=g(a->l->add,a->add);
    if(a->r) a->r->add=g(a->r->add,a->add);
    a->val=f(a->val,a->add);
    a->add=e;
  }
  
  T top(Node *a){
    return f(a->val,a->add);
  }
  
  Node* push(T v){
    return new Node(v,e);
  }
  
  Node* meld(Node *a,Node *b){
    if(!a) return b;
    if(!b) return a;
    if(c(top(a),top(b))) swap(a,b);
    eval(a);
    a->r=meld(a->r,b);
    swap(a->l,a->r);
    return a;
  }
  
  Node* pop(Node* a){
    eval(a);
    auto res=meld(a->l,a->r);
    free(a);
    return res;
  }
  
};
//END CUT HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using Heap=SkewHeap<int, int>;
  Heap::F f=[](int a,int b){return a+b;};
  Heap::G g=[](int a,int b){return a+b;};
  Heap::C c=[](int a,int b){return a<b;};

  Heap heap(f,g,c,0);
  auto base=heap.push(0);
  
  string s;
  while(cin>>s,s!="end"){
    int x;
    if(s=="insert"){
      cin>>x;
      base=heap.meld(base,heap.push(x));
    }
    if(s=="extract"){
      x=heap.top(base);
      base=heap.pop(base);
      cout<<x<<endl;
    }
  }
  return 0;
}
/*
  verified on 2018/02/08
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C&lang=jp
*/
