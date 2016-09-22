#include<iostream>
#include <random>
using namespace std;
int main(){
  cout << 1000 << " ";
  for(int i=0;i<1000;i++) cout << rand()%10 << " ";
  return 0;
}
