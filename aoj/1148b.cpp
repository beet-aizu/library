#include<iostream>
#include<vector>
using namespace std;
struct start{
  int t,n,m;
  bool operator<(const log&a)const{
    return n==a.n ? (m == a.m? t < a.t : m < a.m) : n<a.n;
  }
};
struct end{
  int t,n,m;
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
    vector <start> starts;
    vector <end> ends;
    start st;
    end ed;
    for(i=0;i<r;i++){
      cin >> t >> n >> m >> s ;
      if(s==0){
	st.t=t;st.n=n;st.m=m;
	starts.push_back(st);
      }else{
	ed.t=t;ed.n=n;ed.m=m;
	ends.push_back(en);
      }
    }
    cin >> q;
    sort(logs.begin(),logs.end());
    i=0;
    for(i=0;i<logs.size();i++) cout << logs[i].m <<" "<< logs[i].t << endl;;
    for(i=0;i<q;i++){
      cin >> ts >> te >> m ;
      j=0;
      o=0;
      f=0;
      while(j<logs.size()){
	while(j<logs.size()&&logs[j].m!=m) j++;
	if(j==logs.size()){
	  cout << o << endl;
	  f=1;
	}else{
	  if(logs[j].t<=ts&&te<=logs[j+1].t){
	    o+=te-ts;
	  }else if(logs[j].t<=ts&&ts<logs[j+1].t){
	    o+=logs[j+1].t-ts;
	  }else if(logs[j].t<te&&te<=logs[j+1].t){
	    o+=te-logs[j].t;
	  }else if(ts<=logs[j].t&&logs[j+1].t<=te){
	    o+=logs[j+1].t-logs[j].t;
	  }
	}
	j+=2;
      }
      if(j>=logs.size()&&f==0){
	cout << o << endl;
      }
      
    }
    
    cout  << endl;
    cin >> nu >> me;
  }
  return 0;
}
