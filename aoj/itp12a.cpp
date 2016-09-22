#include <iostream>
using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	cout << "a ";
	if(a<b) cout << "< ";
	if(a==b) cout << "== ";
	if(a>b) cout << "> ";
	cout << "b" << endl;
	
	
	return 0;
}