#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T, typename E>
struct SkewHeap{
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  using C = function<bool(T,T)>;
  G g;
  H h;
  C c;
  T INF;
  E ei;
  SkewHeap(G g,H h,C c,T INF,E ei):g(g),h(h),c(c),INF(INF),ei(ei){}

  struct Node{
    Node *l,*r;
    T val;
    E add;
    Node(T val,E add):val(val),add(add){l=r=nullptr;}
  };

  void eval(Node *a){
    if(a==nullptr) return;
    if(a->add==ei) return;
    if(a->l) a->l->add=h(a->l->add,a->add);
    if(a->r) a->r->add=h(a->r->add,a->add);
    a->val=g(a->val,a->add);
    a->add=ei;
  }

  T top(Node *a){
    return a!=nullptr?g(a->val,a->add):INF;
  }

  T snd(Node *a){
    eval(a);
    return a!=nullptr?min(top(a->l),top(a->r)):INF;
  }

  Node* add(Node *a,E d){
    if(a!=nullptr) a->add=h(a->add,d);
    return a;
  }

  Node* push(T v){
    return new Node(v,ei);
  }

  Node* meld(Node *a,Node *b){
    if(a==nullptr) return b;
    if(b==nullptr) return a;
    if(c(top(a),top(b))) swap(a,b);
    eval(a);
    a->r=meld(a->r,b);
    swap(a->l,a->r);
    return a;
  }

  Node* pop(Node* a){
    eval(a);
    auto res=meld(a->l,a->r);
    delete a;
    return res;
  }

};
#endif
//BEGIN CUT HERE
template<typename T>
T optimalbinarytree(vector<T> ws){
  const T INF = numeric_limits<T>::max()/2;
  using Heap=SkewHeap<T, T>;

  auto g=[](T a,T b){return a+b;};
  auto c=[](T a,T b){return a>b;};
  Heap heap(g,g,c,INF,0);

  int n=ws.size();
  vector<typename Heap::Node* > hs(n-1,nullptr);
  vector<int> ls(n),rs(n);
  vector<T> cs(n-1);

  using P = pair<T, int>;
  priority_queue<P,vector<P>,greater<P> > pq;
  for(int i=0;i<n-1;i++){
    ls[i]=i-1;
    rs[i]=i+1;
    cs[i]=ws[i]+ws[i+1];
    pq.emplace(cs[i],i);
  }

  T res=0;
  for(int k=0;k<n-1;k++){
    T c;
    int i;
    do{
      tie(c,i)=pq.top();pq.pop();
    }while(rs[i]<0||cs[i]!=c);

    bool ml=false,mr=false;
    if(ws[i]+heap.top(hs[i])==c){
      hs[i]=heap.pop(hs[i]);
      ml=true;
    }else if(ws[i]+ws[rs[i]]==c){
      ml=mr=true;
    }else if(heap.top(hs[i])+heap.snd(hs[i])==c){
      hs[i]=heap.pop(heap.pop(hs[i]));
    }else{
      hs[i]=heap.pop(hs[i]);
      mr=true;
    }

    res+=c;
    hs[i]=heap.meld(hs[i],heap.push(c));

    if(ml) ws[i]=INF;
    if(mr) ws[rs[i]]=INF;

    if(ml&&i>0){
      int j=ls[i];
      hs[j]=heap.meld(hs[j],hs[i]);
      rs[j]=rs[i];
      rs[i]=-1;
      ls[rs[j]]=j;
      i=j;
    }

    if(mr&&rs[i]+1<n){
      int j=rs[i];
      hs[i]=heap.meld(hs[i],hs[j]);
      rs[i]=rs[j];
      rs[j]=-1;
      ls[rs[i]]=i;
    }

    cs[i]=min({ws[i]+ws[rs[i]],INF,
               min(ws[i],ws[rs[i]])+heap.top(hs[i]),
               heap.top(hs[i])+heap.snd(hs[i])});
    pq.emplace(cs[i],i);
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
