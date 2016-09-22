#include<iostream>
#include<vector>
using namespace std;
int main(){
  int w,d;
  cin >> w >> d;
  while(w!=0){
    vector<int> ws;
    vector<int> ds;
    int b,i,j,sum=0;
    for(i=0;i<w;i++) {
      cin >> b;ws.push_back(b);
    }
    for(i=0;i<d;i++) {
      cin >> b;ds.push_back(b);
    }
    for(i=0;i<ws.size();i++) {
      for(j=0;j<ds.size();j++){
	if(ws[i]==ds[j]){
	  sum+=ws[i];
	  //cout << sum;
	  ws.erase(ws.begin()+i);
	  ds.erase(ds.begin()+j);
	  i=-1;
	  j=-1;
	}
      }
    }
    for(i=0;i<ws.size();i++) {
      for(j=0;j<ds.size();j++){
	if(ws[i]==ds[j]){
	  sum+=ws[i];
	  //cout << sum;
	  ws.erase(ws.begin()+i);
	  ds.erase(ds.begin()+j);
	  i=-1;
	  j=-1;
	}
      }
    }
    //cout << sum << endl;
    for(i=0;i<ws.size();i++) {
      sum+=ws[i];
      //cout << ws[i] << endl;
    }
    //cout << sum << endl;
    for(i=0;i<ds.size();i++) {
      sum+=ds[i];
      //cout << ds[i] << endl;
    }
    cout << sum << endl;
    //cout << w << d << endl;;
    cin >> w >> d;
  }

}
