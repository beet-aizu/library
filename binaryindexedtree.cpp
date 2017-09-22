#include<bits/stdc++.h>
using namespace std;
#define int long long
//BEGIN CUT HERE
template<typename T> 
struct BIT{
  vector<T> bit;
  int n;
  //1-indexed
  BIT(){init(-1,(T)0);}
  BIT(int n_,T d){init(n_,d);}
  void init(int n_,T d){
    n=n_;
    bit.clear();
    bit.resize(n+1,d);
  }
  T sum(int i){
    T s=0;
    for(int x=i;x>0;x-=(x&-x))
      s+=bit[x];
    return s;
  }
  void add(int i,T a){
    if(i==0) return;
    for(int x=i;x<=n;x+=(x&-x))
      bit[x]+=a;
  }
  T sum0(int i){
    return sum(i+1);
  }
  void add0(int i,T a){
    add(i+1,a);
  }
};
//END CUT HERE

signed main(){
  int n,q;
  cin>>n>>q;
  BIT<int> bit(n+100,0);
  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c) cout<<bit.sum(y)-bit.sum(x-1)<<endl;
    else bit.add(x,y);
  }
  return 0;
}
/*
verified on 2017/09/22
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp
 */
