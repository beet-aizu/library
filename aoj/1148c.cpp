#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct log{
  int t,n,m,s;
  bool operator<(const log&a)const{
    return n==a.n ? (m == a.m? t < a.t : m < a.m) : n<a.n;
  }
};
int main(){
  int nu,me,i,j,k,o,f;
  cin >> nu >> me;
  while(nu!=0||me!=0){
    int r,q;
    cin >> r;
    int t,n,m,s,ts,te;
    vector <log> logs;
    log l;
    for(i=0;i<r;i++){
      cin >> l.t >> l.n >> l.m >> l.s ;
      logs.push_back(l);
    }
    cin >> q;
    sort(logs.begin(),logs.end());
    i=0;

    int a;
    for(a=0;a<q;a++){
      cin >> ts >> te >> m ;
      
      j=0;
      o=0;
      f=0;
      for(i=ts;i<te;i++){
	f=0;
	k=0;
	for(j=0;j<logs.size();j+=2){
	  if(logs[j].m==m&&logs[j].t<=i&&i<logs[j+1].t){
	    f=1;
	  }
	}
	
	o+=f;
      }
      cout << o << endl;
    }
    
    cin >> nu >> me;
  }
  return 0;
}
