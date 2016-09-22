#include<iostream>
#include<string>
using namespace std;
int main(){
  int p,q;
  while(cin>>p>>q,p||q){
    string b;
    int i,j,k;
    int r[20]={},c[20]={},s[20]={},n[20]={};
    int v[100][100][100]={{{}}};
    int br=-1,bc=-1,bs=-1;
    for(i=0;i<p;i++){
      r[i+1]=r[i];
      c[i+1]=c[i];
      s[i+1]=s[i];
      cin >> b;
      j=0;
      while(b[j]=='.') j++;
      n[i]=j;
     
      for(j=0;j<b.size();j++){
	if(b[j]=='(') r[i+1]++;
	if(b[j]==')') r[i+1]--;
	if(b[j]=='{') c[i+1]++;
	if(b[j]=='}') c[i+1]--;
	if(b[j]=='[') s[i+1]++;
	if(b[j]==']') s[i+1]--;
      }
      
      //cout << n[i] << ":" << r[i] << ":" << c[i] << ":" << s[i] << endl;
      //cout << br << ":" << bc << ":" << bs << endl; 
    }
    
    bool ff=false;
    for(i=1;i<=p;i++){
      for(j=i+1;j<=p;j++){
	for(k=j+1;k<=p;k++){
	  int d=r[i]*c[j]*s[k]+r[k]*c[i]*s[j]+r[j]*c[k]*s[i]
	    -r[k]*c[j]*s[i]-r[j]*c[i]*s[k]-r[i]*c[k]*s[j];
	  if(d==0) continue;
	  //cout << d  << "#";
	  br=n[i]*c[j]*s[k]+n[k]*c[i]*s[j]+n[j]*c[k]*s[i]
	    -n[k]*c[j]*s[i]-n[j]*c[i]*s[k]-n[i]*c[k]*s[j];
	  
	  bc=r[i]*n[j]*s[k]+r[k]*n[i]*s[j]+r[j]*n[k]*s[i]
	    -r[k]*n[j]*s[i]-r[j]*n[i]*s[k]-r[i]*n[k]*s[j];
	  
	  bs=r[i]*c[j]*n[k]+r[k]*c[i]*n[j]+r[j]*c[k]*n[i]
	    -r[k]*c[j]*n[i]-r[j]*c[i]*n[k]-r[i]*c[k]*n[j];
	  
	    //cout << br << ":" << bc << ":" << bs << endl; 
	  br/=d;bc/=d;bs/=d;
	  //cout << br << ":" << bc << ":" << bs << endl; 
	  
	  if(1<=br&&br<=20&&1<=bc&&bc<=20&&1<=bs&&bs<=20
	     &&r[i]*br+c[i]*bc+s[i]*bs==n[i]
	     &&r[j]*br+c[j]*bc+s[j]*bs==n[j]
	       &&r[k]*br+c[k]*bc+s[k]*bs==n[k]){
	    ff=true;
	    break;
	  }else{
	    br=-1;bc=-1;bs=-1;
	  }
	  
	}
	if(ff) break;
      }
      if(ff) break;
    }
    
    //cout << br << ":" << bc << ":" << bs << endl; 
    if(br==-1){
      for(i=0;i<p;i++){
	for(j=i+1;j<p;j++){
	  int d=r[i]*c[j]-r[j]*c[i];
	  if(s[i]!=0||s[j]!=0||d==0) continue;
	  int bbr=(n[i]*c[j]-n[j]*c[i])/d;
	  int bbc=(r[i]*n[j]-r[j]*n[i])/d;
	  if(1<=bbr&&bbr<=20&&1<=bbc&&bbc<=20){
	    br=bbr;
	    bc=bbc;
	  }
	}
      }
      for(i=0;i<p;i++){
	for(j=i+1;j<p;j++){
	  int d=s[i]*c[j]-s[j]*c[i];
	  if(r[i]!=0||r[j]!=0||d==0) continue;
	  int bbs=(n[i]*c[j]-n[j]*c[i])/d;
	  int bbc=(s[i]*n[j]-s[j]*n[i])/d;
	  if(1<=bbs&&bbs<=20&&1<=bbc&&bbc<=20){
	    bs=bbs;
	    bc=bbc;
	  }
	}
      }
      for(i=0;i<p;i++){
	for(j=i+1;j<p;j++){
	  int d=r[i]*s[j]-r[j]*s[i];
	  if(c[i]!=0||c[j]!=0||d==0) continue;
	  int bbr=(n[i]*s[j]-n[j]*s[i])/d;
	  int bbs=(r[i]*n[j]-r[j]*n[i])/d;
	  if(1<=bbr&&bbr<=20&&1<=bbs&&bbs<=20){
	    br=bbr;
	    bs=bbs;
	  }
	}
      }
    }
    //cout << br << ":" << bc << ":" << bs << endl; 
    if(br==-1){
      for(i=0;i<p;i++){
	for(j=i+1;j<p;j++){
	  if(c[i]*s[j]==s[i]*c[j]){
	    if(r[i]*c[j]-r[j]*c[i]!=0){
	      br=(n[i]*c[j]-n[j]*c[i])/(r[i]*c[j]-r[j]*c[i]);
	    }
	  }
	}
      }
    }

    if(bc==-1){
      for(i=0;i<p;i++){
	for(j=i+1;j<p;j++){
	  if(r[i]*s[j]==s[i]*r[j]){
	    if(c[i]*r[j]-c[j]*r[i]!=0){
	      bc=(n[i]*r[j]-n[j]*r[i])/(c[i]*r[j]-c[j]*r[i]);
	    }
	  }
	}
      }
    }
 
    if(bs==-1){
      for(i=0;i<p;i++){
	for(j=i+1;j<p;j++){
	  if(c[i]*r[j]==r[i]*c[j]){
	    if(s[i]*c[j]-s[j]*c[i]!=0){
	      bs=(n[i]*c[j]-n[j]*c[i])/(s[i]*c[j]-s[j]*c[i]);
	    }
	  }
	}
      }
    }
    
    
    if(br==-1){
      for(i=0;i<p;i++){
	for(j=i+1;j<p;j++){
	  if(r[i]!=r[j]&&c[i]==c[j]&&s[i]==s[j])
	    br=(n[i]-n[j])/(r[i]-r[j]);
	}
      }
    }
    if(bc==-1){
      for(i=0;i<p;i++){
	for(j=i+1;j<p;j++){
	  if(c[i]!=c[j]&&r[i]==r[j]&&s[i]==s[j])
	    bc=(n[i]-n[j])/(c[i]-c[j]);
	}
      }
    }
    if(bs==-1){
      for(i=0;i<p;i++){
	for(j=i+1;j<p;j++){
	  if(s[i]!=s[j]&&r[i]==r[j]&&c[i]==c[j])
	    bs=(n[i]-n[j])/(s[i]-s[j]);
	}
      }
    }
    

    bool f=true;
    while(f){
      f=false;
      for(i=0;i<p;i++){
	if(r[i]<100&&c[i]<100&&s[i]<100)
	  v[r[i]][c[i]][s[i]]=n[i];
	if(r[i]+c[i]+s[i]==n[i]){
	  if(r[i]!=0&&br==-1) {
	    br=1;
	    f=true;
	  }
	  if(c[i]!=0&&bc==-1){
	    bc=1;
	    f=true;
	  }
	  if(s[i]!=0&&bs==-1){
	    bs=1;
	      f=true;
	  }
	}
	if(r[i]*20+c[i]*20+s[i]*20==n[i]){
	  if(r[i]!=0&&br==-1) {
	    br=20;
	    f=true;
	  }
	  if(c[i]!=0&&bc==-1){
	    bc=20;
	    f=true;
	  }
	  if(s[i]!=0&&bs==-1){
	    bs=20;
	    f=true;
	  }
	}
	
	if(r[i]==0&&c[i]==0){
	  if(s[i]!=0&&bs==-1) {
	    bs=n[i]/s[i];
	    f=true;
	  }
	}
	if(r[i]==0&&s[i]==0){
	  if(c[i]!=0&&bc==-1){ 
	    bc=n[i]/c[i];
	    f=true;
	  }
	}
	if(c[i]==0&&s[i]==0){
	  if(r[i]!=0&&br==-1){
	    br=n[i]/r[i];
	    f=true;
	  }
	}
	if(s[i]==0){
	  if(br!=-1&&bc==-1&&r[i]!=0&&c[i]!=0){
	    bc=(n[i]-r[i]*br)/c[i];
	    f=true;
	  }
	  if(bc!=-1&&br==-1&&r[i]!=0&&c[i]!=0){
	    br=(n[i]-c[i]*bc)/r[i];
	    f=true;
	  }
	}
	
	if(c[i]==0){
	  if(br!=-1&&bs==-1&&r[i]!=0&&s[i]!=0){
	    bs=(n[i]-r[i]*br)/s[i];
	    f=true;
	  }
	  if(bs!=-1&&br==-1&&r[i]!=0&&s[i]!=0){
	    br=(n[i]-s[i]*bs)/r[i];
	    f=true;
	  }
	}
	
	if(r[i]==0){
	  if(bc!=-1&&bs==-1&&c[i]!=0&&s[i]!=0){
	    bs=(n[i]-c[i]*bc)/s[i];
	    f=true;
	  }
	  if(bs!=-1&&bc==-1&&s[i]!=0&&c[i]!=0){
	    bc=(n[i]-s[i]*bs)/c[i];
	    f=true;
	  }
	}
	if(r[i]*c[i]*s[i]!=0){
	  if(br==-1&&bc!=-1&&bs!=-1){
	    br=(n[i]-c[i]*bc-s[i]*bs)/r[i];
	    f=true;
	  }
	  if(br!=-1&&bc==-1&&bs!=-1){
	    bc=(n[i]-r[i]*br-s[i]*bs)/c[i];
	    f=true;
	  }
	  if(br!=-1&&bc!=-1&&bs==-1){
	    bs=(n[i]-c[i]*bc-r[i]*br)/s[i];
	    f=true;
	  }
	}
      }
    }
    
    //cout << br << ":" << bc << ":" << bs << endl; 
    //cout << br << bc << bs << endl;
    
    r[0]=0;c[0]=0;s[0]=0;
    for(i=0;i<q;i++){
      cin >> b;
      r[i+1]=r[i];
      c[i+1]=c[i];
      s[i+1]=s[i];
      for(j=0;j<b.size();j++){
	if(b[j]=='(') r[i+1]++;
	if(b[j]==')') r[i+1]--;
	  if(b[j]=='{') c[i+1]++;
	  if(b[j]=='}') c[i+1]--;
	  if(b[j]=='[') s[i+1]++;
	  if(b[j]==']') s[i+1]--;
      }
      
      //cout << endl << r[i] << ":" << c[i] << ":" << s[i] << endl;
      
      if(i==0) cout << 0;
      else {
	cout << " ";
	if(r[i]==0&&c[i]==0&&s[i]==0) 
	  cout << 0;
	else if(r[i]<100&&c[i]<100&&s[i]<100&&v[r[i]][c[i]][s[i]]!=0) 
	  cout << v[r[i]][c[i]][s[i]];
	else if((r[i]!=0&&br==-1)||(c[i]!=0&&bc==-1)||(s[i]!=0&&bs==-1))
	  cout << -1;
	else 
	  cout << r[i]*br+c[i]*bc+s[i]*bs ;
	
      }
    }
    cout << endl;
  }
  return 0;
}
