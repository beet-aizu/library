#include<iostream>
using namespace std;
int main(){
  int n,m=1;cin >> n;
  int d[21]={};
  int a,v;
  while(n--){
    cin >> a >> v;d[a]=v;
    if(d[m]==d[a]&&a<m)m=a;
    if(d[m]<d[a])m=a;
  }
  cout << m << " " << d[m] << endl;
}
