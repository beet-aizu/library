#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1599"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../vector/compress.cpp"
#include "../../flow/dinic.cpp"
#undef call_from_test

int main(){
  int n;
  cin>>n;
  vector<string> es(n);
  for(int i=0;i<n;i++) cin>>es[i];

  const int L=5;
  vector<string> vs;
  for(string &s:es){
    for(char &c:s){
      if(isdigit(c)) c=c-'0';
      else c=c-'a'+10;
    }
    for(int i=0;i<L;i++){
      if(s[i]&1) continue;
      s[i]=(s[i]+1)%16;
      vs.emplace_back(s);
      s[i]=(s[i]+15)%16;

      s[i]=(s[i]+15)%16;
      vs.emplace_back(s);
      s[i]=(s[i]+1)%16;
    }
  }
  es=compress(es);
  vs=compress(vs);
  auto vd=dict(vs);

  auto restore=
    [](string s){
      for(char &c:s){
        if(c>=10) c='a'+(c-10);
        else c='0'+c;
      }
      return s;
    };

  int m=vd.size();
  Dinic<int, true> G(m+2);
  int S=m,T=m+1;

  vector<int> used(m,0);
  using P = pair<int, int>;
  map<string, P> mp;

  for(string &s:es){
    for(int i=0;i<L;i++){
      if(s[i]&1) continue;

      s[i]=(s[i]+1)%16;
      int x=vd[s];
      s[i]=(s[i]+15)%16;

      s[i]=(s[i]+15)%16;
      int y=vd[s];
      s[i]=(s[i]+1)%16;

      int sum=0;
      for(char c:vs[x]) sum+=c/2;
      if(sum&1) swap(x,y);

      mp[s]=P(x,G.add_edge(x,y,1));

      if(!used[x]){
        mp[vs[x]]=P(S,G.add_edge(S,x,1));
        used[x]=1;
      }

      if(!used[y]){
        mp[vs[y]]=P(y,G.add_edge(y,T,1));
        used[y]=1;
      }
    }
  }

  vector<string> as;
  for(auto s:es) as.emplace_back(s);
  for(auto s:vs) as.emplace_back(s);
  sort(as.begin(),as.end());

  cout<<G.flow(S,T)<<"\n";
  for(auto s:as){
    int x=mp[s].first;
    int a=mp[s].second;
    if(G.cut(S,T,x,a)==1){
      cout<<restore(s)<<"\n";
    }else{
      G.link(S,T,x,a,1);
    }
  }
  cout<<flush;
  return 0;
}
