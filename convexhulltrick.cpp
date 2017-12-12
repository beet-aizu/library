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
signed main(){
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
