#include<iostream>
using namespace std;
int main(){
  int a,b;
  while(cin>>a>>b,a||b){
    if(a<b) swap(a,b);
    cout <<b<<" " << a << endl;
  }
  return 0;
}
