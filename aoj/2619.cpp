#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
  int n;
  
  int nums[1001];
  string strs[1001];
  int ds[1001]={};
  int b;
  string str;
  int i,j,k;
  
  cin >> n;
  for(i=0;i<n;i++){
    cin >> nums[i] ;
    cin >> strs[i];
  }
  int d;
  int c=0;
  while(n!=c){
    k=0;d=-1;
    while(k!=n){
      if(ds[k]==0&&d<nums[k]){
	d=nums[k];
	for(j=0;j<d;j++)
	  cout << ".";
	cout << strs[k] << endl;
	ds[k]=1;
	c++;
      }else k++;
    }
  }
}
