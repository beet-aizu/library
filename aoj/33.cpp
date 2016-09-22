#include<iostream>
using namespace std;
int main(){
  int n;cin >> n;
  while(n--){
    int r=0,l=0,d;
    bool f=false;
    for(int i=0;i<10;i++){
      cin >> d;
      //cout << d << endl;
      if(r<d){
	if(r<l&&l<d) l=d;
	else r=d;
      }else if(l<d){
	if(l<r&&r<d) r=d;
	else l=d;
      }else{
	f=true;
	break;
      }
      //cout << l << ":" << r << endl;
    }
    if(f) cout << "NO" << endl;
    else cout << "YES" << endl;
  }  
}
