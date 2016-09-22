#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;cin>>n;
  int i,j,k;
  vector<int> v;
  for(i=0;i<n;i++){
    cin >> k;
    v.push_back(k);
  }
  for(j=0;j<n;j++) cout << v[j] << (j==n-1?'\n':' ');
  for(i=1;i<n;i++){
    for(j=0;j<i;j++){
      if(v[j]>v[i]){
	k=v[i];
	v.erase(v.begin()+i);
	v.insert(v.begin()+j,k);
	break;
      }
    }
    for(j=0;j<n;j++) cout << v[j] << (j==n-1?'\n':' ');
  }
  return 0;
}
