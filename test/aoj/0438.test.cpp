// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0438

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../bbst/rbst/basic/base.cpp"
#include "../../bbst/rbst/basic/array.cpp"
#undef call_from_test

struct T;
using Node = NodeBase<T>;

struct T{
  Node* nxt;
  char c;
  T():nxt(nullptr){}
  T(Node* nxt,char c):nxt(nxt),c(c){}
};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  auto cs=read<char>(n);

  vector<vector<int>> G(n);
  for(int i=0;i+1<n;i++)
    G[i].emplace_back(i+1);

  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    G[u].emplace_back(v);
  }

  const size_t LIM = 1e6;
  Array<Node, LIM> H;
  vector<Node*> ps(n,nullptr);
  ps[n-1]=H.create(Node(T(nullptr,cs[n-1])));
  auto R=ps[n-1];

  for(int i=n-2;i>=0;i--){
    auto nxt=ps[i+1];

    auto comp1=[&](Node* a,Node* b){
      return H.order_of_key(a)<H.order_of_key(b);
    };

    for(int j:G[i])
      if(comp1(ps[j],nxt)) nxt=ps[j];

    ps[i]=H.create(Node(T(nxt,cs[i])));

    auto comp2=[&](Node* a,Node* b){
      if(a->val.c!=b->val.c) return (a->val.c)<(b->val.c);
      if(a->val.nxt==b->val.nxt) return false;
      if(!a->val.nxt) return true;
      if(!b->val.nxt) return false;
      return comp1(a->val.nxt,b->val.nxt);
    };

    int l=-1,r=n-(i+1);
    // comp(ps[i], l) : false
    // comp(ps[i], r) : true
    while(l+1<r){
      int m=(l+r)>>1;
      auto p=H.find_by_order(R,m);
      if(comp2(ps[i],p)) r=m;
      else l=m;
    }
    auto s=H.split(R,r);
    R=H.merge(H.merge(s.first,ps[i]),s.second);
  }

  auto cur=ps[0];
  while(cur){
    cout<<(cur->val.c);
    cur=cur->val.nxt;
  }
  cout<<endl;
  return 0;
}
