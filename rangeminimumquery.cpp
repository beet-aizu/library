#include<bits/stdc++.h>
using namespace std;
struct RMQ{
  static const int MAX_N = 1 << 17;
  int n,dat[2*MAX_N-1];
  RMQ(){}
  RMQ(int n_){init(n_);}
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++) dat[i]=INT_MAX;
  }
  void update(int k,int a){
    k+=n-1;
    dat[k]=a;
    while(k>0){
      k=(k-1)/2;
      dat[k]=min(dat[k*2+1],dat[k*2+2]);
    }
  }
  int query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return INT_MAX;
    if(a<=l&&r<=b) return dat[k];
    else{
      int vl=query(a,b,k*2+1,l,(l+r)/2);
      int vr=query(a,b,k*2+2,(l+r)/2,r);
      return min(vl,vr);
    }
  }
  int query(int a,int b){
    return query(a,b,0,0,n);
  }
};
int main(){
  int n,q;
  cin>>n>>q;
  RMQ rmq(n);
  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c) cout<<rmq.query(x,y+1)<<endl;
    else rmq.update(x,y);
  }
  return 0;
}
/*
verified on 2017/02/18
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
*/
