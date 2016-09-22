#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(){

  float x,y;
  int n,count=1,i;
  float size;
  cin >> n;
  while(n!=0){
    size=0;
    vector <float> xs,ys;
    for(i=0;i<n;i++){
      cin >> x >> y;
      xs.push_back(x);
      ys.push_back(y);
    }

    for(i=0;i<n;i++){
      size+=((xs[i]-xs[(i+1)%n])*(ys[i]+ys[(i+1)%n]))/2;
    }
    if(size<0) size*=-1;
    printf("%d %.1f\n",count,size);
    count++;
    cin >> n;
  }
  
  return 0;
}
