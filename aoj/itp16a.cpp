#include<iostream>
using namespace std;
int main(){
  int n[101];
  int i;
  int num;
  cin >> num;
  for(i=0;i<num;i++) cin >> n[i];
  cout << n[num-1];
  for(i=1;i<num;i++) cout <<" "<< n[num-i-1];
  cout << endl;
  return 0;
}
