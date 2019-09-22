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
  vector<Node> v;
  F conv;

  Trie(F conv,char c='$'):conv(conv){v.emplace_back(c);}

  void add(const string &s,int x){
    int pos=0;
    for(int i=0;i<(int)s.size();i++){
      int k=conv(s[i]);
      if(~v[pos].nxt[k]){
        pos=v[pos].nxt[k];
        continue;
      }
      int npos=v.size();
      v[pos].nxt[k]=npos;
      v.emplace_back(s[i]);
      pos=npos;
    }
    v[pos].idx=x;
    v[pos].idxs.emplace_back(x);
  }

  int find(const string &s){
    int pos=0;
    for(int i=0;i<(int)s.size();i++){
      int k=conv(s[i]);
      if(v[pos].nxt[k]<0) return -1;
      pos=v[pos].nxt[k];
    }
    return pos;
  }

  int find(int pos,char c){
    return v[pos].nxt[conv(c)];
  }

  int idx(int pos){
    return pos<0?-1:v[pos].idx;
  }

  vector<int> idxs(int pos){
    return pos<0?vector<int>():v[pos].idxs;
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
    auto &v=TRIE::v;
    int n=v.size();
    cnt.resize(n);
    for(int i=0;i<n;i++){
      if(heavy) sort(v[i].idxs.begin(),v[i].idxs.end());
      cnt[i]=v[i].idxs.size();
    }

    queue<int> q;
    for(int i=0;i<(int)X;i++){
      if(~v[0].nxt[i]){
        v[v[0].nxt[i]].nxt[X]=0;
        q.emplace(v[0].nxt[i]);
      }else{
        v[0].nxt[i]=0;
      }
    }

    while(!q.empty()){
      auto &x=v[q.front()];
      cnt[q.front()]+=cnt[x.nxt[X]];
      q.pop();
      for(int i=0;i<(int)X;i++){
        if(x.nxt[i]<0) continue;
        int fail=x.nxt[X];
        while(v[fail].nxt[i]<0) fail=v[fail].nxt[X];
        v[x.nxt[i]].nxt[X]=v[fail].nxt[i];
        if(heavy){
          auto &idx=v[x.nxt[i]].idxs;
          auto &idy=v[v[fail].nxt[i]].idxs;
          vector<int> idz;
          set_union(idx.begin(),idx.end(),
                    idy.begin(),idy.end(),
                    back_inserter(idz));
          idx=idz;
        }
        q.emplace(x.nxt[i]);
      }
    }
  }

  vector<int> match(string s,int heavy=true){
    auto &v=TRIE::v;
    vector<int> res(heavy?TRIE::size():1);
    int pos=0;
    for(auto &c:s){
      int k=TRIE::conv(c);
      while(v[pos].nxt[k]<0) pos=v[pos].nxt[X];
      pos=v[pos].nxt[k];
      if(heavy) for(auto &x:v[pos].idxs) res[x]++;
      else res[0]+=cnt[pos];
    }
    return res;
  }

  int move(int pos,char c){
    auto &v=TRIE::v;
    int k=TRIE::conv(c);
    while(v[pos].nxt[k]<0) pos=v[pos].nxt[X];
    pos=v[pos].nxt[k];
    return pos;
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
      int k=aho.v[pos].idxs[0];
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
  verified on 2019/05/24
  https://www.spoj.com/problems/BLHETA/
*/

signed main(){
  //SPOJ_BLHETA();
  return 0;
}
#endif
