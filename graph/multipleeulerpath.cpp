#include<bits/stdc++.h>
using namespace std;
using Int = long long;
using ll = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;};
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;};
//BEGIN CUT HERE
// for simple graph
// (no muliple edge, no self loop)
template<typename Graph>
bool hasMultipleEulerPath(Graph &G){
  int n=G.size();
  vector<int> ind(n,0),outd(n,0),pre(n,-1);
  for(int v=0;v<n;v++)
    for(int u:G[v])
      ind[u]++,outd[v]++,pre[u]=v;

  int st=-1,en=-1;
  for(int i=0;i<n;i++){
    if(ind[i]>=3||outd[i]>=3) return true;
    if(ind[i]<outd[i]) st=i;
    if(ind[i]>outd[i]) en=i;
  }
  if(st<0) return true;

  while(ind[en]==1&&st!=en) en=pre[en];
  if(st==en) return false;

  queue<int> que;
  vector<int> rs(n,0);
  que.emplace(st);
  rs[st]=1;
  while(!que.empty()){
    int v=que.front();que.pop();
    for(int u:G[v]){
      if(u==en||rs[u]) continue;
      rs[u]=1;
      que.emplace(u);
    }
  }
  vector<int> us(n,0);
  que.emplace(en);
  us[en]=1;
  while(!que.empty()){
    int v=que.front();que.pop();
    if(rs[v]) return true;
    for(int u:G[v]){
      if(u==en||us[u]) continue;
      us[u]=1;
      que.emplace(u);
    }
  }
  return false;
}
//END CUT HERE
//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  const int MAX = 52;
  auto idx=[&](char c)->int{
             if(islower(c)) return c-'a';
             assert(isupper(c));
             return c-'A'+26;
           };

  string s;
  while(cin>>s,s!="#"){
    int n=s.size();
    if(n<=2){
      cout<<"No Results"<<endl;
      continue;
    }

    vector< set<int> > G(MAX);
    for(int i=0;i+1<n;i++){
      int x=idx(s[i]);
      int y=idx(s[i+1]);
      G[x].emplace(y);
    }

    vector<int> ind(MAX,0),outd(MAX,0);
    for(int v=0;v<MAX;v++)
      for(int u:G[v]) ind[u]++,outd[v]++;

    int res=0;
    for(int i=0;i<MAX;i++)
      res+=max<int>(ind[i]-outd[i],0);

    int m=accumulate(ind.begin(),ind.end(),0)+1;
    int add=max<int>(res-1,0);
    m+=add;

    if(m<n||add){
      cout<<m<<endl;
      continue;
    }

    vector< vector<int> > H(MAX);
    for(int v=0;v<MAX;v++)
      for(int u:G[v])
        if(v!=u) H[v].emplace_back(u);

    int flg=hasMultipleEulerPath(H);
    cout<<(flg?m:m+1)<<endl;
  }
  return 0;
}
/*
  verified on 2019/06/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2324
*/
