#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T> 
struct BIT{
  int n;
  vector<T> bit;
  //1-indexed
  BIT():n(-1){}
  BIT(int n_,T d):n(n_),bit(n_+1,d){}
  
  T sum(int i){
    T s=bit[0];
    for(int x=i;x>0;x-=(x&-x))
      s+=bit[x];
    return s;
  }
  void add(int i,T a){
    if(i==0) return;
    for(int x=i;x<=n;x+=(x&-x))
      bit[x]+=a;
  }
  
  int lower_bound(int w){
    if(w<=0) return 0;
    int x=0,r=1;
    while(r<n) r<<=1;
    for(int k=r;k>0;k>>=1){
      if(x+k<=n&&bit[x+k]<w){
        w-=bit[x+k];
        x+=k;
      }
    }
    return x+1;
  }
  
  T sum0(int i){
    return sum(i+1);
  }
  void add0(int i,T a){
    add(i+1,a);
  }

  T query(int l,int r){
    return sum(r-1)-sum(l-1);
  }

  T query0(int l,int r){
    return sum(r)-sum(l);
  }
};
//END CUT HERE

signed AOJ_DSL2B(){
  int n,q;
  cin>>n>>q;
  BIT<Int> bit(n+100,0);
  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c) cout<<bit.query(x,y+1)<<endl;
    else bit.add(x,y);
  }
  return 0;
}
/*
  verified on 2018/06/07
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp
*/

// lower_bound
signed ARC033_C(){
  int q;
  cin>>q;
  BIT<int> bit(2e5,0);
  while(q--){
    int t,x;
    cin>>t>>x;
    if(t==1) bit.add(x,1);
    if(t==2){
      int k=bit.lower_bound(x);
      bit.add(k,-1);
      cout<<k<<endl;
    }
  }
  return 0;
}
/*
  verified on 2018/06/07
  https://beta.atcoder.jp/contests/arc033/tasks/arc033_3
*/

signed main(){
  //AOJ_DSL2B();
  ARC033_C();
  return 0;
}
