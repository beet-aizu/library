#include <iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  while(n!=0){
    int s=1,sum=0,e=1,o=0;
    while(e<=n){
      if(sum<n) {
	sum+=e;
	e++;
      }else if(sum==n){
	o++;
	sum+=e;
	e++;
      }else{
	sum-=s;
	s++;
      }
    }
    cout << o << endl;
    cin >> n;
  }
  return 0;
}
