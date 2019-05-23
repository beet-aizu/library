#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct SuffixArray{ 
  string s;
  vector<int> sa,rev;
  
  SuffixArray(){}
  SuffixArray(const string &S):s(S){
    int n=s.size();
    s.push_back('$');
    sa.resize(n+1);
    iota(sa.begin(),sa.end(),0);
    sort(sa.begin(),sa.end(),
         [&](int a,int b){
           if(s[a]==s[b]) return a>b;
           return s[a]<s[b];
         });
    vector<int> c(n+1,0),r(n+1),cnt(n+1);
    for(int i=0;i<=n;i++) r[i]=s[i];
    for(int len=1;len<=n;len*=2){
      for(int i=0;i<=n;i++){       
        c[sa[i]]=i;
        if(i>0 &&
           r[sa[i-1]]==r[sa[i]] &&
           sa[i-1]+len<=n &&
           r[sa[i-1]+len/2]==r[sa[i]+len/2]) c[sa[i]]=c[sa[i-1]];
      }
      iota(cnt.begin(),cnt.end(),0);
      copy(sa.begin(),sa.end(),r.begin());
      for(int i=0;i<=n;i++){
        int s1=r[i]-len;
        if(s1>=0) sa[cnt[c[s1]]++]=s1;
      }
      c.swap(r);
    }
    rev.resize(n+1);
    for(int i=0;i<=n;i++) rev[sa[i]]=i;    
  }
  int operator[](int i) const{return sa[i];}
  
  bool lt_substr(string &t,int si,int ti){
    int sn=s.size(),tn=t.size();
    while(si<sn&&ti<tn){
      if(s[si]<t[ti]) return 1;
      if(s[si]>t[ti]) return 0;
      si++;ti++;
    }    
    return si==sn&&ti<tn;
  }

  int lower_bound(string& t){
    int l=0,r=s.size();
    while(l+1<r){
      int m=(l+r)>>1;
      if(lt_substr(t,sa[m],0)) l=m;
      else r=m;
    }
    return r;
  }
  
  int upper_bound(string& t){
    t.back()++;
    int res=lower_bound(t);
    t.back()--;
    return res;
  }
  
  // O(|T|*log|S|)
  int count(string& T){
    return upper_bound(T)-lower_bound(T);
  }  
};
//END CUT HERE


template <typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(F f,T ti):f(f),ti(ti){}
  void init(int n_){    
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }
  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  void set_val(int k,T x){
    dat[k+=n]=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);    
  }
  T query(int a,int b){
    T vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }
};

//INSERT ABOVE HERE
signed AOJ_ALDS114D(){
  static char buf[1000001];
  scanf("%s",buf);
  string T(buf);
  SuffixArray sa(T);
  int q;
  scanf("%d",&q);
  while(q--){
    scanf("%s",buf);
    string P(buf);
    printf("%d\n",!!sa.count(P));
  }
  return 0;
}
/*
  verified on 2019/05/23
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D
*/

signed JOI2009HO_A(){  
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,m;
  string s;
  cin>>n>>m>>s;
  SuffixArray sa(s);
  string t="I";
  for(int i=0;i<n;i++) t+="OI";
  
  cout<<sa.count(t)<<endl;
  return 0;
}

signed AOJ_2644(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  string s;
  int m;
  cin>>s>>m;
  SuffixArray sa(s);
  
  using P = pair<int, int>;
  auto f=[](P a,P b){
           return P(max(a.first,b.first),
                    min(a.second,b.second));
         };  
  int n=s.size()+1;
  SegmentTree<P> seg(f,P(-1,n+1));
  
  vector<P> vp;
  for(int i=0;i<n;i++) vp.emplace_back(sa[i],sa[i]);
  seg.build(vp);
  
  for(int i=0;i<m;i++){
    string x,y;cin>>x>>y;
    int lx=sa.lower_bound(x);
    int rx=sa.upper_bound(x);
    int ly=sa.lower_bound(y);
    int ry=sa.upper_bound(y);
    int ans;
    if(rx-lx<=0||ry-ly<=0) ans=0;
    else{
      int a=seg.query(ly,ry).first;
      int b=seg.query(lx,rx).second;
      if(b+(int)x.size()>a+(int)y.size()) ans=0;
      else ans=a-b+y.size();
    }
    cout<<ans<<"\n";
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/05/23
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2644
*/

signed main(){
  //AOJ_ALDS114D();
  //JOI2009HO_A();
  AOJ_2644();
  return 0;
};
