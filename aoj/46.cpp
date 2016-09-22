#include<iostream>
using namespace std;
int main(){
  double a=0,i=1<<20,d;
  while(cin >> d) {
    a=max(a,d);
    i=min(i,d);
  }
  cout << a-i << endl;
  return 0;
}
