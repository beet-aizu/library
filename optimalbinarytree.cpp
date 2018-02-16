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
  T INF;
  E e;
  SkewHeap(F f,G g,C c,T INF,E e):f(f),g(g),c(c),INF(INF),e(e){}
  
  struct Node{
    Node *l,*r;
    T val;
    E add;
    Node(T val,E add):val(val),add(add){l=r=nullptr;}
  };

  void eval(Node *a){
    if(a==nullptr) return;
    if(a->add==e) return;
    if(a->l) a->l->add=g(a->l->add,a->add);
    if(a->r) a->r->add=g(a->r->add,a->add);
    a->val=f(a->val,a->add);
    a->add=e;
  }
  
  T top(Node *a){
    return a!=nullptr?f(a->val,a->add):INF;
  }

  T snd(Node *a){
    eval(a);
    return a!=nullptr?min(top(a->l),top(a->r)):INF;
  }

  Node* add(Node *a,E d){
    if(a!=nullptr) a->add=g(a->add,d);
    return a;
  }
  
  Node* push(T v){
    return new Node(v,e);
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

template<typename T>
T optimalbinarytree(vector<T> s,T INF){
  using Heap=SkewHeap<T,T>;
  
  typename Heap::F f=[](T a,T b){return a+b;};
  typename Heap::G g=[](T a,T b){return a+b;};
  typename Heap::C c=[](T a,T b){return a>b;};
  Heap heap(f,g,c,INF,0);
  
  int n=s.size();
  vector<typename Heap::Node* > hs(n-1,nullptr);
  vector<int> ls(n),rs(n);
  vector<T> cs(n-1);
  
  using P = pair<T, int>;
  priority_queue<P,vector<P>,greater<P> > pq;
  for(int i=0;i<n-1;i++){
    ls[i]=i-1;
    rs[i]=i+1;
    cs[i]=s[i]+s[i+1];
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
    if(s[i]+heap.top(hs[i])==c){
      hs[i]=heap.pop(hs[i]);
      ml=true;
    }else if(s[i]+s[rs[i]]==c){
      ml=mr=true;
    }else if(heap.top(hs[i])+heap.snd(hs[i])==c){
      hs[i]=heap.pop(heap.pop(hs[i]));
    }else{
      hs[i]=heap.pop(hs[i]);
      mr=true;
    }

    res+=c;
    hs[i]=heap.meld(hs[i],heap.push(c));

    if(ml) s[i]=INF;
    if(mr) s[rs[i]]=INF;

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

    cs[i]=min({s[i]+s[rs[i]],
	  min(s[i],s[rs[i]])+heap.top(hs[i]),
	  heap.top(hs[i])+heap.snd(hs[i])});

    pq.emplace(cs[i],i);
  }
  return res;
}
//END CUT HERE

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> s(n);
  for(Int i=0;i<n;i++) cin>>s[i];
  const Int INF = 1e16;
  cout<<optimalbinarytree(s,INF)<<endl;
  return 0;
}

/*
  verified on 2018/02/16
  https://beta.atcoder.jp/contests/atc002/tasks/atc002_c
*/
