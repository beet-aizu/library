#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../bbst/rbst/rbst.cpp"
#include "../../bbst/rbst/data/array.cpp"
#include "../../bbst/rbst/impl/persistent.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  using Data = Array<int>;
  using Node = Data::Node;
  const int LIM = 2e7;
  Persistent<Data, LIM> pa;
  Node* rt=pa.create(0);

  int q;
  cin>>q;
  vector<Node*> ss(q,nullptr);
  for(int i=0;i<q;i++){
    int a;
    cin>>a;
    if(a==0){
      int t,x;
      cin>>t>>x;
      Node* p=~t?ss[t]:rt;
      ss[i]=pa.insert(p,p->cnt,Node(x));
    }
    if(a==1){
      int t;
      cin>>t;
      cout<<pa.get_val(ss[t],1)<<newl;
      ss[i]=pa.erase(ss[t],1);
    }
  }

  return 0;
}
