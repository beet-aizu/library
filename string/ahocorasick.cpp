#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;

#define call_from_test
#include "trie.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<size_t X>
struct AhoCorasick : Trie<X+1>{
  using TRIE = Trie<X+1>;
  using TRIE::TRIE;
  using TRIE::next;
  vector<int> cnt;

  void build(int heavy=true){
    auto &vs=TRIE::vs;
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

  vector<int> match(string s,int heavy=true){
    auto &vs=TRIE::vs;
    vector<int> res(heavy?TRIE::size():1);
    int pos=0;
    for(auto &c:s){
      pos=next(pos,TRIE::conv(c));
      if(heavy) for(auto &x:vs[pos].idxs) res[x]++;
      else res[0]+=cnt[pos];
    }
    return res;
  }

  int move(int pos,char c){
    auto &vs=TRIE::vs;
    assert(pos<(int)vs.size());
    return next(pos,TRIE::conv(c));
  }

  int count(int pos){
    return cnt[pos];
  }

  int size(){return TRIE::vs.size();}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed SPOJ_BLHETA(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  string s;
  cin>>s;

  int n;
  cin>>n;
  vector<string> ts(n);
  for(int i=0;i<n;i++)cin>>ts[i];

  auto conv=[](char c){return c-'A';};
  AhoCorasick<26> aho(conv);
  for(int i=0;i<n;i++){
    aho.add(ts[i],i);
  }
  aho.build();

  int l=s.size();
  int pos=0;

  vector<int> vs;
  vs.emplace_back(pos);

  string ans;
  for(int i=0;i<l;i++){
    pos=aho.move(pos,s[i]);
    vs.emplace_back(pos);
    ans+=s[i];
    if(aho.count(pos)){
      int k=aho.vs[pos].idxs[0];
      for(int j=0;j<(int)ts[k].size();j++){
        vs.pop_back();
        pos=vs.back();
        ans.pop_back();
      }
    }
  }

  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/10/28
  https://www.spoj.com/problems/BLHETA/
*/

signed main(){
  SPOJ_BLHETA();
  return 0;
}
#endif
