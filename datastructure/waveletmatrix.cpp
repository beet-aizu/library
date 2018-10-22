#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct FullyIndexableDictionary{
  int len,blk;
  vector<int> bit,sum;
  
  FullyIndexableDictionary(){}
  FullyIndexableDictionary(int len)
    :len(len),blk((len+31)>>5),bit(blk,0),sum(blk,0){}
  
  void set(int k){
    bit[k>>5]|=1<<(k&31);
  }

  void build(){
    sum[0]=0;
    for(int i=1;i<blk;i++)
      sum[i]=sum[i-1]+__builtin_popcount(bit[i-1]);
  }

  bool operator[](int k) const{
    return bool((bit[k>>5]>>(k&31))&1);
  }
  
  int rank(int k){
    return sum[k>>5]+__builtin_popcount(bit[k>>5]&((1<<(k&31))-1));
  }
  
  int rank(bool v,int k){
    return (v?rank(k):k-rank(k));
  }

  int select(bool v,int k){
    if(k<0||rank(v,len)<=k) return -1;
    int low=0,high=len;
    while(low+1<high){
      int mid=(low+high)>>1;
      if(rank(v,mid)>=k+1) high=mid;
      else low=mid;
    }
    return high-1;
  }

  int select(bool v,int i,int l){
    return select(v,i+rank(v,l));
  }
};

template<class T,int MAXLOG>
struct WaveletMatrix{
  int len;
  FullyIndexableDictionary mat[MAXLOG];
  int zs[MAXLOG],buff1[MAXLOG],buff2[MAXLOG];
  static const T npos=-1;
  
  int freq_dfs(int d,int l,int r,T val,T a,T b){
    if(l==r) return 0;
    if(d==MAXLOG) return (a<=val&&val<b)?r-l:0;
    T nv=1ULL<<(MAXLOG-d-1)|val;
    T nnv=((1ULL<<(MAXLOG-d-1))-1)|nv;
    if(nnv<a||b<=val) return 0;
    if(a<=val&&nnv<b) return r-l;
    int lc=mat[d].rank(1,l),rc=mat[d].rank(1,r);
    return freq_dfs(d+1,l-lc,r-rc,val,a,b)
      +freq_dfs(d+1,lc+zs[d],rc+zs[d],nv,a,b);
  }
  
  WaveletMatrix(vector<T> data){
    len=data.size();
    vector<T> l(len),r(len);
    for(int dep=0;dep<MAXLOG;dep++){
      mat[dep]=FullyIndexableDictionary(len+1);
      int p=0,q=0;
      for(int i=0;i<len;i++){
        bool k=(data[i]>>(MAXLOG-(dep+1)))&1;
        if(k) r[q++]=data[i],mat[dep].set(i);
        else  l[p++]=data[i];
      }
      zs[dep]=p;
      mat[dep].build();
      swap(l,data);
      for(int i=0;i<q;i++) data[p+i]=r[i];
    }
  }
  
  T access(int k){
    T res=0;
    bool bit;
    for(int dep=0;dep<MAXLOG;dep++){
      bit=mat[dep][k];
      res=(res<<1)|bit;
      k=mat[dep].rank(bit,k)+zs[dep]*dep;
    }
    return res;
  }

  // return the number of v in [0,k)
  int rank(T v,int k){
    int l=0,r=k;
    for(int dep=0;dep<MAXLOG;dep++){
      buff1[dep]=l;buff2[dep]=r;
      bool bit=(v>>(MAXLOG-(dep+1)))&1;
      l=mat[dep].rank(bit,l)+zs[dep]*bit;
      r=mat[dep].rank(bit,r)+zs[dep]*bit;
    }
    return r-l;
  }

  // return the position of k-th v
  int select(T v,int k){
    rank(v,len);
    for(int dep=MAXLOG-1;dep>=0;dep--){
      bool bit=(v>>(MAXLOG-(dep+1)))&1;
      k=mat[dep].select(bit,k,buff1[dep]);
      if(k>=buff2[dep]||k<0) return -1;
      k-=buff1[dep];
    }
    return k;
  }

  int select(T v,int k,int l){
    return select(v,k+rank(v,l));
  }

  // return k-th largest value in [l,r)
  T quantile(int l,int r,int k){
    if(r-l<=k||k<0) return -1;
    T res=0;
    for(int dep=0;dep<MAXLOG;dep++){
      int p=mat[dep].rank(1,l);
      int q=mat[dep].rank(1,r);
      if(q-p>k){
        l=p+zs[dep];
        r=q+zs[dep];
        res|=(1<<(MAXLOG-(dep+1)));
      }else{
        k-=(q-p);
        l-=p;
        r-=q;
      }
    }
    return res;
  }
  
  T rquantile(int l,int r,int k){
    return quantile(l,r,r-l-k-1);
  }
  
  // return number of points in [left, right) * [lower, upper)
  int rangefreq(int left,int right,T lower,T upper){
    return freq_dfs(0,left,right,0,lower,upper);
  }

  pair<int, int> ll(int l,int r,T v){
    int res=0;
    for(int dep=0;dep<MAXLOG;dep++){
      buff1[dep]=l;buff2[dep]=r;
      bool bit=(v>>(MAXLOG-(dep+1)))&1;
      if(bit) res+=r-l+mat[dep].rank(bit,l)-mat[dep].rank(bit,r);
      l=mat[dep].rank(bit,l)+zs[dep]*bit;
      r=mat[dep].rank(bit,r)+zs[dep]*bit;
    }
    return make_pair(res,r-l);    
  }
  
  int lt(int l,int r,T v){
    auto p=ll(l,r,v);
    return p.first;
  }
  
  int le(int l,int r,T v){
    auto p=ll(l,r,v);
    return p.first+p.second;
  }
  
  T succ(int l,int r,T v){
    int k=le(l,r,v);
    return k==r-l?npos:rquantile(l,r,k);
  }

  T pred(int l,int r,T v){
    int k=lt(l,r,v);
    return k?rquantile(l,r,k-1):npos;
  }
};

//END CUT HERE


template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed SPOJ_MKTHNUM(){
  int n,q;
  scanf("%d %d",&n,&q);
  vector<int> v(n);
  for(int i=0;i<n;i++) scanf("%d",&v[i]);
  const int OFS = 1e9+1;
  for(int i=0;i<n;i++) v[i]+=OFS;
  WaveletMatrix<int,32> wm(v);
  for(int i=0;i<q;i++){
    int l,r,k;
    scanf("%d %d %d",&l,&r,&k);
    l--;k--;
    printf("%d\n",wm.rquantile(l,r,k)-OFS);
  }
  return 0;
}
/*
  verified on 2018/08/10
  https://www.spoj.com/problems/MKTHNUM/
*/


signed UNIVERSITYCODESPRINT04_F(){
  int n;
  scanf("%d",&n);
  vector<int> t(n);
  for(int i=0;i<n;i++) scanf("%d",&t[i]);
  
  vector<int> pre(n,-1),nxt(n,n),com(n+1,-1);
  unordered_map<int, int> pos;
  for(int i=0;i<n;i++){
    if(pos.count(t[i])) pre[i]=pos[t[i]];
    pos[t[i]]=i;
  }
  
  pos.clear();
  for(int i=n-1;i>=0;i--){
    if(pos.count(t[i])) nxt[i]=pos[t[i]];
    pos[t[i]]=i;
    com[nxt[i]]=pre[i];
  }
  
  WaveletMatrix<int, 30> wm1(pre),wm2(com);
  
  int q;
  scanf("%d",&q);
  for(int i=0;i<q;i++){
    int A,B,ans;
    scanf("%d %d",&A,&B);
    ans=B-(--A);
    ans-=wm1.rangefreq(A,B,A,B)<<1;
    ans+=wm2.rangefreq(A,B,A,B);
    printf("%d\n",ans);
  }
  
  return 0;
}
/*
  verified on 2018/08/10
  https://www.hackerrank.com/contests/university-codesprint-4/challenges/unique-art/problem
*/

signed ABC106_D(){
  int n,m,q;
  scanf("%d %d %d",&n,&m,&q);
  vector<int> x(m),y(m);
  for(int i=0;i<m;i++) scanf("%d %d",&x[i],&y[i]);
  using P = pair<int, int>;
  vector<P> vp;
  for(int i=0;i<m;i++) vp.emplace_back(x[i],y[i]);
  sort(vp.begin(),vp.end());
  for(int i=0;i<m;i++) tie(x[i],y[i])=vp[i];
 
  WaveletMatrix<int, 10> wm(y);
 
  for(int i=0;i<q;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    int l=lower_bound(x.begin(),x.end(),a)-x.begin();
    int r=upper_bound(x.begin(),x.end(),b)-x.begin();
    printf("%d\n",wm.rangefreq(l,r,a,b+1));
  }
  return 0;
}
/*
  verified on 2018/08/21
  https://beta.atcoder.jp/contests/abc106/tasks/abc106_d
*/

signed AOJ_1549(){
  int n;
  scanf("%d",&n);

  const int OFS = 1e6;
  vector<int> a(n);
  for(int i=0;i<n;i++) scanf("%d",&a[i]),a[i]+=OFS;
  WaveletMatrix<int, 21> wm(a);

  int q;
  scanf("%d",&q);
  for(int i=0;i<q;i++){
    int l,r,d;
    scanf("%d %d %d",&l,&r,&d);
    r++;
    d+=OFS;
    int ans=OFS*2;
    if(wm.rank(d,l)<wm.rank(d,r)) ans=0;
    else{
      int succ=wm.succ(l,r,d);
      if(~succ) chmin(ans,abs(succ-d));
      int pred=wm.pred(l,r,d);
      if(~pred) chmin(ans,abs(pred-d));
    }
    printf("%d\n",ans);
  }
  return 0;
}

/*
  verified on 2018/08/29
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549
*/


signed main(){
  //SPOJ_MKTHNUM();
  //UNIVERSITYCODESPRINT04_F();
  //ABC106_D();
  AOJ_1549();
  return 0;
}
