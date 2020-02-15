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

  size_t size()const{return n;}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
