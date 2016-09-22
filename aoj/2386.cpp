#include<iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  int ma[105][105]={{}};
  int i,j;
  long long o=0;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cin >> ma[i][j];
    }
  }
  for(i=0;i<n;i++){
    for(j=i;j<n;j++){
      o+=min(ma[i][j],ma[j][i]);
    }
  }
  cout << o << endl;
}
