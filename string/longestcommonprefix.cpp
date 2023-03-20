#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "suffixarray.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE

template<typename Seq = string>
struct LongestCommonPrefix{
  SuffixArray<Seq> sa;

  vector<int> ht;
  vector< vector<int> > dat;
  LongestCommonPrefix(const Seq &s):sa(s){
    int n=s.size();
    vector<int> lcp(n,0);

    int t=0;
    lcp[0]=0;
    for(int i=0;i<n;i++){
      int j=sa[sa.rev[i]-1];
      if(t>0) t--;
      for(;j+t<n and i+t<n;t++){
        if(s[j+t]!=s[i+t]) break;
      }
      lcp[sa.rev[i]-1]=t;
    }

    int h=1;
    while((1<<h)<n) h++;
    dat.assign(h,vector<int>(n));
    ht.assign(n+1,0);
    for(int j=2;j<=n;j++) ht[j]=ht[j>>1]+1;

    for(int j=0;j<n;j++) dat[0][j]=lcp[j];
    for(int i=1,p=1;i<h;i++,p<<=1)
      for(int j=0;j<n;j++)
        dat[i][j]=min(dat[i-1][j],dat[i-1][min(j+p,n-1)]);
  }

  // a, b are indices for suffix array
  int query(int a,int b){
    assert(a!=b);
    if(a>b) swap(a,b);
    int l=b-a;
    return min(dat[ht[l]][a],dat[ht[l]][b-(1<<ht[l])]);
  }

  // a, b are indices for string
  int lcp(int a,int b){
    return query(sa.rev[a],sa.rev[b]);
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
