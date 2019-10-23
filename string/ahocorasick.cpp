#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

template<size_t X>
struct Trie{
  struct Node{
    char c;
    array<int, X> nxt;
    vector<int> idxs;
    int idx;
    Node(char c):c(c),idx(-1){fill(nxt.begin(),nxt.end(),-1);}
  };

  using F = function<int(char)>;
  vector<Node> vs;
  F conv;

  Trie(F conv,char c='$'):conv(conv){vs.emplace_back(c);}

  void add(const string &s,int x){
    int pos=0;
    for(int i=0;i<(int)s.size();i++){
      int k=conv(s[i]);
      if(~vs[pos].nxt[k]){
        pos=vs[pos].nxt[k];
        continue;
      }
      int npos=vs.size();
      vs[pos].nxt[k]=npos;
      vs.emplace_back(s[i]);
      pos=npos;
    }
    vs[pos].idx=x;
    vs[pos].idxs.emplace_back(x);
  }

  int find(const string &s){
    int pos=0;
    for(int i=0;i<(int)s.size();i++){
      int k=conv(s[i]);
      if(vs[pos].nxt[k]<0) return -1;
      pos=vs[pos].nxt[k];
    }
    return pos;
  }

  int find(int pos,char c){
    return vs[pos].nxt[conv(c)];
  }

  int idx(int pos){
    return pos<0?-1:vs[pos].idx;
  }

  vector<int> idxs(int pos){
    return pos<0?vector<int>():vs[pos].idxs;
  }

};

#endif
//BEGIN CUT HERE
template<size_t X>
struct AhoCorasick : Trie<X+1>{
  using TRIE = Trie<X+1>;
  using TRIE::TRIE;
  vector<int> cnt;

  void build(bool heavy=true){
    auto &vs=TRIE::vs;
    int n=vs.size();
    cnt.resize(n);
    for(int i=0;i<n;i++){
      if(heavy) sort(vs[i].idxs.begin(),vs[i].idxs.end());
      cnt[i]=vs[i].idxs.size();
    }

    queue<int> que;
    for(int i=0;i<(int)X;i++){
      if(~vs[0].nxt[i]){
        vs[vs[0].nxt[i]].nxt[X]=0;
        que.emplace(vs[0].nxt[i]);
      }else{
        vs[0].nxt[i]=0;
      }
    }

    while(!que.empty()){
      auto &x=vs[que.front()];
      cnt[que.front()]+=cnt[x.nxt[X]];
      que.pop();
      for(int i=0;i<(int)X;i++){
        if(x.nxt[i]<0){
          x.nxt[i]=vs[x.nxt[X]].nxt[i];
          continue;
        }
        int fail=x.nxt[X];
        vs[x.nxt[i]].nxt[X]=vs[fail].nxt[i];
        if(heavy){
          auto &idx=vs[x.nxt[i]].idxs;
          auto &idy=vs[vs[fail].nxt[i]].idxs;
          vector<int> idz;
          set_union(idx.begin(),idx.end(),
                    idy.begin(),idy.end(),
                    back_inserter(idz));
          idx=idz;
        }
        que.emplace(x.nxt[i]);
      }
    }
  }

  vector<int> match(string s,int heavy=true){
    auto &vs=TRIE::vs;
    vector<int> res(heavy?TRIE::size():1);
    int pos=0;
    for(auto &c:s){
      pos=vs[pos].nxt[TRIE::conv(c)];
      if(heavy) for(auto &x:vs[pos].idxs) res[x]++;
      else res[0]+=cnt[pos];
    }
    return res;
  }

  int move(int pos,char c){
    auto &vs=TRIE::vs;
    assert(pos<(int)vs.size());
    return vs[pos].nxt[TRIE::conv(c)];
  }

  int count(int pos){
    return cnt[pos];
  }
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
  verified on 2019/10/23
  https://www.spoj.com/problems/BLHETA/
*/

signed main(){
  SPOJ_BLHETA();
  return 0;
}
#endif
