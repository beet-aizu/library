#include <iostream>
using namespace std;

int main(){
	int x,y,w,h,r;
	cin >> w >> h >> x >> y >> r;
	
	if((x<=w-r)&&(x>=r)&&(y<=h-r)&&(y>=r )) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}