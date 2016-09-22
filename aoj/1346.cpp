#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
  string str;
  vector <int> nums;
  vector <int> marks;
  int i,j,k=0,buf;
  long long m=0,n=0,ans;
  vector <int> p;
  int o=0;
  cin >> str >> ans;
  j=0;
  for(i=0;i<str.size();i++){
    if(str[i]=='+') {
      nums.push_back(buf);
      buf=0;
      marks.push_back(1);
    }else if(str[i]=='*'){
      nums.push_back(buf);
      buf=0;
      marks.push_back(2);
      k++;
    }else{
      buf*=10;
      buf+=(str[i]-'0');
    }
  }
  nums.push_back(buf);
  m=nums[0];
  for(i=0;i<marks.size();i++){
    if(marks[i]==1){
      m+=nums[i+1];
    }else{
      m*=nums[i+1];
    }
  }
  i=0;
  while(i<marks.size()){
    if(marks[i]==2){
      nums[i]*=nums[i+1];
      nums.erase(nums.begin()+i+1);
      marks.erase(marks.begin()+i);
    }else{
      i++;
    }
  }
  
  n=nums[0];
  for(i=0;i<marks.size();i++){
    n+=nums[i+1];
    //cout << nums[i+1] << endl;
  }
  

  //cout << n << " " << m << " " << ans << endl;
   
  if(n==ans){
    if(m==ans) cout << "U" <<endl;
    else cout << "M" <<endl;	   
  }else{
    if(m==ans) cout << "L" <<endl;
    else cout << "I" <<endl;	  
  } 
}
