#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct PalindromicTree{
  struct node{
    map<char, int> nxt;
    int len,suf,app,cnt;
    node(){}
    node(int len,int suf,int app,int cnt)
      :len(len),suf(suf),app(app),cnt(cnt){}
  };
  vector<node> vs;
  vector<int> ord;
  int n,ptr;

  PalindromicTree(){}
  PalindromicTree(const string &s)
    :vs(s.size()+10),n(2),ptr(1){

    vs[0]=node(-1,0,-1,0);
    vs[1]=node( 0,0,-1,0);

    for(int i=0;i<(int)s.size();i++) add_char(s,i);
    calc_order();
    calc_count();
  }

  bool add_char(const string &s,int pos){
    char ch=s[pos];
    int cur=ptr;
    while(1){
      int rev=pos-1-vs[cur].len;
      if(rev>=0&&s[rev]==ch) break;
      cur=vs[cur].suf;
    }

    if(vs[cur].nxt.count(ch)){
      ptr=vs[cur].nxt[ch];
      vs[ptr].cnt++;
      return false;
    }
    ptr=n++;

    vs[ptr]=node(vs[cur].len+2,-1,pos-vs[cur].len-1,1);
    vs[cur].nxt[ch]=ptr;

    if(vs[ptr].len==1){
      vs[ptr].suf=1;
      return true;
    }

    while(1){
      cur=vs[cur].suf;
      int rev=pos-1-vs[cur].len;
      if(rev>=0&&s[rev]==ch){
        vs[ptr].suf=vs[cur].nxt[ch];
        break;
      }
    }
    return true;
  }

  void calc_order(){
    ord.clear();
    ord.push_back(0);
    ord.push_back(1);
    for(int i=0;i<(int)ord.size();i++)
      for(auto &p:vs[ord[i]].nxt) ord.push_back(p.second);
  }

  void calc_count(){
    for(int i=(int)ord.size()-1;i>=0;i--)
      vs[vs[ord[i]].suf].cnt+=vs[ord[i]].cnt;
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "rollinghash.cpp"
#undef call_from_test

//INSERT ABOVE HERE

// larger constraints than AOJ 2292
signed YUKI_263(){
  using ll = long long;
  string s,t;
  cin>>s>>t;

  PalindromicTree p1(s),p2(t);
  const int MOD = 1e9+7;
  const int BASE1 = 1777771;
  const int BASE2 = 1e6+3;
  RollingHash<int, MOD, BASE1> rs1(s),rt1(t);
  RollingHash<int, MOD, BASE2> rs2(s),rt2(t);

  const int MAX = 5e5+100;
  map<pair<int, int>, int> m1[MAX];
  for(int i=0;i<(int)p1.n;i++){
    auto& u=p1.vs[i];
    if(u.app<0) continue;
    auto p=make_pair(rs1.find(u.app,u.app+u.len),
                     rs2.find(u.app,u.app+u.len));
    m1[u.len][p]=u.cnt;
  }

  ll ans=0;
  for(int i=0;i<(int)p2.n;i++){
    auto& u=p2.vs[i];
    auto p=make_pair(rt1.find(u.app,u.app+u.len),
                     rt2.find(u.app,u.app+u.len));
    if(u.app<0||!m1[u.len].count(p)) continue;
    ans+=(ll)m1[u.len][p]*u.cnt;
  }

  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/10/29
  https://yukicoder.me/problems/no/263
*/

signed main(){
  YUKI_263();
  return 0;
}
#endif
