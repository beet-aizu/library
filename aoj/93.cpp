#include<iostream>
using namespace std;
int main(){
  int a,b;
  bool fi=true;
  while(cin >> a >> b,a||b){
    if(!fi)cout << endl;
    fi=false;
    bool f=false;
    for(int i=a;i<=b;i++){
      if(i%400==0) {
	cout << i << endl;
	f=true;
      }else if(i%100==0) {
      }else if(i%4==0){
	cout << i << endl;
	f=true;
      }
    }
    if(!f) cout << "NA" << endl;
  }
}
