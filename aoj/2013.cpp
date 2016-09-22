#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef pair<int,int> se;
typedef vector<se> tt;
int main(){
  int n;
  cin>> n;
  while(n!=0){
    int i,j,k;
    string str;
    tt t;
    for(i=0;i<n;i++){
      int st=0,et=0;
      cin >> str;
      st+=((str[0]-'0')*10+str[1]-'0')*24*60
	+((str[3]-'0')*10+str[4]-'0')*60+((str[6]-'0')*10+str[7]-'0');
      cin >> str;
      et+=((str[0]-'0')*10+str[1]-'0')*24*60
	+((str[3]-'0')*10+str[4]-'0')*60+((str[6]-'0')*10+str[7]-'0');
      t.push_back(make_pair(st,et));
    }
    sort(t.begin(),t.end());
    int m=0,b;
    for(j=0;j<86401;j++) {
      b=0;
      for(k=0;k<t.size();k++){
	if(t[k].first<=j&&j<t[k].second) b++;
	if(t[k].first>j) break;
      }
      if(m<b) m=b;
    }
    cout << m << endl;
    cin >> n;
  }
  return 0;
}
