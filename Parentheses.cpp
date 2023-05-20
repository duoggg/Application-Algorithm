#include<bits/stdc++.h>
using namespace std;

int main(){
    
    char c;
    deque<char> myOpen;
    deque<char> myClose;
    map<char,char> a;
    int k=1;
    do{
        c= getchar() ;
        if(c=='\n') continue;
        else if(c=='[' || c=='{' || c=='(') myOpen.push_back(c);
        else {
            
            if(myOpen.empty()) {k=0;}
             else if(myOpen.back()=='{'&& c=='}') myOpen.pop_back();
             else if(myOpen.back()=='['&& c==']') myOpen.pop_back();
             else if(myOpen.back()=='('&& c==')')myOpen.pop_back();
             else {k=0;myOpen.pop_back();}
        }

    }while(c!='\n');
    if(!myOpen.empty())k=0;
    cout<<k<<endl;
    return 0;
    
}