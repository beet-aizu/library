#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;
#define PI 3.141592
int main(){
  float angle=0;
  float x=0,y=0;
  float d,t;
  string str;
  cin >> str;
  if(str[1]==','){
    d= str[0]-'0';
    if(str[2]=='-'){
      if(str.size()==4) t = (str[3]-'0')*(-1);
      else if(str.size()==5) t = ((str[3]-'0')*10+(str[4]-'0'))*(-1);
      else t = ((str[3]-'0')*100+(str[4]-'0')*10+(str[5]-'0'))*(-1);
    }else{
      if(str.size()==3) t = str[2]-'0';
      else if(str.size()==4) t = (str[2]-'0')*10+(str[3]-'0');
      else t = (str[2]-'0')*100+(str[3]-'0')*10+(str[4]-'0');
    }
  }else if(str[2]==','){
    d= (str[0]-'0')*10+str[1]-'0';
    if(str[3]=='-'){
      if(str.size()==5) t = (str[4]-'0')*(-1);
      else if(str.size()==6) t = ((str[4]-'0')*10+(str[5]-'0'))*(-1);
      else t = ((str[4]-'0')*100+(str[5]-'0')*10+(str[6]-'0'))*(-1);
    }else{
      if(str.size()==4) t = str[3]-'0';
      else if(str.size()==5) t = (str[3]-'0')*10+(str[4]-'0');
      else t = (str[3]-'0')*100+(str[4]-'0')*10+(str[5]-'0');
    }
  }else if(str[3]==','){
    d= (str[0]-'0')*100+(str[1]-'0')*10+(str[2]-'0');
    if(str[4]=='-'){
      if(str.size()==6) t = (str[5]-'0')*(-1);
      else if(str.size()==7) t = ((str[5]-'0')*10+(str[6]-'0'))*(-1);
      else t = ((str[5]-'0')*100+(str[6]-'0')*10+(str[7]-'0'))*(-1);
    }else{
      if(str.size()==5) t = str[4]-'0';
      else if(str.size()==6) t = (str[4]-'0')*10+(str[5]-'0');
      else t = (str[4]-'0')*100+(str[5]-'0')*10+(str[6]-'0');
    }
  }
  while(d!=0||t!=0){
    x+=d*sin(angle/180*PI);y+=d*cos(angle/180*PI);
    angle+=t;
    if(angle>360) angle-=360;
    if(angle<-360) angle+=360;
    cin >> str;
      if(str[1]==','){
    d= str[0]-'0';
    if(str[2]=='-'){
      if(str.size()==4) t = (str[3]-'0')*(-1);
      else if(str.size()==5) t = ((str[3]-'0')*10+(str[4]-'0'))*(-1);
      else t = ((str[3]-'0')*100+(str[4]-'0')*10+(str[5]-'0'))*(-1);
    }else{
      if(str.size()==3) t = str[2]-'0';
      else if(str.size()==4) t = (str[2]-'0')*10+(str[3]-'0');
      else t = (str[2]-'0')*100+(str[3]-'0')*10+(str[4]-'0');
    }
  }else if(str[2]==','){
    d= (str[0]-'0')*10+str[1]-'0';
    if(str[3]=='-'){
      if(str.size()==5) t = (str[4]-'0')*(-1);
      else if(str.size()==6) t = ((str[4]-'0')*10+(str[5]-'0'))*(-1);
      else t = ((str[4]-'0')*100+(str[5]-'0')*10+(str[6]-'0'))*(-1);
    }else{
      if(str.size()==4) t = str[3]-'0';
      else if(str.size()==5) t = (str[3]-'0')*10+(str[4]-'0');
      else t = (str[3]-'0')*100+(str[4]-'0')*10+(str[5]-'0');
    }
  }else if(str[3]==','){
    d= (str[0]-'0')*100+(str[1]-'0')*10+(str[2]-'0');
    if(str[4]=='-'){
      if(str.size()==6) t = (str[5]-'0')*(-1);
      else if(str.size()==7) t = ((str[5]-'0')*10+(str[6]-'0'))*(-1);
      else t = ((str[5]-'0')*100+(str[6]-'0')*10+(str[7]-'0'))*(-1);
    }else{
      if(str.size()==5) t = str[4]-'0';
      else if(str.size()==6) t = (str[4]-'0')*10+(str[5]-'0');
      else t = (str[4]-'0')*100+(str[5]-'0')*10+(str[6]-'0');
    }
  }
  }
  int x1=x,y1=y;
  
  printf("%d\n%d\n",x1,y1);
  return 0;
}
