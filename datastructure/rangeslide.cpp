#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//BEGIN CUT HERE
template<typename T, typename F>
struct RangeSlide{
  vector<size_t> ls,rs;
  vector<T> vs;
  F cmp;
  RangeSlide(vector<T> vs,F cmp):vs(vs),cmp(cmp){}

  void add_range(size_t l,size_t r){
    ls.emplace_back(l);
    rs.emplace_back(r);
  }
  
  vector<size_t> build(){
    deque<size_t> deq;
    vector<size_t> res;
    for(size_t i=0,l=0,r=0;i<ls.size();i++){
      if(r<=ls[i]){
        deq.clear();
        l=r=ls[i];
      }
      while(r<rs[i]){
        while(!deq.empty()&&!cmp(vs[deq.back()],vs[r])) deq.pop_back();
        deq.emplace_back(r++);
      }
      while(l<ls[i]){
        if(deq.front()==l++) deq.pop_front();
      }
      res.emplace_back(deq.front());
    }
    return res;
  }
};
//END CUT HERE

template<typename T>
vector<T> compress(vector<T> v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}

//INSERT ABOVE HERE
signed main(){
  Int n,d;
  cin>>n>>d;
  vector<Int> xs(n),ys(n);
  for(Int i=0;i<n;i++) cin>>xs[i]>>ys[i];
  if(n==1){
    cout<<(xs[0]<=d?ys[0]:0)<<endl;
    return 0;
  }
  
  Int h=n/2;
  using P = pair<Int, Int>;
  auto calc=
    [&](Int a,Int b){
      vector<P> res;
      function<void(Int, Int, Int)> dfs=
        [&](Int k,Int s,Int t){
          if(k==b){
            res.emplace_back(s,t);
            return;
          }
          dfs(k+1,s,t);
          dfs(k+1,s+xs[k],t+ys[k]);
          dfs(k+1,s-xs[k],t-ys[k]);
        };
      dfs(a,0,0);
      sort(res.begin(),res.end());
      return res;
    };
  auto v1=calc(0,h);
  auto v2=calc(h,n);
  reverse(v2.begin(),v2.end());
  
  const Int INF = 1e17;
  vector<Int> vs;
  for(auto p:v1) vs.emplace_back(p.first);
  vs.emplace_back(-INF);
  vs.emplace_back(+INF);
  vs=compress(vs);

  vector<Int> ws(vs.size(),-INF);
  {
    Int k=0;
    for(auto p:v1){
      while(vs[k]<p.first) k++;
      chmax(ws[k],p.second);
    }
  }
  v1.clear();
  
  auto cmp=[](Int a,Int b){return a>b;};
  RangeSlide<Int, decltype(cmp)> slide(ws,cmp);  
  vector<Int> ks;

  {
    Int l=0,r=0;
    for(auto p:v2){
      Int x=p.first,k=p.second;
      while(l<(Int)vs.size()&&vs[l]< -x-d) l++;
      while(r<(Int)vs.size()&&vs[r]<=-x+d) r++;
      if(l==r) continue;
      slide.add_range(l,r);
      ks.emplace_back(k);
    }
  }
  vs.clear();
  v2.clear();
  
  auto res=slide.build();
  
  Int ans=0;
  for(Int i=0;i<(Int)res.size();i++) chmax(ans,ws[res[i]]+ks[i]);
  cout<<ans<<endl;
  return 0;
}
