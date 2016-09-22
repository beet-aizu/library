#include <iostream>
using namespace std;

int main(){
  int stones[51];
  int n,p,i,j,stone;
  cin >> n >> p;
  while(n!=0||p!=0){
    for(i=0;i<51;i++) stones[i]=0;
    i=0;
    stone=p-1;
    stones[0]=1;
    while(stones[i]!=p){
      i=(i+1)%n;
      if(stone > 0) {
	stones[i]++;
	stone--;
      }else if(stones[i]!=0){
	stone+=stones[i];
	stones[i]=0;
      }
    }
    cout << i << endl;
    cin >> n >> p;
  }
}
