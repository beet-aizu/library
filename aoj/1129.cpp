#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int n,r,i,j,p,c;
  cin >> n >> r;
  while(n!=0&&r!=0){
    vector <int> cards;
    for(i=0;i<n;i++){
      cards.push_back(i+1);
    }
    for(i=0;i<r;i++){
      cin >> p >> c;
      for(j=0;j<c;j++){
	cards.push_back(cards[n-p-c+1]);
	cards.erase(cards.begin()+n-p-c+1);
      }
      //for(j=0;j<n;j++) cout << j+1 << ":" << cards[j] << endl; 
    }
    
    cout << cards[n-1] << endl;
    
    cin >> n >> r;
  }
  
  return 0;
}
