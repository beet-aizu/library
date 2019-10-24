#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2890"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../bbst/basic/base.cpp"
#include "../../bbst/basic/array.cpp"
#undef call_from_test

signed main(){
  int n,q;
  cin>>n>>q;

  using Node = NodeBase<int>;
  const int LIM = 1e6;
  Array<Node, LIM> as;

  Node* rt=nullptr;
  vector<Node*> vs(n+1);
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    a--;
    vs[a]=as.create(a+1);
    rt=as.merge(rt,vs[a]);
  }

  for(int i=0;i<q;i++){
    int p;
    cin>>p;
    p--;
    int k=as.order_of_key(vs[p]);
    auto s=as.split(rt,k);
    auto t=as.split(s.second,1);
    rt=as.merge(as.merge(t.second,t.first),s.first);
  }

  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<as.get_val(rt,i);
  }
  cout<<endl;
  return 0;
}
