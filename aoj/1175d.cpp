#include<iostream>
#include<vector>
using namespace std;
struct circle{
  double x,y,r;
  int c,id;
};
int ch(circle a,circle b){
  if((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)<(a.r+b.r)*(a.r+b.r)) return 1;
  return 0;
}
int main(){
  int n;
  cin >> n;
  while(n!=0){
    int sum=0;
    circle c;
    vector<circle>  v;
    int i,j,k;
    for(i=0;i<n;i++){
      cin >> c.x >> c.y >> c.r >> c.c;
      c.id=i;
      v.push_back(c);
    }
    int f=0;
    int on[30]={};
    //int cc[5]={};
    vector<int> cc[5];
    while(f==0){
      f=1;
      for(i=0;i<30;i++) on[i]=0;
      for(i=0;i<v.size();i++){
	for(j=i+1;j<v.size();j++){
	  if(ch(v[i],v[j])==1) on[j]=1;
	}
      }
      
      for(i=0;i<5;i++) cc[i].clear();
      for(i=0;i<v.size();i++){
	if(on[i]==0) cc[v[i].c].push_back(i);
      }
      
      for(i=1;i<5;i++){
	if(cc[i].size()>0&&cc[i].size()%2==0){
	  for(j=cc[i].size()-1;j>=0;j--){
	    v.erase(v.begin()+cc[i][j]);
	    f=0;
	  }
	  break;
	}
      }
    }
    cout << n-v.size() << endl;
    cin >> n;
  }
  return 0;
}
