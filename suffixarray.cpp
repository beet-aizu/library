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
    build_sa();
    build_lcp();
    build_rmq();
  }
  void build_sa(){
    sa.clear();
    sa.resize(n+1,0);
    S.push_back('$');
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
    S.pop_back();
  }
  
  // O(|T|*log|S|)
  pair<int,int> count(string& T){
    int sl=S.length(),tl=T.length();
    int a[2],b[2];
    for(int i=0;i<2;i++){
      a[i]=0;
      b[i]=sl;
      while(a[i]+1<b[i]){
	int c=(a[i]+b[i])/2;
	if(S.compare(sa[c],tl,T)<0||
	   (i&&S.compare(sa[c],tl,T)==0)) a[i]=c;
	else b[i]=c;
      }
    }
    if(S.compare(sa[b[0]],tl,T)!=0) return make_pair(0,0);
    if(a[1]<sl&&S.compare(sa[a[1]+1],tl,T)==0) a[1]++;
    if(b[0]> 0&&S.compare(sa[b[0]-1],tl,T)==0) b[0]--;
    return make_pair(b[0],a[1]+1);
  }
  
  bool contains(string& T){
    auto tmp=count(T);
    return tmp.first!=tmp.second;
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
    RMQ(int n_){init(n_);}
    RMQ(int n_,vector<int>& a){init(n_);build(n_,a);}
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
    void update(int k,int a){
      k+=n-1;
      dat[k]=a;
      while(k>0){
	k=(k-1)/2;
	dat[k]=min(dat[k*2+1],dat[k*2+2]);
      }
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
      return query(a,b,0,0,n);
    }
  };
  
  RMQ rmq;
  void build_rmq(){
    rmq.init(n);
    rmq.build(n,lcp);
  }
  
  // O(|T|+log|S|)
  pair<int,int> count2(string& T){
    int a[2],b[2];
    int sl=S.length(),tl=T.length();
    for(int i=0;i<2;i++){
      int p,l,r;
      p=tl;
      a[i]=0;
      b[i]=sl;
      l=getlcp(sa[a[i]],T,0);
      r=getlcp(sa[b[i]],T,0);
      while(a[i]+1<b[i]){
	int c=(a[i]+b[i])/2;
	//cout<<a[i]<<" "<<b[i]<<" "<<c<<endl;
	if(l>=r){
	  int m=rmq.query(a[i],c);
	  if(m<l) b[i]=c,r=m;
	  else{
	    int k=l+getlcp(sa[c],T,l);
	    if(i){
	      if(k==p||S[sa[c]+k]<T[k]) a[i]=c,l=k;
	      else b[i]=c,r=k;
	    }else{
	      if(k==p) b[i]=c,r=k;
	      else if(S[sa[c]+k]<T[k]) a[i]=c,l=k;
	      else b[i]=c,r=k;
	    }
	  }
	}else{
	  int m=rmq.query(c,b[i]);
	  if(m<r) a[i]=c,l=m;
	  else{
	    int k=r+getlcp(sa[c],T,r);
	    if(i){
	      if(k==p||S[sa[c]+k]<T[k]) a[i]=c,l=k;
	      else b[i]=c,r=k;
	    }else{
	      if(k==p) b[i]=c,r=k;
	      else if(S[sa[c]+k]<T[k]) a[i]=c,l=k;
	      else b[i]=c,r=k;
	    }
	  }
	}
      }
    }
   
    if(a[1]<sl&&getlcp(sa[a[1]+1],T,0)==tl) a[1]++;
    if(b[0]> 0&&getlcp(sa[b[0]-1],T,0)==tl) b[0]--;
   
    if(getlcp(sa[b[0]],T,0)!=tl) return make_pair(0,0);

    return make_pair(b[0],a[1]+1);
  }

  bool contains2(string& T){
    auto tmp=count2(T);
    return tmp.first!=tmp.second;
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
    printf("%d\n",sa.contains2(P));
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
char buf[1145141];
signed main(){
  int n;
  scanf("%d",&n);
  int m;
  scanf("%d",&m);
  scanf("%s",buf);
  string s(buf);
  SuffixArray sa(s);
  string t="I";
  for(int i=0;i<n;i++) t=t+"OI";
  auto tmp=sa.count2(t);
  printf("%d\n",tmp.second-tmp.first);
  return 0;
}
//*/
/*
  verified on 2017/10/20
http://joi2009ho.contest.atcoder.jp/tasks/joi2009ho_a
*/
