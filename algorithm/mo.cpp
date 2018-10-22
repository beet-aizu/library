#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct Mo{
  using F = function<void(int)>;
  vector<int> ls,rs,ord;
  int n,width,nl,nr,ptr;
  vector<bool> flg;
  F expand,shrink;
  
  Mo(int n,int width,F expand,F shrink):
    n(n),width(width),nl(0),nr(0),ptr(0),flg(n,0),
    expand(expand),shrink(shrink){}

  void add(int l,int r){
    ls.emplace_back(l);
    rs.emplace_back(r);
  }

  void input(int q,int offl,int offr){
    for(int i=0;i<q;i++){
      int l,r;
      cin>>l>>r;
      add(l+offl,r+offr);
    }
  }

  void build(){
    ord.resize(ls.size());
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),
         [&](int a,int b){
           if(ls[a]/width!=ls[b]/width) return ls[a]<ls[b];
           return bool((rs[a]<rs[b])^((ls[a]/width)&1));
         });
  }

  int process(){
    if(ptr==(int)ord.size()) return -1;
    const int idx=ord[ptr++];
    while(nl>ls[idx]) calc(--nl);
    while(nr<rs[idx]) calc(nr++);
    while(nl<ls[idx]) calc(nl++);
    while(nr>rs[idx]) calc(--nr);
    return idx;
  }

  inline void calc(int idx){
    flg[idx].flip();
    if(flg[idx]) expand(idx);
    else         shrink(idx);
  }
  
};
//END CUT HERE

#define MOD 1000000007
#define MAX_P 500005
Int fact[MAX_P],inv[MAX_P];

void init(Int mod){
  fact[0]=1;
  for(Int i=1;i<MAX_P;i++)
    fact[i]=(fact[i-1]*i)%mod;

  inv[1]=1;
  for(Int i=2;i<MAX_P;i++)
    inv[i]=inv[mod%i]*(mod-mod/i)%mod;
  
}


template<typename T> 
map<T, int> factorize(T x){
  map<T, int> res;
  for(int i=2;i*i<=x;i++){
    while(x%i==0){
      x/=i;
      res[i]++;
    }
  }
  if(x!=1) res[x]++;
  return res;
}


template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T>
vector<vector<T> > make_v(size_t a,size_t b){
  return vector<vector<T> >(a,make_v<T>(b));
}
template<typename T>
vector<vector<vector<T> > > make_v(size_t a,size_t b,size_t c){
  return vector<vector<vector<T> > > (a,make_v<T>(b,c));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}

//INSERT ABOVE HERE
signed DWANGO2017FINAL_B(){
  Int n,q;
  cin>>n>>q;
  vector<Int> x(n);
  for(int i=0;i<n;i++) cin>>x[i];

  const int RT = 40;
  auto acc=make_v<int>(RT,n+1);
  fill_v(acc,0);
  
  using P = pair<Int, Int>;
  vector<vector<P> > v(n);
  for(int i=0;i<n;i++){
    for(auto p:factorize(x[i])){
      if(p.first<RT) acc[p.first][i+1]+=p.second;
      else v[i].emplace_back(p);
    }
  }

  for(int j=0;j<RT;j++)
    for(int i=0;i<n;i++)
      acc[j][i+1]+=acc[j][i];
  
  Int ans=1;
  vector<Int> cnt(114514,0);

  init(MOD);
  auto expand=[&](int idx){
                for(auto p:v[idx]){
                  (ans*=inv[cnt[p.first]+1])%=MOD;
                  cnt[p.first]+=p.second;
                  (ans*=cnt[p.first]+1)%=MOD;
                }
              };
  auto shrink=[&](int idx){
                for(auto p:v[idx]){
                  (ans*=inv[cnt[p.first]+1])%=MOD;
                  cnt[p.first]-=p.second;
                  (ans*=cnt[p.first]+1)%=MOD;
                }
              };
  Mo mo(n,400,expand,shrink);
  mo.input(q,-1,0);
  mo.build();

  vector<Int> a(q);
  for(int i=0;i<q;i++){
    int k=mo.process();
    a[k]=ans;
    int l=mo.ls[k],r=mo.rs[k];
    for(int j=0;j<RT;j++){
      a[k]*=acc[j][r]-acc[j][l]+1;
      a[k]%=MOD;
    }
  }

  for(int i=0;i<q;i++)
    cout<<a[i]<<endl;
  
  return 0;
}
/*
  verified on 2018/02/02
  https://beta.atcoder.jp/contests/dwacon2017-honsen/tasks/dwango2017final_b
*/


signed main(){
  DWANGO2017FINAL_B();
  return 0;
}
