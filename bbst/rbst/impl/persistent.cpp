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
      t->l=clone(t->r);
    }
    return data.eval(t);
  }

  using super::toggle;
  inline void toggle(Node *t){return data.toggle(t);}
  template<typename E>
  inline void propagate(Node *t,E x){return data.propagate(t,x);}
  inline Node* pushup(Node *t){return data.pushup(t);}

  inline decltype(auto) get_val(Node *a,size_t k){
    return data.reflect(super::get_val(a,k));
  }

  using super::query;
  inline decltype(auto) query(Node *a){
    return data.reflect(a);
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

//INSERT ABOVE HERE
signed main(){
  //JOISC2012_COPYPASTE();
  return 0;
}
#endif
