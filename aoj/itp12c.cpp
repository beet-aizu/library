#include <iostream>
using namespace std;

int main(){
	int a,b,c,buf;
	cin >> a >> b >> c;
	if(a>b){
		buf=a;
		a=b;
		b=buf;
	}
	if(b>c){
		buf=b;
		b=c;
		c=buf;
	}
	if(a>b){
		buf=a;
		a=b;
		b=buf;
	}
	cout << a << " "<< b << " " << c << endl;
	
	return 0;
}