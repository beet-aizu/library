#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<int> v;
  int i,b;
  int n;
  cin >> n;
  //cout << n;
  for(i=0;i<n;i++) {
    cin >> b;
    v.push_back(b);
  }

  cout << v[3] << endl;
  
  return 0;
}
