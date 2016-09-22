#include<iostream>
using namespace std;
int main(){
  int a,b,c,i,j,s=60*60*2;
  while(cin >> a >> b >> c,a!=-1){
    i=s-a*60*60-b*60-c;
    if(i/3600>0) cout << "0"<< i/3600 <<":";
    else cout << "00:";
    if((i%3600)/60>9) cout << ((i%3600)/60) << ":";
    else if((i%3600)/60>0) cout << "0" << ((i%3600)/60) << ":";
    else cout << "00:";
    if(i%60>9) cout << i%60 << endl;
    else if(i%60>0) cout << "0" << (i%60) << endl;
    else cout << "00" << endl;
    i*=3;
    if(i/3600>0) cout << "0"<< i/3600 <<":";
    else cout << "00:";
    if((i%3600)/60>9) cout << ((i%3600)/60) << ":";
    else if((i%3600)/60>0) cout << "0" << ((i%3600)/60) << ":";
    else cout << "00:";
    if(i%60>9) cout << i%60 << endl;
    else if(i%60>0) cout << "0" << (i%60) << endl;
    else cout << "00" << endl;
  }
  return 0;
}
