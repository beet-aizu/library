#include<iostream>
using namespace std;
int isPrime(int n){
  for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
  return 1;
}
int main(){
  int b;
  /*
  long long x=0;
  for(i=2;i<25;i++){
    x=x*10+1;
    cout << x<<" "<<i<<" "<<(x%i) <<endl; 
    }*/
  cin >> b;
  if(b==0||b==2) cout << 1 << endl;
  else if(b==1) cout << 2 << endl;
  else cout << 0 << endl;
  return 0;
}
