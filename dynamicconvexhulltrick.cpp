#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T,T INF,bool isMin>
struct DynamicConvexHullTrick {
  using number = double;
  struct Line {
    T m,b,val;
    number x;
    bool q;
    Line(T m=0,T b=0):m(m),b(b),val(0),x(-INF),q(false){}
    
    T eval(T x) const{return m*x+b;}
    bool parallel(const Line &l) const{return m==l.m;}
    number intersect(const Line &l) const{
      return parallel(l)?number(INF):number(l.b-b)/number(m-l.m);
    }
    bool operator<(const Line &l) const{
      if(l.q) return x<l.val;
      return m<l.m;
    }
  };
  
  set<Line> hull;
  using iter = typename set<Line>::iterator;

  bool cPrev(iter it){return it!=hull.begin();}
  bool cNext(iter it){return it!=hull.end()&&next(it)!=hull.end();}

  bool bad(const Line &l1,const Line &l2,const Line &l3){
    return l1.intersect(l3) <= l1.intersect(l2);
  }
  bool bad(iter it){
    return cPrev(it)&&cNext(it)&&bad(*prev(it),*it,*next(it));
  }

  iter update(iter it){
    if(!cPrev(it)) return it;
    number x=it->intersect(*prev(it));
    Line tmp(*it);
    tmp.x=x;
    it=hull.erase(it);
    return hull.insert(it,tmp);
  }
  
  void addLine(T m,T b){
    if(isMin) m=-m,b=-b;
    Line l(m,b);
    iter it=hull.lower_bound(l);
    if(it!=hull.end()&&l.parallel(*it)){
      if(it->b<b) it=hull.erase(it);
      else return;
    }
    it=hull.insert(it,l);
    if(bad(it)){
      hull.erase(it);
      return;
    }
    while(cPrev(it)&&bad(prev(it))) hull.erase(prev(it));
    while(cNext(it)&&bad(next(it))) hull.erase(next(it));

    it=update(it);
    if(cPrev(it)) update(prev(it));
    if(cNext(it)) update(next(it));
  }

  T query(T x){
    if(hull.empty()){
      if(isMin) return INF;
      return -INF;
    }
    Line q;
    q.val=x;q.q=1;
    iter it=--hull.lower_bound(q);
    if(isMin) return -(it->eval(x));
    return it->eval(x);
  }
  
} ;
//END CUT HERE

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

template<typename T1,typename T2> void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed CSA070_SQUAREDEND(){
  Int n,k;
  scanf("%lld %lld",&n,&k);
  vector<Int> a(n+1,0);
  for(Int i=0;i<n;i++) scanf("%lld",&a[i]);

  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  
  const Int INF = 1e15;
  auto dp=make_v<Int>(k+1,n+1);
  fill_v(dp,INF);
  dp[0][0]=0;
  vector<DynamicConvexHullTrick<Int, INF, true> > v(k+1);
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
  verified on 2018/02/22
  https://csacademy.com/contest/round-70/task/squared-ends/
*/

signed TENKA12016FINAL_E(){
  Int n,l;
  cin>>n>>l;
  auto a=make_v<Int>(n,l);
  for(Int i=0;i<n;i++)
    for(Int j=0;j<l;j++)
      cin>>a[i][j];
  
  vector<Int> dp(l,0);
  const Int INF = 1e16;
  for(Int i=0;i<n;i++){
    DynamicConvexHullTrick<Int,INF,1> cht;
    for(Int j=0;j<l;j++)
      cht.addLine(-2*j,a[i][j]+j*j);
    for(Int j=0;j<l;j++)
      dp[j]+=j*j+cht.query(j);
  }
  
  cout<<*min_element(dp.begin(),dp.end())<<endl;
  return 0;
}

/*
  verified on 2018/02/25
  https://beta.atcoder.jp/contests/tenka1-2016-final/tasks/tenka1_2016_final_e
*/

signed COLOPL2018FINAL_C(){
  Int n;
  cin>>n;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  const Int INF = 1e16;
  DynamicConvexHullTrick<Int,INF,1> cht;
  for(Int i=0;i<n;i++) cht.addLine(-2*i,a[i]+i*i);
  for(Int i=0;i<n;i++) cout<<cht.query(i)+i*i<<endl;
  return 0;
}

/*
  verified on 2018/02/25
  https://beta.atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
*/


signed main(){
  //CSA070_SQUAREDEND();
  //TENKA12016FINAL_E();
  COLOPL2018FINAL_C();
  return 0;
}
