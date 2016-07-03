#include<iostream>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  while(h!=0){
    int i,j;
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	cout << "#";
      }
      cout << endl;
    }
    cout << endl;
    cin >> h >> w;
  }
  return 0;
}
