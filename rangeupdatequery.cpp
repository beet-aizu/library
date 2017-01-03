#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1 << 18;
#define int long long
typedef pair<int,int> P;
int n;
P dat[2*MAX_N-1];
void init(int n_){
  n=1;
  while(n<n_) n*=2;
  for(int i=0;i<2*n-1;i++) dat[i].first=-1,dat[i].second=INT_MAX;
}
int query(int k){
  k+=n-1;
  P p=dat[k];
  //cout<<k<<"/"<<dat[k].second<<endl;
  while(k>0){
    k=(k-1)/2;
    //cout<<k<<"/"<<dat[k].second<<endl;
    p=max(p,dat[k]);
  }
  return p.second;
}

void update(int a,int b,int k,P p,int l,int r){
  if(r<=a||b<=l) return;
  if(a<=l&&r<=b) {
    //cout<<a<<":"<<b<<":"<<k<<":"<<l<<":"<<r<<endl;
     dat[k]=p;
  }else{
    update(a,b,k*2+1,p,l,(l+r)/2);
    update(a,b,k*2+2,p,(l+r)/2,r);
  }
}
signed main(){
  int _n,q;
  cin>>_n>>q;
  init(_n+1);
  for(int i=0;i<q;i++){
    int f;
    cin>>f;
    if(!f){
      int s,t,x;
      cin>>s>>t>>x;
      //cout<<i<<":"<<x<<endl;
      update(s,t+1,0,P(i,x),0,n);
    }else{
      int u;
      cin>>u;
      cout<<query(u)<<endl;
    }
  }
  return 0;
}
