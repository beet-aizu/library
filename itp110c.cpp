#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  while(n!=0){
    int i;
    double s[1000]={},sum=0,a=0;
    for(i=0;i<n;i++){
      cin >> s[i];
      sum+=s[i];
    }
    for(i=0;i<n;i++){
      a+=((sum/n)-s[i])*((sum/n)-s[i])/n;
    }
    printf("%.5f\n",sqrt(a));
    cin >> n;
  }
  
  return 0;
}
