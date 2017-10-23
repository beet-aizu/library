#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
struct SuffixArray{
  int n,k;
  string S;
  vector<int> sa,lcp;
  SuffixArray(){}
  SuffixArray(string& S):S(S){init();}
  void init(){
    n=S.length();
    S.push_back('$');
    build_sa();
    build_lcp();
    build_rmq();
  }
  void build_sa(){
    sa.clear();
    sa.resize(n+1,0);
    iota(sa.begin(),sa.end(),0);
    sort(sa.begin(),sa.end(),
	 [&](int a,int b){
	   if(S[a]==S[b]) return a>b;
	   return S[a]<S[b];
	 });
    vector<int> c(n+1,0),r(n+1),cnt(n+1),s(n+1);
    for(int i=0;i<=n;i++) r[i]=S[i];
    for(int len=1;len<=n;len*=2){
      for(int i=0;i<=n;i++){
	 c[sa[i]]=
	   i>0 &&
	   r[sa[i-1]]==r[sa[i]] &&
	   sa[i-1]+len<=n &&
	   r[sa[i-1]+len/2]==r[sa[i]+len/2] ?
	   c[sa[i-1]]:i;
      }
      iota(cnt.begin(),cnt.end(),0);
      copy(sa.begin(),sa.end(),r.begin());
      for(int i=0;i<=n;i++){
	int s1=r[i]-len;
	if(s1>=0) sa[cnt[c[s1]]++]=s1;
      }
      c.swap(r);
    }
  }
  
  bool lt_substr(string &T,int si=0,int ti=0){
    int sn=S.size(),tn=T.size();
    while(si<sn&&ti<tn){
      if(S[si]<T[ti]) return 1;
      if(S[si]>T[ti]) return 0;
      si++;ti++;
    }
    return si>=sn&&ti<tn;
  }
  
  int lower_bound(string& T){
    int low=0,high=n+1;
    while(low+1<high){
      int mid=(low+high)/2;
      if(lt_substr(T,sa[mid],0)) low=mid;
      else high=mid;
    }
    return high;
  }
  
  int upper_bound(string& T){
    T.back()++;
    int res=lower_bound(T);
    T.back()--;
    return res;
  }
  
  // O(|T|*log|S|)
  int count(string& T){
    return upper_bound(T)-lower_bound(T);
  }
  
  void build_lcp(){
    lcp.clear();
    lcp.resize(n+1,0);
    vector<int> r2(n+1);
    for(int i=0;i<=n;i++) r2[sa[i]]=i;
    int h=0;
    lcp[0]=0;
    for(int i=0;i<n;i++){
      int j=sa[r2[i]-1];
      if(h>0) h--;
      for(;j+h<n&&i+h<n;h++){
	if(S[j+h]!=S[i+h]) break;
      }
      lcp[r2[i]-1]=h;
    }
  }
  
  int getlcp(int p,string &T,int d){
    int i=0;
    int len=min((int)T.length()-d,(int)S.length()-p-d);
    while(i<len&&S[p+d+i]==T[d+i]) i++;
    return i;
  }

  struct RMQ{
    int n;
    vector<int> dat;
    const int def=INT_MAX;
    RMQ(){}
    void init(int n_){
      n=1;
      while(n<n_) n*=2;
      dat.clear();
      dat.resize(2*n-1,def);
    }
    void build(int n_, vector<int>& a){
      for(int i=0;i<n_;i++) dat[i+n-1]=a[i];
      for(int i=n-2;i>=0;i--)
	dat[i]=min(dat[i*2+1],dat[i*2+2]);
    }
    int query(int a,int b,int k,int l,int r){
      if(r<=a||b<=l) return def;
      if(a<=l&&r<=b) return dat[k];
      else{
	int vl=query(a,b,k*2+1,l,(l+r)/2);
	int vr=query(a,b,k*2+2,(l+r)/2,r);
	return min(vl,vr);
      }
    }
    int query(int a,int b){
      return query(max(a,0),b,0,0,n);
    }
  };
  
  RMQ rmq;
  void build_rmq(){
    rmq.init(n);
    rmq.build(n,lcp);
  }

  int lower_bound2(string &T){
    int sl=S.length(),tl=T.length();
    if(lt_substr(T,sa[sl-1],0)) return sl;
    int p=tl;
    int low=0,high=sl-1;
    int l=getlcp(sa[low],T,0);
    int r=getlcp(sa[high],T,0);
    while(low+1<high){
      int mid=(low+high)/2;
      int k;
      if(l>=r){
	int m=rmq.query(low,mid);
	if(m<l){
	  high=mid,r=m;
	  continue;
	}
	k=l+getlcp(sa[mid],T,l);
      }else{
	int m=rmq.query(mid,high);
	if(m<r){
	  low=mid,l=m;
	  continue;
	}
	k=r+getlcp(sa[mid],T,r);
      }
      if(k==p) high=mid,r=k;
      else if(S[sa[mid]+k]<T[k]) low=mid,l=k;
      else high=mid,r=k;
    }
				 
    return high;
  }

  int upper_bound2(string &T){
    T.back()++;
    int res=lower_bound2(T);
    T.back()--;
    return res;
  }
  
  // O(|T|+log|S|)
  int count2(string& T){
    return  upper_bound2(T)-lower_bound2(T);
  }
};
//END CUT HERE


/*//
char buf[1000001];
signed main(){
  scanf("%s",buf);
  string T(buf);
  SuffixArray sa(T);
  int q;
  scanf("%d",&q);
  while(q--){
    scanf("%s",buf);
    string P(buf);
    printf("%d\n",!!sa.count2(P));
    //assert(sa.count(P)==sa.count2(P));
  }
  return 0;
}
//*/
/*
verified on 2017/10/20
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D
*/

//*/
signed main(){
  int n,m;
  string s;
  cin>>n>>m>>s;
  SuffixArray sa(s);
  string t="I";
  for(int i=0;i<n;i++) t+="OI";
  cout<<sa.count(t)<<endl;
  //cout<<sa.count2(t)<<endl;
  return 0;
}
//*/
/*
  verified on 2017/10/20
http://joi2009ho.contest.atcoder.jp/tasks/joi2009ho_a
*/
