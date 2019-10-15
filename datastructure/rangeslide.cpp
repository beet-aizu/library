#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
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
        while(!deq.empty()&&
              !cmp(vs[deq.back()],vs[r])) deq.pop_back();
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
#ifndef call_from_test
struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;

//INSERT ABOVE HERE
signed YUKI_576(){
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  vector<int> a(n);
  for(int i=0;i<n;i++) a[i]=s[i]-'0';

  using D = double;
  auto check=
    [&](D x)->int{
      vector<D> b(n);
      for(int i=0;i<n;i++) b[i]=a[i]-x;

      vector<D> sm(n*2+1,0);
      for(int i=0;i<n*2;i++)
        sm[i+1]=sm[i]+b[i%n];

      auto cmp=[](D a,D b){return a<b;};
      RangeSlide<D, decltype(cmp)> rs(sm,cmp);
      for(int i=0;i<n;i++)
        rs.add_range(i,i+n-k+1);

      auto res=rs.build();
      for(int i=0;i<n;i++)
        if(sm[n+i]>sm[res[i]]) return 1;
      return 0;
    };

  D L=0,R=1;
  for(int k=0;k<20;k++){
    D M=(L+R)/2;
    if(check(M)) L=M;
    else R=M;
  }
  cout<<L<<endl;
  return 0;
}
/*
  verified on 2019/05/27
  https://yukicoder.me/problems/no/576
*/

signed main(){
  //YUKI_576();
  return 0;
}
#endif
