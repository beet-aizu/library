#include<iostream>
using namespace std;
int main(){
  int n,w;
  
  cin >> n >> w;
  int i,j,k;
  int b;
  double o=0.01;
  while(n+w!=0){
    double v[101]={};
    o=0.01;
    int m=0,ma=0;
    for(i=0;i<n;i++) {
      cin >> b;
      v[b/w]++;
      if(ma<b/w) ma=b/w;
      if(m<v[b/w])m=v[b/w];
    }
    //cout << m << " " << ma << endl;
    for(i=0;i<=ma;i++) {
      //cout << (v[i]/m)<<" "<< ((double)(ma-i)/ma) << endl;
      o+=(v[i]/m)*((double)(ma-i)/ma);
      //cout << o << endl;
    }
    cout << o << endl;
    cin >> n >> w;
  }
  return 0;
}
