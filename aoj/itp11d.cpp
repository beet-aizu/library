#include <iostream>
using namespace std;

int main(){
	int s,h,m;
	cin >> s;
	h=s/3600;
	m=(s%3600)/60;
	s=s%60;
	cout << h << ":"<< m << ":" << s << endl;
	return 0;
}