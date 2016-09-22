#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n,m,k,i,j;
  cin >> n >> k >> m;
  while(n+k+m!=0){
    int o=0;
    vector<int> v;
    for(i=1;i<=n;i++) v.push_back(i);
    int a=0,b=m-1,c;
    while(v.size()!=1){
      //cout << v[b] << endl;
      v.erase(v.begin()+b);
      b+=k-1;
      b=b%v.size();
    }
    cout << v[0] << endl;
    cin >> n >> k >> m;
  }
}
