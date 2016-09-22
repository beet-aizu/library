#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int b,i;
  vector <int> v;
  for(i=0;i<5;i++) {
    cin >> b;
    v.push_back(b);
  }
  sort(v.begin(),v.end(),greater<int>());
  cout << v[0];
  for(i=1;i<5;i++) cout << " " << v[i];
  cout << endl;
}
