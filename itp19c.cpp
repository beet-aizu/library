#include<iostream>
#include<string>
using namespace std;
int main(){
  int n,i;
  cin >> n;
  string s1,s2;
  int t=0,h=0;
  
  for(i=0;i<n;i++){
    cin >> s1 >> s2;
    if(s1.compare(s2)==0) {
      t++;h++;
    }else if(s1.compare(s2)>0) t+=3;
    else h+=3;
  }
  cout << t << " " << h << endl;
}
