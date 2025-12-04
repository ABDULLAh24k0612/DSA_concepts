#include<iostream>
#include<string>
using namespace std;

void  bruteStringALgorithm(string text,string pattern){
    int textL=text.length();
    int patternL=pattern.length();

    for(int i=0;i<textL-patternL;i++){
        int matchcount=0;
      while(matchcount<patternL && text[i+matchcount]==pattern[matchcount]){
        matchcount++;
      }
      if(matchcount==patternL){
        cout << pattern << " found at the index "<< i <<endl;
      }
    }
}

int main(){

    string text= "ABBBAAAABCBBB";
    string pattern="ABC";

    bruteStringALgorithm(text,pattern);

    return 0;
}
