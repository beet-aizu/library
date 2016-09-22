#include<iostream>
#include<vector>
using namespace std;
int main(){
  int a,b,c;
  int t=0;
  cin >> a >> b >> c;
  int x=0;
  vector <int> m;
  int f=0;
  while(f==0&&(60*x+c)%(a+b)>a) {
    for(int i=0;i<m.size();i++){
      if(m[i]==(60*x+c)%(a+b)) {
	f=1;
	cout << -1 << endl;
      }
    }
    m.push_back((60*x+c)%(a+b));
    x++;
  }
  if(f==0)
  cout << (60*x+c) << endl;
  return 0;
}
