#include <iostream>
using namespace std;

int main(){
  int d,i,area;
  while(cin>>d){
    area = 0;
    for(i=0;i<600/d;i++){
      area += i * i * d * d * d;
    }
    cout << area << endl;
  }
  
}
