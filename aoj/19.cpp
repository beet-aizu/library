#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n,i;
  cin >> n;
  long long o=1;
  for(i=1;i<=n;i++) o*=i;
  cout << o << endl;
}
