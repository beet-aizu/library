#include<iostream>
using namespace std;
int main(){
  int q,n;
  cin >> q;
  int i,j,k,l;
  for(i=0;i<q;i++){
    cin >> n;
    int s=0;
    while(n>=10){
      int b = n;
      k=0;
      while(b>=10) {
	b/=10;
	k++;
      }
      b=n;
      n=0;
      for(j=0;j<k;j++){
	int d=10;
	for(l=0;l<j;l++) d*=10;
	if((b/d)*(b%d)>n) n= (b/d)*(b%d);
      }
      
      s++;
    }
    cout << s << endl;
  }
  return 0;
}
