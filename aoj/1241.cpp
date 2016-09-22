#include<iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  while(n!=0){
    int a,b,c,d;
    int i;
    int o=0;
    for(a=0;a*a<=n;a++){
      for(b=a;a*a+b*b<=n;b++){
	for(c=b;a*a+b*b+c*c<=n;c++){
	  for(d=c;a*a+b*b+c*c+d*d<=n;d++){
	    if(n==a*a+b*b+c*c+d*d) o++;
	  }
	}
      }
    }
    cout << o << endl;
    cin >> n;
  }
}
