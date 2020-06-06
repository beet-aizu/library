#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/binarytrie.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  BinaryTrie<int, 30> bt;

  int q;
  cin>>q;

  for(int i=0;i<q;i++){
    int t,x;
    cin>>t>>x;
    if(t==0){
      if(bt.find(x)) continue;
      bt.add(x,1);
    }
    if(t==1){
      if(!bt.find(x)) continue;
      bt.sub(bt.find(x),1);
    }
    if(t==2){
      cout<<(x^bt.val(bt.xmin(x)))<<newl;
    }
  }

  return 0;
}
