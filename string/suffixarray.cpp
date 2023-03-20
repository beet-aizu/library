#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Seq = string>
struct SuffixArray{
  const Seq s;
  vector<int> sa,rev;

  SuffixArray(const Seq &s_):s(s_){

    int n=s.size();
    auto cmp=[&](int a,int b){
      if(a==b) return false;
      if(a==n) return true;
      if(b==n) return false;
      if(s[a]==s[b]) return a>b;
      return s[a]<s[b];
    };

    sa.resize(n+1);
    iota(sa.begin(),sa.end(),0);
    sort(sa.begin(),sa.end(),cmp);

    vector<int> rs(n+1);
    {
      Seq t(s);
      sort(t.begin(),t.end());
      t.erase(unique(t.begin(),t.end()),t.end());
      for(int i=0;i<n;i++)
        rs[i]=std::lower_bound(t.begin(),t.end(),s[i])-t.begin();
      rs[n]=0;
    }

    for(int len=1;len<=n;len*=2){
      vector<int> cs(n+1);
      for(int i=0;i<=n;i++){
        cs[sa[i]]=i;
        if(i==0) continue;
        if(rs[sa[i-1]]!=rs[sa[i]]) continue;
        if(sa[i-1]+len>=n) continue;
        if(rs[sa[i-1]+len/2]!=rs[sa[i]+len/2]) continue;
        cs[sa[i]]=cs[sa[i-1]];
      }
      vector<int> cnt(n+1);
      iota(cnt.begin(),cnt.end(),0);
      copy(sa.begin(),sa.end(),rs.begin());
      for(int i=0;i<=n;i++){
        int s1=rs[i]-len;
        if(s1>=0) sa[cnt[cs[s1]]++]=s1;
      }
      cs.swap(rs);
    }
    rev.resize(n+1);
    for(int i=0;i<=n;i++) rev[sa[i]]=i;
  }

  int operator[](int i) const{return sa[i];}

  bool lt_substr(const Seq &t,int si,int ti){
    int sn=s.size(),tn=t.size();
    while(si<sn and ti<tn){
      if(s[si]<t[ti]) return 1;
      if(s[si]>t[ti]) return 0;
      si++;ti++;
    }
    return si==sn and ti<tn;
  }

  int lower_bound(Seq t){
    int l=0,r=s.size()+1;
    while(l+1<r){
      int m=(l+r)>>1;
      if(lt_substr(t,sa[m],0)) l=m;
      else r=m;
    }
    return r;
  }

  int upper_bound(Seq t){
    t.back()++;
    int res=lower_bound(t);
    t.back()--;
    return res;
  }

  // O(|t| \log|s|)
  int count(Seq t){
    return upper_bound(t)-lower_bound(t);
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  vector<int> vs({1, 2, 3, 1, 2, 1});
  SuffixArray sa(vs);
  for(int i=0;i<=(int)vs.size();i++) cout<<sa[i]<<endl;

  cout<<sa.count({1})<<endl;
  cout<<sa.count({1, 2})<<endl;
  cout<<sa.count({1, 2, 3})<<endl;
  cout<<sa.count({1, 2, 3, 4})<<endl;
  return 0;
}
#endif
