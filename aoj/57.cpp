#include<iostream>
using namespace std;
int main(){
  int i,n,d[10005]={};
  d[0]=1;
  for(i=0;i<10000;i++) d[i+1]=d[i]+i+1;
  while(cin>>n)
    cout << d[n] << endl;
  return 0;
}
