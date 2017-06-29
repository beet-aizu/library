#include<bits/stdc++.h>
using namespace std;
#define int long long
// I will fix it later.

typedef pair<int,int> P;
struct RUP{
  int n;
  vector<P> dat;
  RUP(){}
  RUP(int n_){init(n_);}
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1);
    for(int i=0;i<2*n-1;i++) dat[i].first=-1,dat[i].second=INT_MAX;
  }
  int query(int k){
    k+=n-1;
    P p=dat[k];
    while(k>0){
      k=(k-1)/2;
      p=max(p,dat[k]);
    }
    return p.second;
  }
  void update(int a,int b,P p,int k,int l,int r){
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b) {
      dat[k]=p;
    }else{
      update(a,b,p,k*2+1,l,(l+r)/2);
      update(a,b,p,k*2+2,(l+r)/2,r);
    }
  }
  
  void update(int a,int b,P p){
    update(a,b,p,0,0,n);
  }
};
signed main(){
  int n,q;
  cin>>n>>q;
  RUP rup(n);
  for(int i=0;i<q;i++){
    int f;
    cin>>f;
    if(!f){
      int s,t,x;
      cin>>s>>t>>x;
      rup.update(s,t+1,P(i,x));
    }else{
      int u;
      cin>>u;
      cout<<rup.query(u)<<endl;
    }
  }
  return 0;
}

/*
verified on 2017/02/24
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
*/
