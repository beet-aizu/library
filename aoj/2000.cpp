#include <iostream>
using namespace std;

struct Point{int x,y;};

int main(){
  int n,m,l,x,y,i,j,k,a;
  char d;
  int flag;
  
  cin >> n;
  while(n!=0){
    Point p[21];
    int v[21] = {};
    Point now;
    now.x=10;
    now.y=10;
    flag=0;
    for(i=0;i<n;i++) {
      cin >> x >> y;
      p[i].x=x;
      p[i].y=y;
    }
    k=0;
    cin >> m;
    for(i=0;i<m;i++){
      cin >> d >> l;
      for(a=0;a<l;a++){
      if(d=='N') now.y++;
      if(d=='E') now.x++;
      if(d=='S') now.y--;
      if(d=='W') now.x--;
      for(j=0;j<n;j++){
	if(now.x==p[j].x&&now.y==p[j].y&&v[j]==0){
	  k++;
	  v[j]=1;
	}
      }
      }
    }
    if(k==n) cout << "Yes" << endl;
    else cout << "No" << endl;
    cin >> n;
  }
  return 0;
}
