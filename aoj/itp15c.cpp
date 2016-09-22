#include<iostream>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  while(h!=0){
    int i,j;
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	if((i%2==0&&j%2==0)||(i%2==1&&j%2==1))
	  cout << "#";
	else cout << ".";
      }
      cout << endl;
    }
    cout << endl;
    cin >> h >> w;
  }
  return 0;
}
