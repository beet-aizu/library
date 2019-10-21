#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../datastructure/binarytrie.cpp"
#undef call_from_test

signed main(){
  int n,q;
  cin>>n>>q;

  BinaryTrie<int, 30> bt;
  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c==0){
      bt.add(x,y);
    }
    if(c==1){
      int res=bt.order_of_key(y+1)-bt.order_of_key(x);
      cout<<res<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
