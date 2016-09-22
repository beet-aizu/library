#include<iostream>
using namespace std;
long long o,n;
void rec(int d,int s){
  if(d==4){
    if(n==s) o++;
    return;
  }
  for(int i=0;i<=1000;i++){
    if(s+i<=n) rec(d+1,s+i);
  }
}
int main(){
  while(cin>>n) {
    o=0;
    rec(0,0);
    cout << o << endl;
  }
}
