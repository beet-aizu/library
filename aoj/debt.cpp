#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	int i,n,x=100000;
	cin >> n;
	for(i=0;i<n;i++){
		x*=1.05;
		if(x%1000!=0) x=(x/1000+1)*1000;
	}
	cout << x << endl;
	return 0;
}