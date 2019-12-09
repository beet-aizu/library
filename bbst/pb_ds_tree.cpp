#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
template <typename T>
using gtree = tree<T,null_type,less<T>,rb_tree_tag,
                   tree_order_statistics_node_update>;
// usage:
// find_by_order(int k):
// return the iterator of k-th smallest element (0-indexed)
// order_of_key(T key):  return the index of key in tree
//END CUT HERE
#ifndef call_from_test
signed ARC028_B(){
  using ll = long long;
  int n,k;
  cin>>n>>k;
  vector<int> xs(n);
  for(int i=0;i<n;i++) cin>>xs[i];
  map<int, int> mp;
  for(int i=0;i<n;i++) mp[xs[i]]=i+1;
  gtree<ll> G;
  for(int i=0;i<k-1;i++) G.insert(xs[i]);
  for(int i=k-1;i<n;i++){
    G.insert(xs[i]);
    auto key=*G.find_by_order(k-1);
    cout<<mp[key]<<endl;
  }
  return 0;
}

/*
  verified on 2019/12/09
  https://atcoder.jp/contests/arc028/tasks/arc028_2
*/

signed ARC033_C(){
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
  verified on 2019/12/09
  https://atcoder.jp/contests/arc033/tasks/arc033_3
*/

signed main(){
  //ARC028_B();
  //ARC033_C();
  return 0;
}
#endif
