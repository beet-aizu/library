#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template <typename T,bool isMin>
struct ConvexHullTrick {
  using P = pair<T, T>;
  deque<P> L;

  inline T getY(const P &a,const T &x){
    return a.first*x+a.second; 
  }

  inline bool check(const P &a,const P &b,const P &c){
    return (b.first-a.first)*(c.second-b.second)
      >= (b.second-a.second)*(c.first-b.first);
  }
  
  void addLine(T a,T b){
    if(!isMin) a*=-1,b*=-1;
    P line(a,b);
    if(!L.empty()&&L.back().first==a){
      line.second=min(line.second,L.back().second);
      L.pop_back();
    }
    while(L.size()>=2&&check(L[L.size()-2],L[L.size()-1],line)) L.pop_back();
    L.emplace_back(line);    
  }

  bool empty() const{
    return L.empty();
  }
  
  T query(T x){
    assert(!empty());
    int low=-1,high=L.size()-1;
    while(low+1<high){
      int mid=(low+high)>>1;
      if(getY(L[mid],x)>=getY(L[mid+1],x)) low=mid;
      else high=mid;
    }
    return (!isMin?-1:1)*getY(L[high],x);
  }
  
  T queryMonotone(T x){
    assert(!empty());
    while(L.size()>=2&&getY(L[0],x)>=getY(L[1],x)) L.pop_front();
    return (!isMin?-1:1)*getY(L[0],x);
  }
};
//END CUT HERE
template<typename T1,typename T2> void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed TENKA12016FINAL_E(){
  int n,l;
  scanf("%d %d",&n,&l);
  vector<vector<int> > a(n,vector<int>(l));
  for(int i=0;i<n;i++)
    for(int j=0;j<l;j++)
      scanf("%d",&a[i][j]);
  
  vector<Int> dp(l,0);
  
  for(int i=0;i<n;i++){
    ConvexHullTrick<Int, true> cht;
    for(Int j=0;j<l;j++)
      cht.addLine(-2*j,a[i][j]+j*j);
    for(Int j=0;j<l;j++)
      dp[j]+=j*j+cht.queryMonotone(j);
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
  ConvexHullTrick<Int, true> cht;
  for(Int i=0;i<n;i++) cht.addLine(-2*i,a[i]+i*i);
  for(Int i=0;i<n;i++) printf("%lld\n",cht.queryMonotone(i)+i*i);
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
  
  vector<ConvexHullTrick<Int, false> > vh(x+1);
  
  Int ans=0;
  for(Int i=0;i<n;i++){
    for(Int j=x;j>t[i];j--){
      if(vh[j-t[i]].empty()) continue;
      Int val=vh[j-t[i]].queryMonotone(f[i])+p[i]-f[i]*f[i];
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
