#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template <typename T>
struct ConvexHullTrick {
  using P = pair<T, T>;
  deque<P> L;
  int isdec;

  ConvexHullTrick():isdec(-1){}

  inline T getY(const P &a,const T &x){
    return a.first*x+a.second; 
  }

  inline bool check(const P &a,const P &b,const P &c){
    return (b.first-a.first)*(c.second-b.second)
      >= (b.second-a.second)*(c.first-b.first);
  }

  inline bool empty(){return L.empty();}

  void add(T a,T b){
    P line(a,b);
    if(isdec==-1&&!L.empty()){
      if(a<L[0].first) isdec=1;
      else if(a>L[0].first) isdec=0;
    }
    if(isdec){
      if(!L.empty()&&L.back().first==a){
	line.second=min(line.second,L.back().second);
	L.pop_back();
      }
      while(L.size()>=2&&check(*prev(L.end(),2),L.back(),line)) L.pop_back();
      L.emplace_back(line);
    }else{
      if(!L.empty()&&L.front().first==a){
	line.second=min(line.second,L.front().second);
	L.pop_front();
      }
       while(L.size()>=2&&check(L[0],L[1],line)) L.pop_front();
      L.emplace_front(line);
    }
  }

  T get(T x){
    int low=-1,high=L.size()-1;
    while(low+1<high){
      int mid=(low+high)>>1;
      if(getY(L[mid],x)>=getY(L[mid+1],x)) low=mid;
      else high=mid;
    }
    return getY(L[high],x);
  }
  
  T getMonotone(T x){
    while(L.size()>=2&&getY(L[0],x)>=getY(L[1],x)) L.pop_front();
    return getY(L[0],x);
  }
  
};
//END CUT HERE
signed LiveArchive_5097(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using P = pair<Int, Int>;
  Int n,k;
  while(cin>>n>>k){
    vector<P> v(n);
    for(Int i=0;i<n;i++){
      Int w,h;
      cin>>w>>h;
      v[i]=P(h,w);
    }
    sort(v.rbegin(),v.rend());
    {
      auto u=v;
      v.clear();
      Int w=0;
      for(Int i=0;i<n;i++){
	if(u[i].second>w){
	  v.push_back(u[i]);
	  w=u[i].second;
	}
      }
      n=v.size();
    }
    ConvexHullTrick<Int> dp;
    dp.add(v[0].first,0);
    Int ans=1LL<<55;
    for(int i=0;i<k;i++){
      ConvexHullTrick<Int> nx;
      for(int j=0;j<n;j++){
	Int x=dp.getMonotone(v[j].second);
	if(j+1==n) ans=min(ans,x);
	else nx.add(v[j+1].first,x);
      }
      swap(dp,nx);
    }
    cout<<ans<<endl;
  }
  return 0;
}
/*
  verified on 2017/12/12
  http://rhodon.u-aizu.ac.jp:8080/arena/submission_log.jsp?no=3794&runID=2326224
*/


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
signed TENKA12016FINAL_E(){
  Int n,l;
  cin>>n>>l;
  auto a=make_v<Int>(n,l);
  for(Int i=0;i<n;i++)
    for(Int j=0;j<l;j++)
      cin>>a[i][j];
  
  vector<Int> dp(l,0);
  
  for(Int i=0;i<n;i++){
    ConvexHullTrick<Int> cht;
    for(Int j=0;j<l;j++)
      cht.add(-2*j,a[i][j]+j*j);
    for(Int j=0;j<l;j++)
      dp[j]+=j*j+cht.get(j);
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
  ConvexHullTrick<Int> cht;
  for(Int i=0;i<n;i++) cht.add(-2*i,a[i]+i*i);
  for(Int i=0;i<n;i++) cout<<cht.get(i)+i*i<<endl;
  return 0;
}

/*
  verified on 2018/02/25
  https://beta.atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
*/



signed main(){
  //LiveArchive_5097();
  //TENKA12016FINAL_E();
  COLOPL2018FINAL_C();
  return 0;
}
