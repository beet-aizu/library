#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main(){
  double x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  //cout << sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) << endl;
  printf("%.5f\n",sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
  return 0;
}
