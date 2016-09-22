#include <iostream>
#include <algorithm>

using namespace std;

int main(){

  int n,a,b,count=0,i,j;
  
  cin >> n >> a >> b;
  while(n!=0){
    count = n;
    if(a<b) swap(a,b);
    int ar[1000010]={};
    ar[a]=1;
    ar[b]=1;
    for(i=1;i<=n;i++){
      if(i-a>0)
	if(ar[i-a]==1) ar[i] = 1;
      if(i-b>0)
	if(ar[i-b]==1) ar[i] = 1;
      count -= ar[i];
    }
    cout << count << endl;
    cin >> n >> a >> b;
  }
  
  return 0;
}
