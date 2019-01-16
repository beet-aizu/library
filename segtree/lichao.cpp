#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template <typename T, bool isMin>
struct LiChao{
  static constexpr T INF = numeric_limits<T>::max();
  struct Line{
    T a,b;
    Line(T a,T b):a(a),b(b){}
    T get(T x){return a*x+b;}
  };
  
  int n;
  vector<T> pos;
  vector<Line> dat;
  LiChao(vector<T> &pos):pos(pos){init(pos.size());}

  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    while((int)pos.size()<n)
      pos.emplace_back(T(pos.back()+1));
    dat.assign(2*n,Line(0,-INF));
  }

  void addLine(T a,T b){
    if(isMin) a=-a,b=-b;
    Line x(a,b);
    update(1,0,n-1,x);
  }
  
  T query(T x){
    int t=lower_bound(pos.begin(),pos.end(),x)-pos.begin();
    return (isMin?-1:1)*query(1,0,n-1,t);
  }

  inline bool over(Line &a,Line &b,T lb,T ub){
    return a.get(lb)>=b.get(lb)&&a.get(ub)>=b.get(ub);
  }
  
  void update(int k,int l,int r,Line &x){
    T lb=pos[l],ub=pos[r];
    if(over(dat[k],x,lb,ub)) return;
    if(over(x,dat[k],lb,ub)){
      dat[k]=x;
      return;
    }
    int c=(l+r)>>1;
    if(dat[k].get(pos[c])<x.get(pos[c])) swap(dat[k],x);
    if(dat[k].get(lb)<=x.get(lb)) update((k<<1)|0,l,c,x);
    else update((k<<1)|1,c+1,r,x);
  }

  T query(int k,int l,int r,int t){
    T res=dat[k].get(pos[t]);
    if(l==r) return res;
    int c=(l+r)>>1;
    if(t<=c) return max(res,query((k<<1)|0,l,c,t));
    return max(res,query((k<<1)|1,c+1,r,t));
  }  
};
//END CUT HERE


template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
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

signed CSA070_SQUAREDEND(){
  Int n,k;
  scanf("%lld %lld",&n,&k);
  vector<Int> a(n+1,0);
  for(Int i=0;i<n;i++) scanf("%lld",&a[i]);

  if(n==1){
    puts("0");
    return 0;
  }
  
  const Int INF = 1e15;
  auto dp=make_v<Int>(k+1,n+1);
  fill_v(dp,INF);
  dp[0][0]=0;
  
  vector<Int> pos(a);
  sort(pos.begin(),pos.end());
  pos.erase(unique(pos.begin(),pos.end()),pos.end());
  
  vector<LiChao<Int, true> > v;
  for(int i=0;i<k+1;i++) v.emplace_back(pos);
  v[0].addLine(-2*a[0],a[0]*a[0]);
  
  for(Int i=0;i<n;i++){
    for(Int j=0;j<k;j++){
      dp[j+1][i+1]=v[j].query(a[i])+a[i]*a[i];
      v[j+1].addLine(-2*a[i+1],dp[j+1][i+1]+a[i+1]*a[i+1]);
    }
  }
  
  printf("%lld\n",dp[k][n]);
  return 0;
}

/*
  verified on 2019/01/16
  https://csacademy.com/contest/round-70/task/squared-ends/
*/

signed TENKA12016FINAL_E(){
  int n,l;
  scanf("%d %d",&n,&l);
  auto a=make_v<Int>(n,l);
  for(Int i=0;i<n;i++)
    for(Int j=0;j<l;j++)
      scanf("%lld",&a[i][j]);
  
  vector<Int> dp(l,0);
  vector<Int> pos(l,0);
  iota(pos.begin(),pos.end(),0);
  for(Int i=0;i<n;i++){
    LiChao<Int, true> cht(pos);
    for(Int j=0;j<l;j++)
      cht.addLine(-2*j,a[i][j]+j*j);
    for(Int j=0;j<l;j++)
      dp[j]+=j*j+cht.query(j);
  }
  
  printf("%lld\n",*min_element(dp.begin(),dp.end()));
  return 0;
}

/*
  verified on 2019/01/16
  https://beta.atcoder.jp/contests/tenka1-2016-final/tasks/tenka1_2016_final_e
*/

signed COLOPL2018FINAL_C(){
  int n;
  scanf("%d",&n);
  vector<Int> a(n);
  for(Int i=0;i<n;i++) scanf("%lld",&a[i]);
  vector<Int> pos(n,0);
  iota(pos.begin(),pos.end(),0);
  LiChao<Int, true> cht(pos);
  for(Int i=0;i<n;i++) cht.addLine(-2*i,a[i]+i*i);
  for(Int i=0;i<n;i++) printf("%lld\n",cht.query(i)+i*i);
  return 0;
}

/*
  verified on 2019/01/16
  https://beta.atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
*/

signed main(){
  //CSA070_SQUAREDEND();
  //TENKA12016FINAL_E();
  //COLOPL2018FINAL_C();
  return 0;
}
