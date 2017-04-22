#include<bits/stdc++.h>
using namespace std;
#define int long long
struct BIT{
  vector<int> bit;
  int n;
  //1-indexed
  BIT(){init();}
  BIT(int n):n(n){init();}
  void init(){
    bit.clear();
    bit.resize(n+1,0);
  }
  int sum(int i){
    int s=0;
    while(i>0){
      s+=bit[i];
      i-=i&-i;
    }
    return s;
  }
  void add(int i,int x){
    while(i<=n){
      bit[i]+=x;
      i+=i&-i;
    }
  }
  int sum0(int i){
    return sum(i+1);
  }
  void add0(int i,int x){
    add(i+1,x);
  }
};
signed main(){
  int n,q;
  cin>>n>>q;
  BIT bit(n);
  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c) cout<<bit.sum(y)-bit.sum(x-1)<<endl;
    else bit.add(x,y);
  }
  return 0;
}
/*
verified on 2017/04/22
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp
 */
