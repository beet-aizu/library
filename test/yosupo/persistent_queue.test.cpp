#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../bbst/rbst/basic/base.cpp"
#include "../../bbst/rbst/persistent/base.cpp"
#include "../../bbst/rbst/persistent/array.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using Node = NodeBase<int>;
  const int LIM = 2e7;
  PersistentArray<Node, LIM> pa;
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
      cout<<pa.get_val(ss[t],1)<<"\n";
      ss[i]=pa.erase(ss[t],1);
    }
  }

  return 0;
}
