#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main(){
  int d,i,j,k;
  cin >> d;
  double a[1000]={},b[1000]={};
  for(i=0;i<d;i++) cin >> a[i];
  for(i=0;i<d;i++) cin >> b[i];
  double o1=0,o2=0,o3=0,oe=0;
  for(i=0;i<d;i++){
    o1+=fabs(a[i]-b[i]);
    o2+=fabs(a[i]-b[i])*fabs(a[i]-b[i]);
    o3+=fabs(a[i]-b[i])*fabs(a[i]-b[i])*fabs(a[i]-b[i]);
    oe=max(oe,fabs(a[i]-b[i]));
  }
  printf("%.6f\n",o1);
  printf("%.6f\n",sqrt(o2));
  printf("%.6f\n",pow(o3,1.0/3.0));
  printf("%.6f\n",oe);
  return 0;
}
