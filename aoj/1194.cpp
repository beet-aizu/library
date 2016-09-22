#include<iostream>
#include<stdio.h>
#include<math.h>
#define EPS (1e-10)
using namespace std;
int main(){
  double r,n;
  cin >> r >> n;
  while(r!=0||n!=0){
    int i,j,k;
    double xr,xl,h;
    double hs[41]={};
    for(i=0;i<n;i++){
      cin >> xr >> xl >> h;
      for(j=xr;j<xl;j++){
	hs[j+20]=max(hs[j+20],h);
      }
    }
    /*
    for(i=0;i<=40;i++) cout << hs[i] ;
    cout << endl;
    */
    double o=0;
    int f=0;
    while(f==0){
      o+=0.0001;
      int w;
      if(o<r){
	w = (int) sqrt((r*r)-(r-o)*(r-o));
	if(sqrt((r*r)-(r-o)*(r-o))-w>=EPS) w+=1;
      }
      else{
	w=r;
      }
      //cout << w << endl;
      for(j=-w;j<0;j++){
	if(hs[j+20]<o-r+sqrt((r*r)-((j+1)*(j+1)))){
	  //cout << w << ":" << o << ":" << hs[j+20]  << ":" <<  j << endl;
	  f=1;
	}
      }
      if(o-hs[20-1]>EPS){
	//cout << w << ":" << o << ":" << hs[20-1]  << endl;
	f=1;
      }
      if(o-hs[20]>EPS){
	//cout << w << ":" << o << ":" << hs[20] << endl;
	f=1;
      }
      for(j=1;j<w;j++){
	if(hs[j+20]<o-r+sqrt((r*r)-(j*j))){
	  //cout << w << ":" << o << ":" << hs[j+20]  << ":" <<  j << endl;
	  f=1;
	}
      }
    }
    
    printf("%.4f\n",o-0.0001);
    cin >> r >> n;
  }

}
