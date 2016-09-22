#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct seed{
  string l;
  int p,a,b,c,d,e,f,s,m;
  double n;
  double r,t;
  int i,j;
  void k(){
    t = a+b+c + (d+e) * m;
    r = f*s*m-p;
    n = r / t;
  }
  bool operator<(const seed & a)const{
    return n==a.n ? (l<a.l) : n > a.n;
  }
};
int main(){
  int n;
  int i,j,k;
  cin >> n;
  while(n!=0){
    vector <seed> ss;
    seed s;
    for(i=0;i<n;i++){
      cin >> s.l >> s.p >> s.a >> s.b >> s.c >> s.d >> s.e >> s.f >> s.s >> s.m;
      s.k();
      ss.push_back(s);
    }
    sort(ss.begin(),ss.end());
    for(i=0;i<n;i++) cout << ss[i].l << endl;
    cout << "#" <<  endl;
    cin >> n;
  }
  return 0;
}
