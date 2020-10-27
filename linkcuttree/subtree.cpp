#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "base.cpp"
#undef call_from_test

#endif
// http://beet-aizu.hatenablog.com/entry/2019/06/08/221833
//BEGIN CUT HERE
template<typename Ap>
struct NodeBase{
  using A = Ap;
  NodeBase *l,*r,*p;
  bool rev;
  A val,dat,sum;
  NodeBase(){}
  NodeBase(A val,A dat,A sum):
    rev(0),val(val),dat(dat),sum(sum){
    l=r=p=nullptr;}
};

template<typename Np, size_t LIM>
struct SubTree : LinkCutTreeBase<Np, LIM>{
  using super = LinkCutTreeBase<Np, LIM>;
  using Node = Np;
  using A = typename Node::A;

  Node* create(A val){
    return super::create(Node(val,A(),val));
  }

  inline void toggle(Node *t){
    swap(t->l,t->r);
    t->rev^=1;
  }

  inline Node* eval(Node *t){
    if(t->rev){
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
    return t;
  }

  inline A resolve(Node *t){
    return t?t->sum:A();
  }

  inline void pushup(Node *t){
    if(t==nullptr) return;
    t->sum=t->val+t->dat;
    t->sum+=resolve(t->l);
    t->sum+=resolve(t->r);
  }

  using super::splay;

  Node* expose(Node *t){
    Node *rp=nullptr;
    for(Node *c=t;c;c=c->p){
      splay(c);
      c->dat+=resolve(c->r);
      c->r=rp;
      c->dat-=resolve(c->r);
      pushup(c);
      rp=c;
    }
    splay(t);
    return rp;
  }

  A query(Node *t){
    expose(t);
    return t->sum;
  }

  void set_val(Node *t,A a){
    expose(t);
    t->val=a;
    pushup(t);
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#undef call_from_test

//INSERT ABOVE HERE

// sum of square
signed CFR564_E(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> modv(n),modt(n);
  vector<int> cs(n);

  for(int i=0;i<n;i++){
    cin>>cs[i];
    cs[i]--;
    modv[cs[i]].emplace_back(i);
    modt[cs[i]].emplace_back(0);
  }

  vector<vector<int> > G(n+1);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  G[n].emplace_back(0);

  for(int i=1;i<=m;i++){
    int v,x;
    cin>>v>>x;
    v--;x--;
    modv[cs[v]].emplace_back(v);
    modt[cs[v]].emplace_back(i);
    cs[v]=x;
    modv[cs[v]].emplace_back(v);
    modt[cs[v]].emplace_back(i);
  }

  using ll = long long;
  struct A{
    ll sz1,sz2;
    A():sz1(0),sz2(){}
    A(ll sz1,ll sz2):sz1(sz1),sz2(sz2){}
    A operator+(const A &a)const{
      return A(sz1+a.sz1,sz2+a.sz2);
    };
    A& operator+=(const A &a){
      sz1+=a.sz1;
      sz2+=a.sz1*a.sz1;
      return (*this);
    }
    A& operator-=(const A &a){
      sz1-=a.sz1;
      sz2-=a.sz1*a.sz1;
      return (*this);
    }
  };

  using Node = NodeBase<A>;
  constexpr size_t LIM = 1e6;
  using LCT = SubTree<Node, LIM>;
  LCT lct;

  for(int i=0;i<n+1;i++) lct.create(A(1,0));

  vector<int> par(n+1,0);
  {
    using P = pair<int, int>;
    queue<P> q;
    q.emplace(n,-1);
    while(!q.empty()){
      int v,p;
      tie(v,p)=q.front();q.pop();
      par[v]=p;
      if(~p) lct.link(lct[p],lct[v]);
      for(int u:G[v])
        if(u!=p) q.emplace(u,v);
    }
  }

  vector<ll> delta(m+1,0);
  vector<int> color(n+1,0);

  for(int c=0;c<n;c++){
    ll lst=(ll)n*n,cur=(ll)n*n;
    delta[0]+=lst;

    if(modv[c].empty()) continue;
    for(int i=0;i<(int)modv[c].size();i++){
      int v=modv[c][i];
      color[v]^=1;
      if(color[v]){
        cur-=lct.query(lct.root(lct[v])).sz2;
        lct.cut(lct[v]);
        cur+=lct.query(lct.root(lct[par[v]])).sz2;
        cur+=lct.query(lct[v]).sz2;
      }else{
        cur-=lct.query(lct.root(lct[par[v]])).sz2;
        cur-=lct.query(lct[v]).sz2;
        lct.link(lct[par[v]],lct[v]);
        cur+=lct.query(lct.root(lct[v])).sz2;
      }
      if(i+1==(int)modv[c].size() or modt[c][i]!=modt[c][i+1]){
        delta[modt[c][i]]+=cur-lst;
        lst=cur;
      }
    }

    for(int i=0;i<(int)modv[c].size();i++){
      int v=modv[c][i];
      if(!color[v]) continue;
      color[v]^=1;
      lct.link(lct[par[v]],lct[v]);
    }
  }

  ll ans=(ll)n*n*n;
  for(int i=0;i<=m;i++){
    ans-=delta[i];
    cout<<ans<<"\n";
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2020/01/06
  https://codeforces.com/contest/1172/problem/E
*/

// test root
signed NIKKEI2019_QUAL_E(){
  int n,m;
  cin>>n>>m;
  vector<int> xs(n);
  for(int i=0;i<n;i++) cin>>xs[i];
  using T = tuple<int, int, int>;
  vector<T> vt;
  for(int i=0;i<m;i++){
    int a,b,y;
    cin>>a>>b>>y;
    a--;b--;
    vt.emplace_back(y,a,b);
  }
  sort(vt.begin(),vt.end());

  using ll = long long;
  using Node = NodeBase<ll>;
  constexpr size_t LIM = 1e6;
  using LCT = SubTree<Node, LIM>;
  LCT lct;

  for(int i=0;i<n;i++) lct.create(xs[i]);

  using P = pair<int, int>;
  set<P> es;
  for(auto t:vt){
    int a,b;
    tie(ignore,a,b)=t;
    if(lct.is_connected(lct[a],lct[b])) continue;
    lct.evert(lct[b]);
    lct.link(lct[a],lct[b]);
    es.emplace(a,b);
  }

  int ans=0;
  reverse(vt.begin(),vt.end());
  for(auto t:vt){
    int y,a,b;
    tie(y,a,b)=t;
    auto rt=lct.root(lct[a]);
    ll sum=lct.query(rt);
    if(sum>=y) continue;
    ans++;
    if(es.count(P(a,b))){
      lct.evert(lct[a]);
      lct.cut(lct[b]);
    }
  }

  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2020/01/06
  https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_e
*/

signed main(){
  //CFR564_E();
  //NIKKEI2019_QUAL_E();
  return 0;
}
#endif
