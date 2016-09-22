#include<iostream>
using namespace std;
int main(){
  int e,x,y,z,i,j,k,b,m;
  cin >> e;
  while(e!=0){
    x=0;y=0;z=0;
    m=e;
    for(z=0;z*z*z<=e;z++){
      x=0;y=0;
      b=e-z*z*z;
      while(y*y<=b) y++;
      y--;
      b-=y*y;
      while(x<=b) x++;
      x--;
      m = (x+y+z) < m ?(x+y+z) : m;
    }
    cout << m << endl;
    cin >> e;
  }
  return 0;
}
