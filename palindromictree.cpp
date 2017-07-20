#include<bits/stdc++.h>
using namespace std;
#define int long long
//BEGIN CUT HERE
struct PalindromicTree{
  struct node{
    map<char,int> nxt;
    int len,suf,hei,app,cnt;
  };
  string s;
  vector<node> v;
  vector<int> ord;
  int n,suff;
  PalindromicTree(){}
  PalindromicTree(string s_){init(s_);build();}
  bool addchar(int pos){
    char ch=s[pos];
    int cur=suff;
    while(1){
      if(pos-1-v[cur].len>=0&&s[pos-1-v[cur].len]==ch) break;
      cur=v[cur].suf;
    }
    if(v[cur].nxt.count(ch)){
      suff=v[cur].nxt[ch];
      v[suff].cnt++;
      return false;
    }
    suff=n++;
    v[suff].len=v[cur].len+2;
    v[suff].app=pos-v[suff].len+1;
    v[suff].cnt=1;
    v[cur].nxt[ch]=suff;
    
    if(v[suff].len==1){
      v[suff].suf=1;
      v[suff].hei=1;
      return true;
    }
    while(1){
      cur=v[cur].suf;
      if(pos-1-v[cur].len>=0&&s[pos-1-v[cur].len]==ch){
	v[suff].suf=v[cur].nxt[ch];
	break;
      }
    }
    v[suff].hei=v[v[suff].suf].hei+1;
    return true;
  }
  
  void init(string s_){
    s=s_;
    v.clear();
    v.resize(s.length()+10);

    n=2;
    suff=1;
    v[0].app=v[1].app=-1;
    v[0].len=-1;v[1].len=0;
    v[0].suf=v[1].suf=0;
    v[0].hei=v[1].hei=0;
  }
  
  void calcOrder(){
    ord.clear();
    ord.push_back(0);
    ord.push_back(1);
    for(int i=0;i<(int)ord.size();i++){
      for(auto &p:v[ord[i]].nxt) ord.push_back(p.second);
    }
  }
  
  void calcCount(){
    assert(ord.size());
    for(int i=(int)ord.size()-1;i>=0;i--){
      v[v[ord[i]].suf].cnt+=v[ord[i]].cnt;
    }
    v[0].cnt=v[1].cnt=0;
  }

  void build(){
    for(int i=0;i<(int)s.size();i++) addchar(i);
    calcOrder();
    calcCount();
  }
  
};
//END CUT HERE

struct RollingHash{
  typedef unsigned long long ull;
  string S;
  ull B;
  vector<ull> hash,p;
  int len;
  RollingHash(){}
  RollingHash(string S,ull B=1000000007LL):S(S),B(B){init();};
  void init(){
    len=S.length();
    hash.resize(len+1);
    p.resize(len+1);
    hash[0]=0;p[0]=1;
    for(int i=0;i<len;i++){
      hash[i+1]=hash[i]*B+S[i];
      p[i+1]=p[i]*B;
    }
  }
  //S[l,r)
  ull find(int l,int r){
    return hash[r]-hash[l]*p[r-l];
  }
};

signed main(){
  string s,t;
  cin>>s>>t;
  PalindromicTree p1(s),p2(t);
  RollingHash r1(s),r2(t);
  map<int,int> m1[55555],m2[55555];
  for(int i=0;i<(int)p1.n;i++){
    PalindromicTree::node& u=p1.v[i];
    if(u.app<0) continue;
    m1[u.len][r1.find(u.app,u.app+u.len)]=u.cnt;
  }
  for(int i=0;i<(int)p2.n;i++){
    PalindromicTree::node& u=p2.v[i]; 
    if(u.app<0) continue;
    m2[u.len][r2.find(u.app,u.app+u.len)]=u.cnt;
  }
  int ans=0;
  for(int i=1;i<=(int)s.length();i++){
    for(auto p:m1[i]){
      ans+=m2[i][p.first]*p.second;
    }
  }
  cout<<ans<<endl;
  return 0;
}


/*
verified on 2017/07/20
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2292
*/
