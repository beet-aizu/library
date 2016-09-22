#include<iostream>
#include<string>
using namespace std;
int main(){
  int d[]={31,29,31,30,31,30,31,31,30,31,30,31};
  string s[]={"Thursday",
	      "Friday","Saturday","Sunday","Monday","Tuesday","Wednesday",};
  int i,j;
  int a,b;
  cin>>a>>b;
  while(a!=0){
    int o=0;
    for(i=1;i<a;i++) o+=d[i-1];
    o+=b-1;
    //cout << o << endl;
    cout << s[o%7] << endl;
    cin>>a>>b;
  }
  return 0;
}
