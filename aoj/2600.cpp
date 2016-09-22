#include<iostream>
using namespace std;
int main(){
  int n,w,h;
  int i,j,k;
  int mx[100001]={};
  int my[100001]={};
  cin >> n >> w >> h;
  int x,y,r;
  int a,b;
  int f=0,f1=0;
  for(i=0;i<n;i++){
    cin >> x >> y >> r;
    a=x-r;b=x+r;
    if(a<0) a=0;
    if(b>w) b=w;
    fill(mx+a,mx+b,1);
    a=y-r;b=y+r;
    if(a<0) a=0;
    if(b>h) b=h;
    fill(my+a,my+b,1);
    /*
    for(j=x-r;j<=x+r-1;j++){
      if(j<0) j=0;
      if(j>=w) break;
      mx[j]=1;
    }
    for(j=y-r;j<=y+r-1;j++){
      if(j<0) j=0;
      if(j>=h) break;
      my[j]=1;
    }
    */
    f=0;
    for(j=0;j<w;j++){
      if(mx[j]==0) {
	f=1;
      }
    }
    
    if(f==0) {
      cout << "Yes" << endl;
      f1=1;
      break;
    }
    
    f=0;
    for(j=0;j<h;j++){
      if(my[j]==0) {
	f=1;
      }
    }
    
    if(f==0) {
      cout << "Yes" << endl;
      f1=1;
      break;
    }
    
  }
  //cout << f1 << endl;
  if(f1==0){
    f=0;
  for(i=0;i<w;i++){
    //cout << mx[i];
    if(mx[i]==0) {
      f=1;
      //break;
      //cout << i;
    }
  }
  //cout<< endl;
  if(f==0) cout << "Yes" << endl;
  else{
    f=0;
  for(i=0;i<h;i++){
    //cout << my[i];
    if(my[i]==0) {
      f=1;
      //break;
    }
  }
  if(f==0) cout << "Yes" << endl;
  else cout << "No" << endl;
  }
  }
}
