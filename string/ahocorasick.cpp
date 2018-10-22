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

template<int X>
struct AhoCorasick : Trie<X+1>{
  using TRIE = Trie<X+1>;
  using TRIE::TRIE;
  vector<int> cnt;

  void build(bool heavy=true){
    auto &v=TRIE::v;
    int n=v.size();
    cnt.resize(n);
    for(int i=0;i<n;i++) cnt[i]=v[i].idxs.size();
    
    queue<int> q;
    for(int i=0;i<X;i++){
      if(~v[0].nxt[i]){
        v[v[0].nxt[i]].nxt[X]=0;
        q.emplace(v[0].nxt[i]);
      }else{
        v[0].nxt[i]=0;
      }      
    }

    while(!q.empty()){
      auto &x=v[q.front()];
      cnt[q.front()]+=cnt[x.nxt[X]];
      q.pop();
      for(int i=0;i<X;i++){
        if(x.nxt[i]<0) continue;
        int fail=x.nxt[X];
        while(v[fail].nxt[i]<0) fail=v[fail].nxt[X];
        v[x.nxt[i]].nxt[X]=v[fail].nxt[i];
        if(heavy){
          auto &idx=v[x.nxt[i]].idxs;
          auto &idy=v[v[fail].nxt[i]].idxs;
          vector<int> idz;
          set_union(idx.begin(),idx.end(),
                    idy.begin(),idy.end(),
                    back_inserter(idz));
          idx=idz;
        }
        q.emplace(x.nxt[i]);
      }
    }
  }

  vector<int> match(string s,int heavy=true){
    auto &v=TRIE::v;
    vector<int> res(heavy?TRIE::size():1);
    int pos=0;
    for(auto &c:s){
      int k=TRIE::conv(c);
      while(v[pos].nxt[k]<0) pos=v[pos].nxt[X];
      pos=v[pos].nxt[k];
      if(heavy) for(auto &x:v[pos].idxs) res[x]++;
      else res[0]+=cnt[pos];
    }
    return res;
  }

  int move(int pos,char c){
    auto &v=TRIE::v;
    int k=TRIE::conv(c);
    while(v[pos].nxt[k]<0) pos=v[pos].nxt[X];
    pos=v[pos].nxt[k];
    return pos;
  }
  
};

//END CUT HERE

//INSERT ABOVE HERE
template<typename T> void chmin(T &a,T b){if(a>b) a=b;}
template<typename T> void chmax(T &a,T b){if(a<b) a=b;}

signed TENKA12016_C(){
  string s;
  cin>>s;
  int m;
  cin>>m;
  vector<string> p(m);
  for(int i=0;i<m;i++) cin>>p[i];
  
  vector<int> w(m);
  for(int i=0;i<m;i++) cin>>w[i];

  Trie<27>::F f=[](char c){return c-'a';};
  AhoCorasick<26> aho(f);

  for(int i=0;i<m;i++) aho.add(p[i],i);
  aho.build(false);
  
  int n=s.size();
  vector<int> dp(n+1,0);
  int ans=0;
  for(int i=0;i<n;i++){
    chmax(ans,dp[i]);
    int pos=0;
    for(int j=0;j<222&&i+j<n;j++){
      pos=aho.move(pos,s[i+j]);
      if(pos<0) break;
      int k=aho.idx(pos);
      if(~k) chmax(dp[i+j+1],ans+w[k]);
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

signed dp[2][2][501][21][601];
bool used[2][2][501][21][601];
signed AOJ_2257(){
  Int n,m,k;
  while(cin>>n>>m>>k,n){
    memset(dp,0,sizeof(dp));
    memset(used,0,sizeof(used));
    
    vector<string> from(n),to(n);
    for(Int i=0;i<n;i++) cin>>from[i]>>to[i];
    vector<string> season(k);
    for(Int i=0;i<k;i++) cin>>season[i];

    Trie<27>::F f=[](char c){return c-'a';};
    AhoCorasick<26> aho(f);
    for(Int i=0;i<k;i++) aho.add(season[i],i);
    aho.build();
    Int l=aho.v.size();
    
    vector<string> v;
    for(Int i=0;i<n;i++){
      v.emplace_back(from[i]);
      v.emplace_back(to[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    map<string, Int> idx;
    for(Int i=0;i<(Int)v.size();i++) idx[v[i]]=i;

    vector<vector<Int> > G(v.size());
    for(Int i=0;i<n;i++)
      G[idx[from[i]]].emplace_back(idx[to[i]]);

    const Int MOD = 1e9+7;
    using T = tuple<Int, Int, Int, Int, Int>;
    queue<T> q;
    for(Int i=0;i<(Int)v.size();i++){
      dp[0][0][i][0][0]=1;
      q.emplace(0,0,i,0,0);
    }
    while(!q.empty()){
      Int c,d,x,p,pos;
      tie(c,d,x,p,pos)=q.front();q.pop();      
      if(d==m) break;
      Int f=d&1;
      
      //cout<<c<<" "<<d<<" "<<x<<" "<<p<<" "<<pos<<endl;
      //cout<<v[x]<<":"<<dp[c][f][x][p][pos]<<endl;
      
      if(p==(Int)v[x].size()){
        for(Int y:G[x]){
          Int npos=aho.move(pos,v[y][0]);
          if(aho.cnt[npos]>1) continue;
          Int nc=aho.cnt[npos];
          if(c&&nc) continue;
          dp[c||nc][!f][y][1][npos]+=dp[c][f][x][p][pos];
          dp[c||nc][!f][y][1][npos]%=MOD;
          if(!used[c||nc][!f][y][1][npos])
            q.emplace((c||nc),d+1,y,1,npos);
          used[c||nc][!f][y][1][npos]=1;
        }
      }else{
        Int npos=aho.move(pos,v[x][p]);
        Int np=p+1;
        if(aho.cnt[npos]>1) goto END;
        Int nc=aho.cnt[npos];
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
    Int ans=0;
    for(Int i=0;i<(Int)v.size();i++){
      for(Int j=0;j<l;j++){
        ans+=dp[1][m&1][i][v[i].size()][j];
        ans%=MOD;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}

/*
  verified on 2018/05/20
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2257
*/

signed main(){
  //TENKA12016_C();
  AOJ_2257();
  return 0;
}
