#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2328"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../string/split.cpp"
#include "../../flow/dinic.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  const int DEG = 55;
  const int INF = 1<<28;
  int n,m;
  while(cin>>n>>m,n){
    Dinic<int, false> flow(n);
    int ed[DEG][55][55];
    memset(ed,0,sizeof(ed));

    for(int i=0;i<m;i++){
      int a,b;
      string s;
      cin>>a>>b>>s;
      a--;b--;
      flow.add_edge(a,b,0);
      for(string t:split(s,'+')){
        if(!count(t.begin(),t.end(),'x')){
          ed[0][a][b]+=stoi(t);
          ed[0][b][a]+=stoi(t);
        }else if(t.back()=='x'){
          t.pop_back();
          if(t.empty()) t="1";
          ed[1][a][b]+=stoi(t);
          ed[1][b][a]+=stoi(t);
        }else{
          auto v=split(t,'^');
          v[0].pop_back();
          if(v[0].empty()) v[0]="1";
          ed[stoi(v[1])][a][b]+=stoi(v[0]);
          ed[stoi(v[1])][b][a]+=stoi(v[0]);
        }
      }
    }

    vector<int> ans(DEG);
    for(int i=DEG-1;i>=0;i--){
      for(auto& v:flow.G){
        for(auto& e:v){
          if(e.cap) e.cap=INF;
          e.cap+=ed[i][e.to][flow.G[e.to][e.rev].to];
        }
      }
      ans[i]=flow.flow(0,n-1);
    }

    bool f=1;
    for(int i=DEG-1;i>=0;i--){
      if(!ans[i]){
        if(i) continue;
        if(f) cout<<ans[i],f=0;
        continue;
      }
      if(!f) cout<<"+";
      f=0;
      if(!(i&&ans[i]==1)) cout<<ans[i];
      if(i>0) cout<<"x";
      if(i>1) cout<<"^"<<i;
    }
    cout<<endl;
  }
  return 0;
}
