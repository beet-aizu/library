#include <iostream>
using namespace std;

int main(){
  int n,y,m,d,o,i,j,k,sum;
  cin >> n;
  for(o=0;o<n;o++){
    cin >> y >> m >> d;
    sum=0;
    i=y;j=m;k=d;
    while(i!=1000){
      sum++;
      k++;
      if(i%3!=0&&j%2==0){
	if(k==20){
	  j++;
	  k=1;
	}
      }else if(k==21) {
	k=1;
	j++;
      }

      if(j==11) {
	j=1;
	i++;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
