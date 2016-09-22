#include<iostream>
using namespace std;
int main(){
  int ma[100005]={};
  int n;
  cin >> n;
  int i,j,k;
  int a,b;
  for(i=0;i<n;i++){
    cin >> a >> b;
    for(j=a;j<=b;j++) ma[j]++;
  }
  int m=0;
  for(i=0;i<100005;i++){
    //if(i<10)
    //cout << i <<":" << ma[i]<<endl;
    if(i<=ma[i]+1)
      m=max(m,i-1);
  }
  cout << m << endl;
  return 0;
}
