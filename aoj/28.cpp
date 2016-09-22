#include<iostream>
using namespace std;
int main(){
  int i,m=0;
  int d[100]={};
  while(cin >> i) d[i-1]++;
  for(i=0;i<100;i++) m=max(m,d[i]);
  for(i=0;i<100;i++) if(d[i]==m) cout << (i+1) << endl; 
}
