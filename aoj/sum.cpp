#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	int a,b,c,d,n,x;
	while(cin >> n){
		x=0;
		for(a=0;a<10;a++)
		for(b=0;b<10;b++)
		for(c=0;c<10;c++)
		for(d=0;d<10;d++)
		if(a+b+c+d==n) x++;
		
		cout << x << endl;
	}
	return 0;
}