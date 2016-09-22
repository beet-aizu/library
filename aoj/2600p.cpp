#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> i_i;
int main(){
  int n,w,h;
  int i,j,k;
  int x,y,r;
  vector<i_i> vx;
  vector<i_i> vy;
  i_i a;
  cin >> n >> w >> h;
  for(i=0;i<n;i++){
    cin >> x >> y >> r;
    a.first=x-r;a.second=x+r;
    vx.push_back(a);
    a.first=y-r;a.second=y+r;
    vy.push_back(a);
  }
  //cout << vx.size() << vy.size();
  sort(vx.begin(),vx.end());
  sort(vy.begin(),vy.end());
  int f=0;
  int fi=vx[0].first,se=vx[0].second;
  //cout << fi;
  if(fi>0) {
    f=1;
  }else{
    for(i=0;i<vx.size();i++){
      fi=vx[i].first;
      if(fi>se){
	f=1;
	break;
      }
      se=max(se,vx[i].second);
    }
  }
  //cout << se << endl;
  if(se<w) f=1;
  if(f==0) {
    cout << "Yes" <<endl;
  }else{
    f=0;
    fi=vy[0].first;
    se=vy[0].second;
    //cout << fi;
    if(fi>0) f=1;
    else
      for(i=0;i<vy.size();i++){
	fi=vy[i].first;
	if(fi>se){
	  f=1;
	  break;
	}
	se=max(se,vy[i].second);
      }
    //cout << se << endl;
    if(se<h) f=1;
    if(f==0) cout << "Yes" <<endl;
    else cout << "No" <<endl;
  }
  
}
