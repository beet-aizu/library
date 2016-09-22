#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
  int a,b;
  char op;
  cin >> a >> op >> b;
  while(op!='?'){
    int c;
    if(op=='+') c=a+b;
    if(op=='-') c=a-b;
    if(op=='*') c=a*b;
    if(op=='/') c=a/b;
    cout << c << endl;
    cin >> a >> op >> b;
  }
  return 0;
}
