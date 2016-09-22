#include<iostream>
using namespace std;
int main(){
  int n,m,p,o,i,j,k,b,sum;
  int card;
  cin >> n >> m >> p;
  while(n!=0){
    sum=0;
    for(i=0;i<n;i++){
      if(m-1==i){
	cin >> card;
	sum+=card;
      }else{
	cin >> b;
	sum+=b;
      }
    }
    if(card==0) cout << 0 << endl;
    else cout << ((100-p)*sum/card) <<endl;
    cin >> n >> m >> p;
  }
  
  return 0;
}
