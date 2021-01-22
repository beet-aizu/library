// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2257

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../string/trie.cpp"
#include "../../string/ahocorasick.cpp"
#undef call_from_test

signed dp[2][2][501][21][601];
bool used[2][2][501][21][601];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,k;
  while(cin>>n>>m>>k,n){
    memset(dp,0,sizeof(dp));
    memset(used,0,sizeof(used));

    vector<string> from(n),to(n);
    for(int i=0;i<n;i++) cin>>from[i]>>to[i];
    vector<string> season(k);
    for(int i=0;i<k;i++) cin>>season[i];

    AhoCorasick<26, false> aho('a');
    for(int i=0;i<k;i++) aho.add(season[i],i);
    aho.build();
    int l=aho.size();

    vector<string> v;
    for(int i=0;i<n;i++){
      v.emplace_back(from[i]);
      v.emplace_back(to[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    map<string, int> idx;
    for(int i=0;i<(int)v.size();i++) idx[v[i]]=i;

    vector<vector<int> > G(v.size());
    for(int i=0;i<n;i++)
      G[idx[from[i]]].emplace_back(idx[to[i]]);

    const int MOD = 1e9+7;
    using T = tuple<int, int, int, int, int>;
    queue<T> q;
    for(int i=0;i<(int)v.size();i++){
      dp[0][0][i][0][0]=1;
      q.emplace(0,0,i,0,0);
    }

    while(!q.empty()){
      int c,d,x,p,pos;
      tie(c,d,x,p,pos)=q.front();q.pop();
      if(d==m) break;
      int f=d&1;

      if(p==(int)v[x].size()){
        for(int y:G[x]){
          int npos=aho.move(pos,v[y][0]);
          if(aho.cnt[npos]>1) continue;
          int nc=aho.cnt[npos];
          if(c&&nc) continue;
          dp[c||nc][!f][y][1][npos]+=dp[c][f][x][p][pos];
          dp[c||nc][!f][y][1][npos]%=MOD;
          if(!used[c||nc][!f][y][1][npos])
            q.emplace((c||nc),d+1,y,1,npos);
          used[c||nc][!f][y][1][npos]=1;
        }
      }else{
        int npos=aho.move(pos,v[x][p]);
        int np=p+1;
        if(aho.cnt[npos]>1) goto END;
        int nc=aho.cnt[npos];
        if(c&&nc) goto END;
        dp[c||nc][!f][x][np][npos]+=dp[c][f][x][p][pos];
        dp[c||nc][!f][x][np][npos]%=MOD;
        if(!used[c||nc][!f][x][np][npos])
          q.emplace((c||nc),d+1,x,np,npos);
        used[c||nc][!f][x][np][npos]=1;
      }
    END:
      dp[c][f][x][p][pos]=0;
      used[c][f][x][p][pos]=0;
    }

    int ans=0;
    for(int i=0;i<(int)v.size();i++){
      for(int j=0;j<l;j++){
        ans+=dp[1][m&1][i][v[i].size()][j];
        ans%=MOD;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
