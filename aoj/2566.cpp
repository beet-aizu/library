#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
int main(){
  string a,b,c;
  while(cin >> a,a!="0"){
    cin >> b >> c;
    ll n=a.size()-1;
    ll i,j,k;
    ll ans[85][2]={{}};
    ans[n+1][0]=1;
    for(i=n;i>0;i--){
      if(a[i]!='?'){
	if(b[i]!='?'){
	  if(c[i]!='?'){
	    if(a[i]+b[i]-'0'==c[i]) ans[i][0]=ans[i+1][0];
	    if(a[i]+b[i]-'0'==c[i]-1) ans[i][0]=ans[i+1][1];
	    if(a[i]+b[i]-'0'==c[i]+10) ans[i][1]=ans[i+1][0];
	    if(a[i]+b[i]-'0'==c[i]+10-1) ans[i][1]=ans[i+1][1];
	  }else{
	    if(a[i]-'0'+b[i]-'0'<10) ans[i][0]+=ans[i+1][0];
	    else ans[i][1]+=ans[i+1][0];
	    if(a[i]-'0'+b[i]-'0'+1<10) ans[i][0]+=ans[i+1][1];
	    else ans[i][1]+=ans[i+1][1];
	  }
	}else{
	  if(c[i]!='?'){
	    if(a[i]==c[i]){
	      ans[i][0]+=ans[i+1][0];
	      ans[i][1]+=ans[i+1][1];
	    }else if(a[i]<c[i]){
	      ans[i][0]+=ans[i+1][0]+ans[i+1][1];
	    }else{
	      ans[i][1]+=ans[i+1][0]+ans[i+1][1];
	    }
	  }else{
	    k=a[i]-'0';
	    ans[i][0]+=ans[i+1][1]*(10-(k+1));
	    ans[i][1]+=ans[i+1][1]*(k+1);
	    ans[i][0]+=ans[i+1][0]*(10-k);
	    ans[i][1]+=ans[i+1][0]*k;
	  }
	}
      }else{
	if(b[i]!='?'){
	  if(c[i]!='?'){
	    if(b[i]==c[i]){
	      ans[i][0]+=ans[i+1][0];
	      ans[i][1]+=ans[i+1][1];
	    }else if(b[i]<c[i]){
	      ans[i][0]+=ans[i+1][0]+ans[i+1][1];
	    }else{
	      ans[i][1]+=ans[i+1][0]+ans[i+1][1];
	    }
	  }else{
	    k=b[i]-'0';
	    ans[i][0]+=ans[i+1][1]*(10-(k+1));
	    ans[i][1]+=ans[i+1][1]*(k+1);
	    ans[i][0]+=ans[i+1][0]*(10-k);
	    ans[i][1]+=ans[i+1][0]*k;
	  }
	}else{
	  if(c[i]!='?'){
	    k=c[i]-'0';
	    ans[i][0]+=ans[i+1][0]*(k+1);
	    ans[i][1]+=ans[i+1][0]*(10-(k+1));
	    ans[i][0]+=ans[i+1][1]*k;
	    ans[i][1]+=ans[i+1][1]*(10-k);
	  }else{
	    ans[i][0]+=ans[i+1][0]*55+ans[i+1][1]*45;
	    ans[i][1]+=ans[i+1][0]*45+ans[i+1][1]*55;
	  }
	}
      }
      ans[i][0]%=MOD;
      ans[i][1]%=MOD;
      //cout << ans[i][0] << ":" << ans[i][1] << endl;
    }


    
    i=0;
    if(a[i]!='0'&&b[i]!='0'&&c[i]!='0'){
      if(a[i]!='?'){
	if(b[i]!='?'){
	  if(c[i]!='?'){
	    if(a[i]+b[i]-'0'==c[i]) ans[i][0]=ans[i+1][0];
	    if(a[i]+b[i]-'0'==c[i]-1) ans[i][0]=ans[i+1][1];
	  }else{
	    if(a[i]-'0'+b[i]-'0'<10) ans[i][0]+=ans[i+1][0];
	    if(a[i]-'0'+b[i]-'0'+1<10) ans[i][0]+=ans[i+1][1];
	  }
	}else{
	  if(c[i]!='?'){
	    if(a[i]<c[i])ans[i][0]+=ans[i+1][0];
	    if(a[i]+1<c[i])ans[i][0]+=ans[i+1][1];
	  }else{
	    k=a[i]-'0';
	    if(0<(10-(k+1))) ans[i][0]+=ans[i+1][0]*(10-(k+1));
	    if(0<(10-(k+2))) ans[i][0]+=ans[i+1][1]*(10-(k+2));
	  }
	}
      }else{
	if(b[i]!='?'){
	  if(c[i]!='?'){
	    if(b[i]<c[i])ans[i][0]+=ans[i+1][0];
	    if(b[i]+1<c[i])ans[i][0]+=ans[i+1][1];
	  }else{
	    k=b[i]-'0';
	    if(0<(10-(k+1))) ans[i][0]+=ans[i+1][0]*(10-(k+1));
	    if(0<(10-(k+2))) ans[i][0]+=ans[i+1][1]*(10-(k+2));
	  }
	}else{
	  if(c[i]!='?'){
	    k=c[i]-'0';
	    if(0<k-1) ans[i][0]+=ans[i+1][0]*(k-1);
	    if(0<k-2) ans[i][0]+=ans[i+1][1]*(k-2);
	  }else{
	    ans[i][0]+=ans[i+1][0]*36+ans[i+1][1]*28;
	  }
	}
      }
    }
    //cout << ans[i][0] << ":" << ans[i][1] << endl;
    cout << ans[0][0]%MOD << endl;
  }
  return 0;
}
