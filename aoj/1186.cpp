#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct rect{
  int w,h,v;
  bool operator<(const rect& a) const{
    return v==a.v ? h < a.h : v < a.v;
  }
};
int main(){
  int i,j,k,w,h;
  vector <rect> rs;
  rect r;
  for(i=1;i<151;i++){
    for(j=1;j<i;j++){
      r.w=i;
      r.h=j;
      r.v=i*i+j*j;
      rs.push_back(r);
    }
  }
  sort(rs.begin(),rs.end());
  cin >> h >> w;
  while(h!=0){
    for(i=0;i<rs.size();i++){
      if(rs[i].w==w&&rs[i].h==h) cout << rs[i+1].h << " " << rs[i+1].w << endl;
    }
    cin >> h >> w;
  }
  return 0;
}
