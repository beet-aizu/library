#include<iostream>
using namespace std;
int main(){
  long long n,o=1,k=3;
  cin >> n;
  while(k<n){
    k*=3;
    o++;
  }
  cout << o << endl;
}
