#include<iostream>
using namespace std;
int main(){
  int ans=0;
  int n,d;
  cin >> n;
  int i,j,k;
  for(i=0;i<n;i++){
    cin >> d;
    k=1;
    for(j=2;j*j<=d;j++){
      if(d%j==0){
	k=0;
	break;
      }
    }
    ans+=k;
  }
  cout << ans << endl;
  return 0;
}
