#include<iostream>
using namespace std;
int main(){
  int d;
  while(cin >> d,d){
    int i,j,k=5,o=0;
    while(d>=k){
      o+=d/k;
      k*=5;
    }
    cout << o << endl;
  }
}
