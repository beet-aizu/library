#include<iostream>
#include<vector>
using namespace std;
struct circle{
  double x,y,r;
  int c;
};
int ch(circle a,circle b){
  if((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)<(a.r+b.r)*(a.r+b.r)) return 1;
  return 0;
}
int sum=0,ds;
int n;
void rec(vector<circle> vs){
  //cout << vs.size() << endl;
  int i,j,k;
  int f;
  int on[30]={};
  vector<int> cc[5];
  f=1;
  int ff=0;
  while(ff==0){
    ff=1;
    for(i=0;i<30;i++) on[i]=0;
    for(i=0;i<5;i++) cc[i].clear();
    for(i=0;i<vs.size();i++){
      for(j=i+1;j<vs.size();j++){
	if(ch(vs[i],vs[j])==1) on[j]=1;
      }
    }
    for(i=0;i<vs.size();i++){
      if(on[i]==0) cc[vs[i].c].push_back(i);
    }
    for(i=1;i<5;i++){
      if(cc[i].size()>0&&cc[i].size()%2==0){
	for(j=cc[i].size()-1;j>=0;j--){
	  vs.erase(vs.begin()+cc[i][j]);
	  ff=0;
	  f=0;
	}
      }
    }
  }
  for(i=1;i<5;i++){
    //cout << cc[i].size() << endl;
    if(cc[i].size()>=2&&cc[i].size()%2==1){
      f=0;
      vector<circle> next(vs);
      //for(j=0;j<vs.size();j++) next.push_back(vs[j]);
      for(j=0;j<cc[i].size();j++){
	for(k=cc[i].size()-1;k>=0;k--){
	  if(k!=j)
	    next.erase(next.begin()+cc[i][k]);
	}
	rec(next);
      }
      break;
    }
  }
  int o=n-vs.size();
  if(f==1) sum=max(sum,o);
  else{
    rec(vs);
  }
}

int main(){
  cin >> n;
  while(n!=0){
    circle c;
    vector<circle>  v;
    int i,j,k;
    for(i=0;i<n;i++){
      cin >> c.x >> c.y >> c.r >> c.c;
      v.push_back(c);
    }
    sum=0;
    rec(v);
    cout << sum << endl;
    cin >> n;
  }
  return 0;
}
