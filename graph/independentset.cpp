#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
struct IndependentSet{
  int n;
  vector<vector<int> > G;
  IndependentSet(int n):n(n),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  int build(){
    vector<int> deg(n,0);
    for(int i=0;i<n;i++) deg[i]=G[i].size();
    int res=0,cnt=0,alive=n;
    vector<int> used(n,0),dead(n,0);
    function<void(void)> dfs=
      [&](){
        if(cnt+alive<=res) return;        
        int v=-1;
        for(int i=0;i<n;i++){
          if(used[i]||dead[i]) continue;
          if(deg[i]<=1){
            v=i;
            break;
          }
          if(v<0||deg[v]<deg[i]) v=i;
        }       
        if(v<0) return;
                
        if(deg[v]!=1){
          dead[v]=1;
          alive--;
          for(int u:G[v]) deg[u]--;

          dfs();
          
          dead[v]=0;
          alive++;
          for(int u:G[v]) deg[u]++;
        }
        {
          used[v]=1;          
          alive--;
          for(int u:G[v])
            if(0==dead[u]++) alive-=!used[u];
          cnt++;
          chmax(res,cnt);

          dfs();
          
          used[v]=0;          
          alive++;
          for(int u:G[v])
            if(--dead[u]==0) alive+=!used[u];
          cnt--;          
        }
      };
    dfs();
    return res;
  }
};
//END CUT HERE
//INSERT ABOVE HERE
signed CODETHANKSFESTIVAL2017_G(){
  int n,m;
  cin>>n>>m;
  IndependentSet G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.add_edge(a,b);
  }
  cout<<G.build()<<endl;
  return 0;
}
/*
  verified on 2019/02/21
  https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_g
*/

signed CFR533_E(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  int n,m;
  cin>>n>>m;

  IndependentSet G(m);
  map<string, int> rev;

  vector<int> vs;

  using P = pair<int, int>;
  set<P> sp;
  auto add_edge=
    [&](){
      sort(vs.begin(),vs.end());
      vs.erase(unique(vs.begin(),vs.end()),vs.end());
      for(int x:vs){
        for(int y:vs){
          if(x==y) continue;
          if(sp.count(P(x,y))) continue;
          sp.emplace(x,y);
          sp.emplace(y,x);
          G.add_edge(x,y);
        }        
      }
      vs.clear();
    };
  
  for(int i=0;i<n;i++){
    int t;
    cin>>t;
    if(t==1) add_edge();
    if(t==2){
      string s;
      cin>>s;
      if(!rev.count(s)){
        int sz=rev.size();
        rev[s]=sz;
      }
      vs.emplace_back(rev[s]);
    }
  }
  add_edge();

  cout<<G.build()<<endl;
  return 0;
}
/*
  verified on 2019/02/21
  https://codeforces.com/contest/1105/problem/E
*/
signed main(){
  //CODETHANKSFESTIVAL2017_G();
  CFR533_E();
  return 0;
}
