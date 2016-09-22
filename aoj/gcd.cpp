#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long a,b,x,y,g,l,buf;
	while(cin >> a >>b){
		if(a>b){
			x=a;
			y=b;
		}else{
			x=b;
			y=a;
		}
		while(x%y!=0){
			buf=x;
			x=y;
			y=buf%y;
		}
		cout << y << " " << (a*b/y) << endl;
	}
	return 0;
}