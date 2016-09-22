#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n,m;
  while(cin>>n>>m,n||m){
    int i,j,k;
    vector<int> v;
    for(i=1;i<=n;i++) v.push_back(i);
    int p=n-1;
    while(v.size()>1){
      p=(p+m)%v.size();
      //cout << v[p] << endl;
      v.erase(v.begin()+p);
      p=(v.size()+p-1)%v.size();
    }
    cout << v[0] << endl;
  }
  return 0;
}
