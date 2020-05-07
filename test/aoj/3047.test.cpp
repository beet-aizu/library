#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3047"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../flow/dinic.cpp"
#undef call_from_test

const int K = 28;
int cap[K][K];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin>>s[i];

  for(int i=0;i<26;i++){
    memset(cap,0,sizeof(cap));

    int x=26,y=27,z=0,e=0;
    Dinic<int, true> G(K);

    for(int j=0;j<n;j++){
      int u=s[j].front()-'a';
      int v=s[j].back()-'a';
      if(u==i) z++;
      if(v==i) e++;
      if(u==i) u=x;
      if(v==i) v=y;
      if(u!=v) cap[u][v]++;
    }

    for(int u=0;u<K;u++)
      for(int v=0;v<K;v++)
        if(cap[u][v]) G.add_edge(u,v,cap[u][v]);

    if((e&&!z)||(z&&G.flow(x,y)==z)) cout<<char('a'+i)<<endl;
  }

  return 0;
}
