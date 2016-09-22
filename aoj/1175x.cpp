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
int sum;
int n;
vector<circle>  v;
int on[30]={};
bool dp[1<<24];
void rec(int bit){
  if(dp[bit]) return;
  dp[bit]=true;
  int i,j,k;
  int o=0;
  for(i=0;i<n;i++) if(bit>>i&1) o++;
  sum=max(n-o,sum);
  int f=0;
  for(i=0;i<n;i++){
    if(!(bit>>i&1)||bit&on[i]) continue;
    for(j=i+1;j<n;j++){
      if(!(bit>>j&1)||bit&on[j]) continue;
      if(v[i].c==v[j].c){
	rec((bit&~(1<<i))&~(1<<j));
      }
    }
  }
}

int main(){
  cin >> n;
  while(n!=0){
    circle c;
    int i,j,k;
    v.clear();
    for(i=0;i<n;i++){
      cin >> c.x >> c.y >> c.r >> c.c;
      v.push_back(c);
    }
    sum=0;
    fill(on,on+30,0);
    for(i=0;i<n;i++){
      for(j=0;j<i;j++){
	if(ch(v[i],v[j])) on[i]|=(1<<j);
      }
    }
    fill(dp,dp+(1<<n),false);
    rec((1<<n)-1);
    cout << sum << endl;
    cin >> n;
  }
  return 0;
}
