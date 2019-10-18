#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#endif
//BEGIN CUT HERE
// prohibited to push an element less than popped one
// Key: int or long long
template<typename K,typename V>
struct RadixHeap{
  static constexpr int bit = sizeof(K) * 8;
  array<vector< pair<K, V> >, bit> vs;

  int size;
  K last;
  RadixHeap():size(0),last(0){}

  bool empty() const{return size==0;}

  inline int getbit(int a){
    return a?bit-__builtin_clz(a):0;
  }

  inline int getbit(long long a){
    return a?bit-__builtin_clzll(a):0;
  }

  void emplace(K key,V val){
    size++;
    vs[getbit(key^last)].emplace_back(key,val);
  }

  pair<K, V> pop(){
    if(vs[0].empty()){
      int idx=1;
      while(vs[idx].empty()) idx++;
      last=min_element(vs[idx].begin(),vs[idx].end())->first;
      for(auto &p:vs[idx]) vs[getbit(p.first^last)].emplace_back(p);
      vs[idx].clear();
    }
    --size;
    auto res=vs[0].back();
    vs[0].pop_back();
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
