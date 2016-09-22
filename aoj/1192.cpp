#include <iostream>
using namespace std;
int main(){
  int x,y,s,i,j,k,o,a,b,sum;
  cin >> x >> y >> s;
  while(x!=0){
    o=0;
    for(i=1;i<s/2+1;i++){
      a=i*(100+x)/100;
      b=(s-a)*100/(100+x);
      while((b+1)*(100+x)/100+a<=s) b++;
      sum = i*(100+y)/100+b*(100+y)/100;
      if(b*(100+x)/100+a==s&&sum>o) {
	o=sum;
	//cout << a << endl;
      }
    }
    cout << o << endl;
    cin >> x >> y >> s;
  }
  return 0;
}
