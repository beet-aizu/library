#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int n,i;
  cin >> n;
  while(n!=0){
    int score[101];
    for(i=0;i<n;i++) cin >> score[i];
    sort(score,score+n);
    int sum=0;
    for(i=1;i<n-1;i++) sum+=score[i];
    cout << sum/(n-2) << endl;
    cin >> n;
  }
  
  return 0;
}
