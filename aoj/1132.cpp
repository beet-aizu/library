#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> P;
int main(){
  int n;
  while(cin>>n,n){
    vector<P> v;
    double x,y,mx1,mx2,my1,my2,p,q,a,b,c;
    int ans=1;
    int i,j,k,l;
    for(i=0;i<n;i++){
      cin >> x >> y;
      v.push_back(P(x,y));
    }
    for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
        mx1=v[i].first;my1=v[i].second;
	mx2=v[j].first;my2=v[j].second;
	//cout << (mx1-mx2)*(mx1-mx2)+(my1-my2)*(my1-my2) << endl;
	if((mx1-mx2)*(mx1-mx2)+(my1-my2)*(my1-my2)>2.0*2.0) continue;
	p=(my1-my2)/(mx2-mx1);
	q=((mx1+mx2)-p*(my1+my2))/2;
	//cout << p << ":" << q << endl;
	a=p*p+1;b=2*p*q-2*my1-2*mx1*p;c=q*q-2*mx1*q+mx1*mx1+my1*my1-1.0;
	//cout << a << ":" << b << ":" << c << endl;
	l=0;
	//cout << b*b-4*a*c << "/";
	y=(-b+sqrt(b*b-4*a*c))/(2*a);x=p*y+q;
	//cout << x << ":" << y << endl;
	for(k=0;k<n;k++){
	  if((v[k].first-x)*(v[k].first-x)
	     +(v[k].second-y)*(v[k].second-y)<=1.0001) l++;
	}
	l=0;
	y=(-b-sqrt(b*b-4*a*c))/(2*a);x=p*y+q;
	for(k=0;k<n;k++){
	  if((v[k].first-x)*(v[k].first-x)
	     +(v[k].second-y)*(v[k].second-y)<=1.0001) l++;
	}
	ans=max(ans,l);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
