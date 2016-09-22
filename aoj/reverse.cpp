#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	char str[64];
	int i;
	cin >> str;
	for(i=1;i<=strlen(str);i++){
		cout << str[strlen(str)-i];
	}
	cout << endl;
	return 0;
}