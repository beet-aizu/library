#include<iostream>
#include<map>
using namespace std;
typedef pair<int,int> P;
#define F first
#define S second
int n,q;
P d[4*1000005];
void init(int n_){
  n=1;
  while(n<n_) n*=2;
  for(int i=0;i<n-1;i++) {
    d[i].F=0;
    d[i].S=0;
  }
  for(int i=n-1;i<2*n-1;i++) {
    d[i].F=0;
    d[i].S=i-n+1;
  }
}
void update(int k,int a){
  k+=n-1;
  d[k].F+=a;
  while(k>0){
    k=(k-1)/2;
    if(d[k*2+1].F>=d[k*2+2].F) {
      d[k].F=d[k*2+1].F;
      d[k].S=d[k*2+1].S;
    }else{
      d[k].F=d[k*2+2].F;
      d[k].S=d[k*2+2].S;
    }
  }
}
int query(int a,int b,int k,int l,int r){
  if(r<=a || b <= l ) return 0;
  if(a<=l&&r<=b) return d[k].S;
  else{
    int vl=query(a,b,k*2+1,l,(l+r)/2);
    int vr=query(a,b,k*2+2,(l+r)/2,r);
    if(d[vl].F>=d[vr].F) return vl;
    else return vr;
  }
}
int main(){
  int a,b;
  cin >> n >> q;
  init(n);
  for(int i=0;i<q;i++){
    cin >> a >> b;
    a--;
    update(a,b);
    int x=query(0,n,0,0,n);
    cout << x+1 << " " << d[n-1+x].F << endl;
  }
  return 0;
}
