#include<iostream>
using namespace std;
struct ant{int x,d,s,i;};
int main(){
  int n,l;
  cin >> n >> l;
  while(n!=0){
    int i,j,k;
    ant as[30];
    bool f[30];
    char c;
    for(i=0;i<n;i++){
      cin >> c >> as[i].x;
      if(c=='R') as[i].d=1;
      else as[i].d=-1;
      as[i].s=1;
      as[i].i=i;
      f[i]=false;
    }
    k=1;
    bool fl=true;
    while(fl){
      fl=false;
      for(i=0;i<n;i++) {
	if(!f[i]) {
	  as[i].x+=as[i].d;
	  if(as[i].x<=0||as[i].x>=l) f[i]=true;
	  else as[i].s++;
	  fl=true;
	}
      }
      for(i=0;i<n;i++) {
	if(f[i]) continue;
	for(j=i+1;j<n;j++) {
	  if(f[j]) continue;
	  if(as[i].x==as[j].x) swap(as[i].i,as[j].i);
	}
      }
    }
    int o=0,id=0;
    for(i=0;i<n;i++) {
      //cout << o << as[i].d << ":" << as[i].i<<endl;
      if(o<=as[i].s){
	if(o==as[i].s&&as[i].d==1) continue;
	
	o=as[i].s;id=as[i].i;
      }
    }
    cout << o <<" " << id+1 << endl;
    cin >> n >> l;
  }

}
