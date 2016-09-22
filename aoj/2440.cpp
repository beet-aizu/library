#include <iostream>
#include <string>

using namespace std;

int main(){
  int n,m,i,j,k,s=0;
  string id[256],str;
  cin >> n;
  for(i=0;i<n;i++) cin >> id[i];
  cin >> m;
  for(i=0;i<m;i++){
    cin >> str;
    k=0;
    for(j=0;j<n;j++){
      if(id[j]==str) k=1;
    }
    if(k==0) cout << "Unknown " << str << endl;
    else if(s==0) {
      cout << "Opened by " << str << endl;
      s=1;
    }else{
      cout << "Closed by " << str << endl;
      s=0;
    }
  }
   
  
  return 0;
}
