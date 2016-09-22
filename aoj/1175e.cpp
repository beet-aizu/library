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
    int on[24]={};
    int cc[5]={};
    while(f==0){
      f=1;
      
      for(i=0;i<24;i++) on[i]=0;
      for(i=0;i<v.size();i++){
	for(j=i+1;j<v.size();j++){
	  if(ch(v[i],v[j])==1) on[j]=1;
	}
      }
      for(i=0;i<5;i++) cc[i]=0;
      for(i=0;i<v.size();i++){
	if(on[i]==0) cc[v[i].c]++;
      }
      for(i=1;i<5;i++){
	k=0;
	for(j=0;j<v.size();j++){
	  if(on[j]==0&&v[j].c==i){
	    if((cc[i]/2)*2>k) {
	      v.erase(v.begin()+j-k);
	      k++;
	      sum++;
	      f=0;
	      j=-1;
	    }
	  }
	}
	if(f==0) break;
      }
    }
    cout << n-v.size() << endl;
    cin >> n;
  }
  return 0;
}
