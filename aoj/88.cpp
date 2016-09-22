#include<iostream>
#include<string>
using namespace std;
string c2s(char c){
  if(c==' ') return "101";
  if(c=='\'') return "000000";
  if(c==',') return "000011";
  if(c=='-') return "10010001";
  if(c=='.') return "010001";
  if(c=='?') return "000001";
  if(c=='A') return "100101";
  if(c=='B') return "10011010";
  if(c=='C') return "0101";
  if(c=='D') return "0001";
  if(c=='E') return "110";
  if(c=='F') return "01001";
  if(c=='G') return "10011011";
  if(c=='H') return "010000";
  if(c=='I') return "0111";
  if(c=='J') return "10011000";
  if(c=='K') return "0110";
  if(c=='L') return "00100";
  if(c=='M') return "10011001";
  if(c=='N') return "10011110";
  if(c=='O') return "00101";
  if(c=='P') return "111";
  if(c=='Q') return "10011111";
  if(c=='R') return "1000";
  if(c=='S') return "00110";
  if(c=='T') return "00111";
  if(c=='U') return "10011100";
  if(c=='V') return "10011101";
  if(c=='W') return "000010";
  if(c=='X') return "10010010";
  if(c=='Y') return "10010011";
  if(c=='Z') return "10010000"; 
}
char s2c(string x){
  if(x=="00000") return 'A';
  if(x=="00001") return 'B';
  if(x=="00010") return 'C';
  if(x=="00011") return 'D';
  if(x=="00100") return 'E';
  if(x=="00101") return 'F';
  if(x=="00110") return 'G';
  if(x=="00111") return 'H';
  if(x=="01000") return 'I';
  if(x=="01001") return 'J';
  if(x=="01010") return 'K';
  if(x=="01011") return 'L';
  if(x=="01100") return 'M';
  if(x=="01101") return 'N';
  if(x=="01110") return 'O';
  if(x=="01111") return 'P';
  if(x=="10000") return 'Q';
  if(x=="10001") return 'R';
  if(x=="10010") return 'S';
  if(x=="10011") return 'T';
  if(x=="10100") return 'U';
  if(x=="10101") return 'V';
  if(x=="10110") return 'W';
  if(x=="10111") return 'X';
  if(x=="11000") return 'Y';
  if(x=="11001") return 'Z';
  if(x=="11010") return ' ';
  if(x=="11011") return '.';
  if(x=="11100") return ',';
  if(x=="11101") return '-';
  if(x=="11110") return '\'';
  if(x=="11111") return '?';
}
int main(){
  string s;
  while(getline(cin,s)){
    int i;
    string m;
    for(i=0;i<s.size();i++) m+=c2s(s[i]);
    if(m.size()%5!=0){
      m+="0000";
    }
    string o;
    for(i=0;i+5<=m.size();i+=5){
      o+=s2c(m.substr(i,5));
    }
    cout << o << endl;
  }
  return 0;
}
