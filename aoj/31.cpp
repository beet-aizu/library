#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    vector<int> v;
    for(int i=10;i>=0;i--){
      if(n>=(1<<i)){
	n-=(1<<i);
	v.push_back(1<<i);
      }
    }
    sort(v.begin(),v.end());
    cout << v[0];
    for(int i=1;i<v.size();i++) cout << " " << v[i];
    cout << endl;
  }
}
