#include<iostream>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
typedef pair<int,int> i_i;
#define mp(a,b) make_pair(a,b)
int main(){
  int n,m;
  cin >> n >> m;
  int step[1<<15];
  int inf = 1<<10;
  fill(step,step+(1<<15),inf);
  int i,j,k,c=0,b=0;
  int in=0;
  int o1=0,o2=0;
  for(i=0;i<n;i++) {
    cin >> k;
    b+=k;
    in=in<<1;
    in+=k;
  }
  /*
  for(i=n-1;i>=0;i--) cout << ((in>>i&1) ? 1:0);
  cout << endl;
  */
  //step[in]=0;
  for(i=0;i<m;i++) {
    cin >> k;
    o1=o1<<k;
    o2=o2<<k;
    if(i%2==0) {
      b+=k;
      o1+=pow(2,k)-1;
    }else{
      o2+=pow(2,k)-1;
    }
  }
  /*
  for(i=0;i<n;i++) cout << ((o1>>i&1) ? 1:0);
  cout << endl;
  for(i=0;i<n;i++) cout << ((o2>>i&1) ? 1:0);
  cout << endl;
  */

  queue<i_i> q;
  i_i x;
  x.first=in;x.second=0;
  q.push(x);
  while(step[o1]==inf&&step[o2]==inf&&!q.empty()){
    x=q.front();
    q.pop();
    /*
    for(i=n-1;i>=0;i--) cout << ((x.first>>i&1) ? 1:0);
    cout << endl;
    */
    if(step[x.first]>x.second){
      step[x.first]=x.second;
      for(i=n-1;i>0;i--){
	if((x.first>>i&1)==(x.first>>(i-1)&1)) continue;
	if((x.first>>i&1))
	  q.push(mp(x.first-pow(2,i)+pow(2,i-1),x.second+1));
	else
	  q.push(mp(x.first+pow(2,i)-pow(2,i-1),x.second+1));
      }
    }
  }
  
  
  cout << min(step[o1],step[o2]) << endl;
  return 0;
}
