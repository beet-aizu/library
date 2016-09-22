#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct line{
  int p1,p2,h;
  bool operator<(const line& another) const {
    return h > another.h;
  }
};
int main(){
  int n,m,a,h,p,q,i,j,k,c;
  
  cin >> n >> m >> a;
  while(n!=0){
    vector <line> ls;
    line l;
    for(i=0;i<m;i++) {
      cin >> h >> p >> q;
      l.h=h;l.p1=p;l.p2=q;
      ls.push_back(l);
    }
    sort(ls.begin(),ls.end());
    c=a;
    for(i=0;i<m;i++){
      if(ls[i].p1==c) c=ls[i].p2;
      else if(ls[i].p2==c) c=ls[i].p1;
    }
    cout << c << endl;
    cin >> n >> m >> a;
  }
  return 0;
}
