#include<iostream>
#include<string>
using namespace std;
int main(){
  int n;
  cin>> n;
  while(n!=0){
    int i,j,k;
    string str;
    int mp[86401]={};
    for(i=0;i<n;i++){
      int st=0,et=0;
      cin >> str;
      st=((str[0]-'0')*10+str[1]-'0')*60*60
	+((str[3]-'0')*10+str[4]-'0')*60+((str[6]-'0')*10+str[7]-'0');
      cin >> str;
      et=((str[0]-'0')*10+str[1]-'0')*60*60
	+((str[3]-'0')*10+str[4]-'0')*60+((str[6]-'0')*10+str[7]-'0');
      for(j=st;j<et;j++) mp[j]++;
    }
    int m=0,b;
    for(i=0;i<86401;i++) if(m<mp[i]) m=mp[i];
    cout << m << endl;
    cin >> n;
  }
  return 0;
}
