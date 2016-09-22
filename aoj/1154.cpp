#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n,i,j,k,f;
  vector <int> sm;
  for(i=1;i<60000/7+1;i++){
    f=0;
    for(j=0;j<sm.size();j++){
      if((7*i-1)%sm[j]==0) f = 1;  
    }
    if(f==0) sm.push_back(7*i-1);
    f=0;
    for(j=0;j<sm.size();j++){
      if((7*i+1)%sm[j]==0) f = 1;  
    }
    if(f==0) sm.push_back(7*i+1);
  }
  cin >> n;
  while(n!=1){
    cout << n << ":";
    f=0;
    for(i=0;i<sm.size();i++){
      if(n%sm[i]==0) {
	cout << " " << sm[i];
	f=1;
      }
    }
    if(f==0) cout << " " << n;
    cout << endl;
    cin >> n;
  }
  return 0;
}
