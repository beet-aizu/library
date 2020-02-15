#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct AbsoluteSum{
  multiset<T> lp,rp;
  T sum;
  AbsoluteSum():sum(0){}
  T insert(T x){
    if(lp.empty()){
      lp.emplace(x);
      rp.emplace(x);
      return T(0);
    }
    auto p=interval();
    lp.emplace(x);
    rp.emplace(x);
    if(p.first<=x&&x<=p.second) return T(0);
    if(*lp.rbegin()>*rp.begin()){
      T a=*lp.rbegin();
      T b=*rp.begin();
      lp.erase(lp.find(a));
      rp.erase(rp.find(b));
      rp.emplace(a);
      lp.emplace(b);
    }
    T res=min(abs(p.first-x),abs(p.second-x));
    sum+=res;
    return res;
  }

  T erase(T x){
    assert(lp.count(x)+rp.count(x)>=2);
    if(lp.count(x)&&rp.count(x)){
      lp.erase(lp.find(x));
      rp.erase(rp.find(x));
      return T(0);
    }
    if(lp.count(x)){
      lp.erase(lp.find(x));
      lp.erase(lp.find(x));
      lp.emplace(*rp.begin());
      rp.erase(rp.begin());
    }else{
      rp.erase(rp.find(x));
      rp.erase(rp.find(x));
      rp.emplace(*lp.rbegin());
      lp.erase(lp.rbegin().base());
    }
    auto p=interval();
    if(p.first<=x&&x<=p.second) return T(0);
    T res=min(abs(p.first-x),abs(p.second-x));
    sum-=res;
    return res;
  }

  pair<T, T> interval(){
    assert(!lp.empty());
    return make_pair(*lp.rbegin(),*rp.begin());
  }

  T value(){return sum;}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE

// test interval()
signed ABC127_F(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int q;
  cin>>q;
  using ll = long long;
  AbsoluteSum<ll> as;
  ll sum=0;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==1){
      ll a,b;
      cin>>a>>b;
      as.insert(a);
      sum+=b;
    }
    if(t==2){
      cout<<as.interval().first<<" "<<sum+as.value()<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/19
  https://atcoder.jp/contests/abc127/tasks/abc127_f
*/

signed main(){
  //ABC127_F();
  return 0;
}
#endif
