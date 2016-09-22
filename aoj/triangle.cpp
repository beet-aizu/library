#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a,b,s,i,n;
	while(cin >> a >> b){
			
	n=0;
	s=a+b;
	while(s!=0){
	s/=10;
	n++;
	}
	cout << n << endl;
	}
	return 0;
}