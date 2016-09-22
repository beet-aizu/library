#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
  int n;
  int i,j,k;
  while(cin>>n,n){
    map<string,int> m;
    map<string,int> l;
    int t,g;
    map<string,bool> h;
    string date,time,io,name,ye;
    for(i=0;i<n;i++){
      cin >> date >> time >> io >> name;
      t=(time[0]-'0')*600+(time[1]-'0')*60+(time[3]-'0')*10+(time[4]-'0');
      if(io=="I"){
	h[name]=true;
	l[name]=t;
	if(name=="000"){
	  //cout << "I" << t << endl;
	  for(map<string,bool>::iterator itr=h.begin();itr!=h.end();++itr) {
	    if(itr->second){
	      //cout << "key = " << itr->first << endl;
	      l[itr->first]=t;
	    }
	  }
	}
      }else{
	h[name]=false;
	if(name=="000"){
	  //cout << "O" << t << endl;
	  for(map<string,bool>::iterator itr=h.begin();itr!=h.end();++itr) {
	    if(itr->second){
	      //cout << "key = " << itr->first << endl;
	      m[itr->first]+=t-l[itr->first];
	    }
	  }
	}else{
	  if(h["000"]) m[name]+=t-l[name];
	}
      }
    }
    int o=0;
    for(map<string,bool>::iterator itr=h.begin();itr!=h.end();++itr) {
      //cout << "key = " << itr->first <<"time=" << m[itr->first] << endl;
      o=max(o, m[itr->first]);
    }
    cout << o << endl;
  }
  return 0;
}
