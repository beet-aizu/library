#include<iostream>
#include<sstream>
using namespace std;
int s2d(string buf){
  istringstream iss(buf);
  double x;iss >> x;
  return x;
}
int main(){
  string buf;
  while(cin>>buf){
    int i;
    for(i=0;i<buf.size();i++) if(buf[i]==',') buf[i]=' ';
    stringstream ss(buf);
    double d[12];
    for(i=0;i<12;i++){
      ss >> buf;
      d[i]=s2d(buf);
      //cout << i << ":" << d[i] << endl;
    }
    double p=0;
    for(i=0;i<10;i++) p+=d[i];
    p*=d[10]/(d[10]+d[11]);
    //cout << p << endl;
    int o=0,k=0;
    for(i=0;i<10;i++){
      if(p<=k+d[i]){
	o=i+1;
	break;
      }
      k+=d[i];
    }
    cout << o << endl;
  }
  return 0;
}
