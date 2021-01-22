#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "trie.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<size_t X, bool heavy>
struct AhoCorasick : Trie<X+1>{
  using super = Trie<X+1>;
  using super::super, super::next, super::size;
  using super::vs, super::conv;

  vector<int> cnt;

  // O(\sigma \sum |T_i|)
  void build(){
    int n=vs.size();
    cnt.resize(n);
    for(int i=0;i<n;i++){
      if(heavy) sort(vs[i].idxs.begin(),vs[i].idxs.end());
      cnt[i]=vs[i].idxs.size();
    }

    queue<int> que;
    for(int i=0;i<(int)X;i++){
      if(~next(0,i)){
        next(next(0,i),X)=0;
        que.emplace(next(0,i));
      }else{
        next(0,i)=0;
      }
    }

    while(!que.empty()){
      auto &x=vs[que.front()];
      int fail=x.nxt[X];

      cnt[que.front()]+=cnt[fail];
      que.pop();

      for(int i=0;i<(int)X;i++){
        int &nx=x.nxt[i];
        if(nx<0){
          nx=next(fail,i);
          continue;
        }
        que.emplace(nx);
        next(nx,X)=next(fail,i);
        if(heavy){
          auto &idx=vs[nx].idxs;
          auto &idy=vs[next(fail,i)].idxs;
          vector<int> idz;
          set_union(idx.begin(),idx.end(),
                    idy.begin(),idy.end(),
                    back_inserter(idz));
          idx=idz;
        }
      }
    }
  }

  int count(int pos){
    return cnt[pos];
  }

  // O(|S|)
  int match(string s){
    int res=0,pos=0;
    for(auto &c:s){
      pos=next(pos,conv(c));
      res+=count(pos);
    }
    return res;
  }

  // O(|S| + \sum |T_i|)
  vector<int> frequency(string s){
    vector<int> res(size(),0);
    int pos=0;
    for(auto &c:s){
      pos=next(pos,conv(c));
      res[pos]++;
    }
    for(int i=size()-1;i;i--)
      res[vs[i].nxt[X]]+=res[i];
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
