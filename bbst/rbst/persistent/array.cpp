#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../basic/base.cpp"
#include "../basic/array.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Node, size_t LIM>
struct PersistentArray : Array<Node, LIM>{
  using super = Array<Node, LIM>;
  using super::super;

  inline Node* clone(Node* a){
    if(a==nullptr) return a;
    return super::create(*a);
  }

  Node* eval(Node* a){
    a=clone(a);
    if(a->rev){
      a->l=clone(a->l);
      a->r=clone(a->r);
    }
    return super::eval(a);
  }

  Node* rebuild(Node* a){
    auto v=super::dump(a);
    super::size=0;
    return super::build(v);
  }

  bool almost_full() const{
    return super::size>LIM*9/10;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed JOISC2012_COPYPASTE(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int m;
  string buf;
  cin>>m>>buf;

  using Node = NodeBase<char>;
  const size_t LIM = 1e7;
  PersistentArray<Node, LIM> pa;

  vector<char> v(buf.begin(),buf.end());
  auto rt=pa.build(v);

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

  auto ds=pa.dump(rt);
  buf.resize(ds.size());
  for(int i=0;i<(int)ds.size();i++) buf[i]=ds[i];
  cout<<buf<<endl;
  return 0;
}
/*
  verified on 2019/10/22
  https://atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste
*/

signed main(){
  JOISC2012_COPYPASTE();
  return 0;
}
#endif
