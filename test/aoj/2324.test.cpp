#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2324"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/multipleeuleriantrail.cpp"
#undef call_from_test

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
        H[v].emplace_back(u);

    int flg=hasMultipleEulerianTrail(H);
    cout<<(flg?m:m+1)<<endl;
  }
  return 0;
}
