#include<iostream>
#include<limits.h>
using namespace std;
int inf=INT_MAX;
int dat[400004];
int n,q;
void init(int n_){
  n=1;
  while(n < n_) n*=2;
  for(int i=0;i<2*n-1;i++) dat[i]=inf;
}
void update(int k,int a){
  k+=n-1;
  dat[k]=a;
  while(k>0) {
    k=(k-1)/2;
    dat[k]=min(dat[k*2+1],dat[k*2+2]);
  }
}
int query(int a,int b, int k,int l,int r){
  //cout << a<< b<< k<<l<<r <<endl;
  if(r<=a||b<=l) return inf;
  if(a<=l && r <= b) return dat[k];
  else{
    int vl=query(a,b,k*2+1,l,(l+r)/2);
    int vr=query(a,b,k*2+2,(l+r)/2,r);
    //cout << vl << ":" <<vr << endl;
    return min(vl,vr);
  }
}

int find(int x,int y){
  return query(x,y,0,0,n);
}
int main(){
  int n_;
  cin >> n_ >> q;
  init(n_);
  //cout << n <<endl;
  int i,j;
  for(i=0;i<q;i++){
    int com,x,y;
    cin >> com >> x >> y;
    if(com==0) update(x,y);
    else cout << find(x,y+1) << endl;
  }
  return 0;
}
