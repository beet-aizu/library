#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
// return sum of top K element (default: maximum)
template<typename T, T identity, typename V=vector<T>,
         typename C1=less<T>, typename C2=greater<T> >
struct PrioritySum{
  size_t num;
  T sum;  
  priority_queue<T, V, C1> pq1;
  priority_queue<T, V, C2> pq2;
  PrioritySum():num(0),sum(identity){}
  PrioritySum(size_t num):num(num),sum(identity){}

  void resolve(){
    assert(pq1.size()+pq2.size()>=num);
    while(pq2.size()<num){
      sum+=pq1.top();
      pq2.emplace(pq1.top());
      pq1.pop();
    }
    while(pq2.size()>num){
      sum-=pq2.top();
      pq1.emplace(pq2.top());
      pq2.pop();
    }
    if(pq1.empty()||pq2.empty()) return;
    while(C2()(pq1.top(),pq2.top())){
      T t1=pq1.top();pq1.pop();
      T t2=pq2.top();pq2.pop();
      sum+=t1;
      sum-=t2;
      pq1.emplace(t2);
      pq2.emplace(t1);
    }
  }

  T query(){resolve();return sum;}
  
  void push(const T &x){pq1.emplace(x);}
  void expand(){num++;}
  void shrink(){assert(num);num--;}
};
template<typename T>
using MaximumSum=PrioritySum<T, T(0), vector<T>, less<T>, greater<T> >;
template<typename T>
using MinimumSum=PrioritySum<T, T(0), vector<T>, greater<T>, less<T> >;

//END CUT HERE

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed ARC074_D(){
  using ll = long long;
  
  int n;
  cin>>n;
  vector<ll> a(3*n);
  for(int i=0;i<3*n;i++) cin>>a[i];

  MaximumSum<ll> ps1(n);
  vector<ll> dp1(3*n);
  for(int i=0;i<3*n;i++){
    if(i>=n) dp1[i]=ps1.query();
    ps1.push(a[i]);
  }
  
  MinimumSum<ll> ps2(n);
  vector<ll> dp2(3*n);
  for(int i=3*n-1;i>=0;i--){
    ps2.push(a[i]);
    if(i<=2*n) dp2[i]=ps2.query();
  }

  ll ans=dp1[n]-dp2[n];  
  for(int i=n;i<=2*n;i++) chmax(ans,dp1[i]-dp2[i]);
  
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/04/09
  https://atcoder.jp/contests/arc074/tasks/arc074_b 
*/

signed main(){
  ARC074_D(); 
  return 0;
}
