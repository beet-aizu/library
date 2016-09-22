#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct team{
  int id,score,time,wrong[11];
  bool operator<(const team& a) const{
    return score == a.score ? (time == a.time ? id > a.id : time < a.time ) : score > a.score;
  }
};
int main(){
  int m,t,p,r,i,j,k;
  cin >> m >> t >> p >> r;
  while(m!=0){
    vector <team> teams;
    team te;
    for(j=0;j<11;j++) te.wrong[j]=0;
    te.score=0;
    te.time=0;
    for(i=1;i<=t;i++){
      te.id=i;
      teams.push_back(te);
    }
    int a,b,c,d;
    for(i=0;i<r;i++){
      cin >> a >> b >> c >> d;
      if(d==0){
	teams[b-1].score++;
	teams[b-1].time+=a+20*teams[b-1].wrong[c];
      }else{
	teams[b-1].wrong[c]++;
      }
    }
    sort(teams.begin(),teams.end());
    for(i=0;i<t;i++){
      if(i>0){
	if(teams[i-1].score==teams[i].score&&teams[i-1].time==teams[i].time) cout << "=";
	else cout << ",";
      }
      cout << teams[i].id;
    }
    cout << endl;
    cin >> m >> t >> p >> r;
  }
  return 0;
}
