#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<size_t X>
struct Trie{
  struct Node{
    array<int, X> nxt;
    vector<int> idxs;
    int idx;
    Node():idx(-1){fill(nxt.begin(),nxt.end(),-1);}
  };

  using F = function<int(char)>;
  vector<Node> vs;
  F conv;

  Trie(F conv):conv(conv){vs.emplace_back();}
  Trie(char start):Trie([=](char a){return a-start;}){}

  inline int &next(int i,int j){
    return vs[i].nxt[j];
  }

  void add(const string &s,int x){
    int pos=0;
    for(char c:s){
      int k=conv(c);
      if(~next(pos,k)){
        pos=next(pos,k);
        continue;
      }
      int npos=vs.size();
      next(pos,k)=npos;
      vs.emplace_back();
      pos=npos;
    }
    vs[pos].idx=x;
    vs[pos].idxs.emplace_back(x);
  }

  int find(const string &s){
    int pos=0;
    for(char c:s){
      int k=conv(c);
      if(next(pos,k)<0) return -1;
      pos=next(pos,k);
    }
    return pos;
  }

  int move(int pos,char c){
    assert(pos<(int)vs.size());
    return pos<0?-1:next(pos,conv(c));
  }

  int size(){return vs.size();}

  int idx(int pos){
    return pos<0?-1:vs[pos].idx;
  }

  vector<int> idxs(int pos){
    return pos<0?vector<int>():vs[pos].idxs;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
