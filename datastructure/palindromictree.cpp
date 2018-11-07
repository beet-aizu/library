#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct PalindromicTree{
  struct node{
    map<char,int> nxt;
    int len,suf,app,cnt;
    node(){}
    node(int len,int suf,int app,int cnt)
      :len(len),suf(suf),app(app),cnt(cnt){}
  };
  vector<node> v;
  vector<int> ord;
  int n,ptr;
  
  PalindromicTree(){}
  PalindromicTree(const string &s)
    :v(s.size()+10),n(2),ptr(1){
    
    v[0]=node(-1,0,-1,0);
    v[1]=node( 0,0,-1,0);
    
    for(int i=0;i<(int)s.size();i++) add_char(s,i);
    calc_order();
    calc_count();    
  }
  
  bool add_char(const string &s,int pos){
    char ch=s[pos];
    int cur=ptr;
    while(1){
      int rev=pos-1-v[cur].len;
      if(rev>=0&&s[rev]==ch) break;
      cur=v[cur].suf;
    }
    
    if(v[cur].nxt.count(ch)){
      ptr=v[cur].nxt[ch];
      v[ptr].cnt++;
      return false;
    }
    ptr=n++;

    v[ptr]=node(v[cur].len+2,-1,pos-v[cur].len-1,1);    
    v[cur].nxt[ch]=ptr;
    
    if(v[ptr].len==1){
      v[ptr].suf=1;
      return true;
    }
    
    while(1){
      cur=v[cur].suf;
      int rev=pos-1-v[cur].len;
      if(rev>=0&&s[rev]==ch){
        v[ptr].suf=v[cur].nxt[ch];
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
      for(auto &p:v[ord[i]].nxt) ord.push_back(p.second);
  }
  
  void calc_count(){
    for(int i=(int)ord.size()-1;i>=0;i--)
      v[v[ord[i]].suf].cnt+=v[ord[i]].cnt;
  }
};
//END CUT HERE

struct RollingHash{
  using ull = unsigned long long;
  vector<ull> hash,p;
  RollingHash(){}
  RollingHash(const string &s,ull B=1e9+7){
    int n=s.size();
    hash.assign(n+1,0);
    p.assign(n+1,1);
    for(int i=0;i<n;i++){
      hash[i+1]=hash[i]*B+s[i];
      p[i+1]=p[i]*B;
    }
  }
  //s[l, r)
  ull find(int l,int r){
    return hash[r]-hash[l]*p[r-l];
  }
};
//INSERT ABOVE HERE

signed main(){
  using ll = long long;
  string s,t;
  cin>>s>>t;
  PalindromicTree p1(s),p2(t);
  RollingHash r1(s),r2(t);
  using ull = RollingHash::ull;
  
  const int MAX = 5e5+100;
  map<ull, int> m1[MAX];
  for(int i=0;i<(int)p1.n;i++){
    PalindromicTree::node& u=p1.v[i];
    if(u.app<0) continue;
    m1[u.len][r1.find(u.app,u.app+u.len)]=u.cnt;
  }
  
  ll ans=0;
  for(int i=0;i<(int)p2.n;i++){
    PalindromicTree::node& u=p2.v[i]; 
    ull x=r2.find(u.app,u.app+u.len);
    if(u.app<0||!m1[u.len].count(x)) continue;
    ans+=(ll)m1[u.len][x]*u.cnt;
  }
  
  cout<<ans<<endl;
  return 0;
}

/*
  verified on 2018/11/07
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2292
  https://yukicoder.me/problems/no/263
*/
