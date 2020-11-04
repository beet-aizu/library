#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../rbst.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Data, size_t LIM>
struct Persistent : RBST<Persistent<Data, LIM>, Data, typename Data::Node, LIM>{
  using super = RBST<Persistent, Data, typename Data::Node, LIM>;
  using Node = typename Data::Node;

  Data data;

  template<class... Args>
  Persistent(Args... args):data(forward<Args>(args)...){}

  inline Node* clone(Node *t){
    if(t==nullptr) return t;
    return super::create(*t);
  }

  inline Node* touch(Node *t){
    if(t==nullptr) return t;
    t=clone(t);
    if(data.dirty(t)){
      t->l=clone(t->l);
      t->r=clone(t->r);
    }
    return data.eval(t);
  }

  using super::toggle;
  inline void toggle(Node *t){return data.toggle(t);}
  template<typename E>
  inline void propagate(Node *t,E x){return data.propagate(t,x);}
  inline Node* pushup(Node *t){return data.pushup(t);}

  inline decltype(auto) get_val(Node *a,size_t k){
    return data.get_val(super::get_val(a,k));
  }

  using super::merge, super::split;
  decltype(auto) query(Node *a,size_t l,size_t r){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=t.first;
    return data.reflect(u);
  }

  bool almost_full() const{
    return super::size+1000>LIM;
  }

  Node* rebuild(Node* a){
    auto vs=data.dump(a);
    super::size=0;
    return super::build(vs);
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../data/array.cpp"
#undef call_from_test

signed JOISC2012_COPYPASTE(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int m;
  string buf;
  cin>>m>>buf;

  using Data = Array<char>;
  using Node = Data::Node;
  const size_t LIM = 1e7;
  Persistent<Data, LIM> pa;

  vector<Node> vs(buf.begin(),buf.end());
  auto rt=pa.build(vs);

  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    auto s=pa.split(rt,a);
    auto t=pa.split(s.second,b-a);
    auto u=pa.split(rt,c);
    rt=pa.merge(pa.merge(u.first,t.first),u.second);

    if((int)pa.count(rt)>m)
      rt=pa.split(rt,m).first;

    if(pa.almost_full()) rt=pa.rebuild(rt);
  }

  auto ds=pa.data.dump(rt);
  buf.resize(ds.size());
  for(int i=0;i<(int)ds.size();i++) buf[i]=ds[i].val;
  cout<<buf<<endl;
  return 0;
}
/*
  verified on 2020/11/04
  https://atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste
*/


#define call_from_test
#include "../data/lazy.cpp"
#undef call_from_test

signed ARC030_D(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,q;
  cin>>n>>q;

  using ll = long long;
  using P = pair<ll, ll>;
  vector<P> vp(n,P(0,1));
  for(int i=0;i<n;i++) cin>>vp[i].first;

  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,ll b){return P(a.first+b*a.second,a.second);};
  auto h=[](ll a,ll b){return a+b;};
  auto flip=[](P a){return a;};

  using Data = Lazy<P, ll, decltype(f), decltype(g), decltype(h),
                    decltype(flip)>;
  using Node = Data::Node;
  constexpr size_t LIM = 6e6;
  Persistent<Data, LIM> G(f,g,h,flip,P(0,0),0);

  vector<Node> vs;
  for(auto v:vp) vs.emplace_back(v,0);
  auto rt=G.build(vs);

  for(int i=0;i<q;i++){
    int t;
    cin>>t;

    if(t==1){
      int a,b,v;
      cin>>a>>b>>v;
      a--;
      rt=G.update(rt,a,b,v);
    }

    if(t==2){
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      a--;c--;
      auto s=G.split(rt,a);
      auto t=G.split(s.second,b-a);
      auto u=G.split(rt,c);
      auto v=G.split(u.second,d-c);

      rt=G.merge(G.merge(s.first,v.first),t.second);
    }

    if(t==3){
      int a,b;
      cin>>a>>b;
      a--;
      cout<<G.query(rt,a,b).first<<newl;
    }

    if(G.almost_full()) rt=G.rebuild(rt);
  }
  return 0;
}
/*
  verified on 2020/11/04
  https://atcoder.jp/contests/arc030/tasks/arc030_4
*/

//INSERT ABOVE HERE
signed main(){
  //JOISC2012_COPYPASTE();
  //ARC030_D();
  return 0;
}
#endif
