#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int d,e;
  while(cin>>d>>e,d||e){
    int i,j,k;
    double m=1000;
    for(i=0;i<=d;i++){
      j=d-i;
      double di=sqrt(i*i+j*j);
      m=min(m,fabs(di-e));
    }
    cout << m << endl;
  }
  return 0;
}
