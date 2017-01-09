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
  while(k>0){
    k=(k-1)/2;
    p=max(p,dat[k]);
  }
  return p.second;
}

void update(int a,int b,P p,int k=0,int l=0,int r=n){
  if(r<=a||b<=l) return;
  if(a<=l&&r<=b) {
     dat[k]=p;
  }else{
    update(a,b,p,k*2+1,l,(l+r)/2);
    update(a,b,p,k*2+2,(l+r)/2,r);
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
      update(s,t+1,P(i,x));
    }else{
      int u;
      cin>>u;
      cout<<query(u)<<endl;
    }
  }
  return 0;
}
