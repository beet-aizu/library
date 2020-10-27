#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#endif
//BEGIN CUT HERE
// add recursive sequence
template<typename T>
struct RecursiveSequence{
  vector<vector<int>> add,sub;
  RecursiveSequence(int n):add(n),sub(n+1){}

  // add a_0, ..., a_{r-l-1} to [l, r)
  void query(int l,int r){
    add[l].emplace_back(0);
    sub[r].emplace_back(r-l);
  }

  // a_i = \sum_{k} c_k a_{i-k}
  vector<T> build(vector<T> as,vector<T> cs){
    assert(as.size()==cs.size());
    int n=add.size();
    int k=as.size();

    reverse(cs.begin(),cs.end());
    as.resize(n+k);
    for(int i=0;i<n;i++)
      for(int j=0;j<k;j++)
        as[i+k]+=as[i+j]*cs[j];

    vector<T> ss(n+k,T(0));
    for(int i=0;i<n;i++){
      for(int l:add[i])
        for(int j=0;j<k;j++)
          ss[i+j]+=as[l+j];

      for(int l:sub[i])
        for(int j=0;j<k;j++)
          ss[i+j]-=as[l+j];

      for(int j=0;j<k;j++)
        ss[i+k]+=ss[i+j]*cs[j];
    }
    ss.resize(n);
    return ss;
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
