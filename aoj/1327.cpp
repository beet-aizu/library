#include<iostream>
#include<vector>
using namespace std;
struct ary{
  int x[51]; 
  ary(){}
  ary(int *p){
    for(int i=0;i<51;i++){
      x[i]=p[i];
    }
  }
};
int main(){
  int n,m,a,b,c,t;
  while(cin>>n>>m>>a>>b>>c>>t,n||m||a||b||c||t){
    int s[2][51]={{}};
    vector<ary> v;
    int x[51]={}; 
    int i,j,k,p,q;;
    for(i=0;i<n;i++){
      cin >> s[0][i]; 
    }
    //for(j=0;j<n;j++) cout << s[0][j] << (j==n-1?"\n":" ");
    v.push_back(ary(s[0]));
    //cout << t << endl;
    bool f;
    for(i=0;i<t;i++){
      s[(i+1)%2][0]=(b*s[i%2][0]+c*s[i%2][1])%m;
      for(j=1;j<n-1;j++){
	s[(i+1)%2][j]=(a*s[i%2][j-1]+b*s[i%2][j]+c*s[i%2][j+1])%m;
      }
      s[(i+1)%2][n-1]=(a*s[i%2][n-2]+b*s[i%2][n-1])%m;

      /*
      cout << i << ":";
      for(j=0;j<n;j++) cout << s[(i+1)%2][j] << (j==n-1?"\n":" ");
      */

      f=false;
      for(j=0;j<v.size();j++){
	bool ff=true;
	for(k=0;k<n;k++) if(v[j].x[k]!=s[(i+1)%2][k]) ff=false;
	if(ff){
	  f=true;
	  p=j;
	  break;
	}
      }
      if(f){
	q=i;
	cout << p <<":"<< q << endl;
	break;
      }
      v.push_back(ary(s[(i+1)%2]));
    }
    if(f){
      for(i=0;i<n;i++) cout << v[(t-p)%(q-p)+p-1].x[i] << (i==n-1?"\n":" ");
    }else{
      for(i=0;i<n;i++) cout << s[t%2][i] << (i==n-1?"\n":" ");
    }
  }
  return 0;
}
