#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE

template<int X>
struct Trie{
  struct Node{
    char c;
    vector<int> nxt,idxs;
    int idx;
    Node(char c):c(c),nxt(X,-1),idx(-1){}
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
//END CUT HERE

template<typename T> void chmin(T &a,T b){if(a>b) a=b;}
template<typename T> void chmax(T &a,T b){if(a<b) a=b;}

signed main(){
  string s;
  cin>>s;
  int m;
  cin>>m;
  vector<string> p(m);
  for(int i=0;i<m;i++) cin>>p[i];
  
  vector<int> w(m);
  for(int i=0;i<m;i++) cin>>w[i];

  Trie<26>::F f=[](char c){return c-'a';};
  Trie<26> trie(f);

  for(int i=0;i<m;i++) trie.add(p[i],i);

  int n=s.size();
  vector<int> dp(n+1,0);
  int ans=0;
  for(int i=0;i<n;i++){
    chmax(ans,dp[i]);
    int pos=0;
    for(int j=0;j<222&&i+j<n;j++){
      pos=trie.find(pos,s[i+j]);
      if(pos<0) break;
      int k=trie.idx(pos);
      if(~k) chmax(dp[i+p[k].size()],ans+w[k]);
    }
  }
  chmax(ans,dp[n]);
  cout<<ans<<endl;
  return 0;
}

/*
  verified on 2018/05/20
  https://beta.atcoder.jp/contests/tenka1-2016-final/tasks/tenka1_2016_final_c
*/
