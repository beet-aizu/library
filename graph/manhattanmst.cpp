#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
vector<pair<int, int>> manhattanmst(vector<T> xs,vector<T> ys){
  using P = pair<int, int>;
  vector<P> es;
  int n=xs.size();

  // xs[i] <- xs[i] + \eps^i, ys[i] <- ys[i] + \eps^(n+i),
  for(int s=0;s<2;s++){
    for(int t=0;t<2;t++){
      vector<int> ord(n);
      iota(ord.begin(),ord.end(),0);
      auto cmp=[&](int i,int j)->bool{
        if(xs[i]+ys[i]!=xs[j]+ys[j]) return xs[i]+ys[i]<xs[j]+ys[j];
        return s^(i>j);
      };
      sort(ord.begin(),ord.end(),cmp);

      map<pair<T, int>, int> idx;
      for(int i:ord){
        for(auto it=idx.lower_bound({-ys[i],(s&t)?+i:-i});
            it!=idx.end();it=idx.erase(it)){
          int j=it->second;
          if(xs[i]-xs[j]<ys[i]-ys[j]) break;
          es.emplace_back(i,j);
        }
        idx[{-ys[i],(s&t)?+i:-i}]=i;
      }
      swap(xs,ys);
    }
    for(int i=0;i<n;i++) xs[i]*=-1;
  }
  return es;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
