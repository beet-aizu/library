#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
template <typename T>
using gtree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// usage:
// find_by_order(int k): return the iterator of k-th smallest element (0-indexed)
// order_by_key(T key):  return the index of key in tree
//END CUT HERE
signed main(){
  int q;
  cin>>q;
  gtree<int> G;
  while(q--){
    int t,x;
    cin>>t>>x;
    if(t==1) G.insert(x);
    if(t==2){
      int k=*G.find_by_order(x-1);
      G.erase(k);
      cout<<k<<endl;
    }
  }
  return 0;
}

/*
verified on 2017/12/12
https://beta.atcoder.jp/contests/arc033/tasks/arc033_3
 */
