#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_N = 1 << 17;
int datm[2*MAX_N],data[2*MAX_N],n;
void init(int n_){
  n=1;
  while(n<n_) n*=2;
  for(int i=0;i<n*2;i++) datm[i]=data[i]=0;
}
void add(int a,int b,int x,int k=0,int l=0,int r=n){
  if(r<=a||b<=l) return;
  if(a<=l&&r<=b){
    data[k]+=x;
    return;
  }
  add(a,b,x,k*2+1,l,(l+r)/2);
  add(a,b,x,k*2+2,(l+r)/2,r);
  datm[k]=max(datm[k*2+1]+data[k*2+1],datm[k*2+2]+data[k*2+2]);
}
int query(int a,int b,int k=0,int l=0,int r=n){
  if(r<=a||b<=l) return 0;
  if(a<=l&&r<=b) return datm[k]+data[k];
  int vl=query(a,b,k*2+1,l,(l+r)/2);
  int vr=query(a,b,k*2+2,(l+r)/2,r);
  return max(vl,vr)+data[k];
}
signed main(){
  return 0;
}
