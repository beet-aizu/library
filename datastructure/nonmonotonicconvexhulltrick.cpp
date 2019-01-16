#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T,bool isMin>
struct NonmonotonicConvexHullTrick {
  using number = double;
  static constexpr number INF = numeric_limits<T>::max();
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

  bool empty() const{
    return hull.empty();
  }

  T query(T x){
    assert(!empty());
    Line q;
    q.val=x;q.q=1;
    iter it=--hull.lower_bound(q);
    if(isMin) return -(it->eval(x));
    return it->eval(x);
  }
} ;
//END CUT HERE

template<typename T1,typename T2> void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE

signed TENKA12016FINAL_E(){
  int n,l;
  scanf("%d %d",&n,&l);
  
  vector<vector<int> > a(n,vector<int>(l));
  for(Int i=0;i<n;i++)
    for(Int j=0;j<l;j++)
      scanf("%d",&a[i][j]);
  
  vector<Int> dp(l,0);
  for(Int i=0;i<n;i++){
    NonmonotonicConvexHullTrick<Int, true> cht;
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
  for(int i=0;i<n;i++) scanf("%lld",&a[i]);
  NonmonotonicConvexHullTrick<Int, true> cht;
  for(Int i=0;i<n;i++) cht.addLine(-2*i,a[i]+i*i);
  for(Int i=0;i<n;i++) printf("%lld\n",cht.query(i)+i*i);
  return 0;
}

/*
  verified on 2019/01/16
  https://beta.atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
*/


signed AOJ_2725(){
  int n,x;
  scanf("%d %d",&n,&x);
  vector<Int> t(n),p(n),f(n);
  for(Int i=0;i<n;i++) scanf("%lld %lld %lld",&t[i],&p[i],&f[i]);

  using T = tuple<Int, Int, Int>;
  vector<T> vt(n);
  for(Int i=0;i<n;i++) vt[i]=T(f[i],p[i],t[i]);
  sort(vt.begin(),vt.end());
  for(Int i=0;i<n;i++) tie(f[i],p[i],t[i])=vt[i];
  
  vector<NonmonotonicConvexHullTrick<Int, false> > vh(x+1);
  
  Int ans=0;
  for(Int i=0;i<n;i++){
    for(Int j=x;j>t[i];j--){
      if(vh[j-t[i]].empty()) continue;
      Int val=vh[j-t[i]].query(f[i])+p[i]-f[i]*f[i];
      vh[j].addLine(2*f[i],val-f[i]*f[i]);      
      chmax(ans,val);
    }
    vh[t[i]].addLine(2*f[i],p[i]-f[i]*f[i]);
    chmax(ans,p[i]); 
  }
  
  printf("%lld\n",ans);
  return 0;
}

/*
  verified on 2019/01/16
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2725
*/

signed main(){
  //TENKA12016FINAL_E();
  //COLOPL2018FINAL_C();
  //AOJ_2725();
  return 0;
}
