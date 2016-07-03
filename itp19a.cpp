#include<iostream>
#include<string>
using namespace std;
int main(){
  string w;
  string t;
  cin >> w;
  int i;
  for(i=0;i<w.size();i++) {
    if('A'<=w[i]&&w[i]<='Z') w[i]+='a'-'A';
  }
  int o=0;
  cin >> t;
  while(t!="END_OF_TEXT"){
  
    for(i=0;i<t.size();i++) {
      if('A'<=t[i]&&t[i]<='Z') t[i]+='a'-'A';
    }
    if(w==t) o++;
    cin >> t;
  }
  cout << o << endl;
}
