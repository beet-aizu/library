#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int n,l,i,j,c,a,b,o;
  int k[6]={};
  int bu[30]={};
  cin >> n >> l;
  while(l!=0){
    c=1;
    bu[0]=n;
    int f=0;
    while(f==0){
      j=1;
      for(i=0;i<l-1;i++) j*=10;
      for(i=0;i<l;i++){
	k[i]=bu[c-1]%(j*10)/j;
	j/=10;
      }
      sort(k,k+l);
      a=0;j=1;
      for(i=0;i<l;i++) {
	a+=k[i]*j;
	j*=10;
      }
      b=0;j=1;
      for(i=0;i<l;i++) {
	b+=k[l-1-i]*j;
	j*=10;
      }
      bu[c]=a-b;
      for(i=0;i<c;i++) {
	if(bu[c]==bu[i]) {
	  f=1;
	  o=i;
	}
      }
      c++;
    }
    cout << o << " " <<  bu[c-1] << " " << c-1-o << endl;
    cin >> n >> l;
  }
  return 0;
}
