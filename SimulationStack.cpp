#include<bits/stdc++.h>
using namespace std;
queue<int> st;
queue<int> result;

int main(){
    string line;
    int a;
    

    do{
        cin>>line;
        if(line =="#") continue;
        
         if(line=="PUSH"){cin >>a; st.push(a);}
         else if(line =="POP"){ 
            if(!st.empty()){result.push(st.front()); st.pop();}
            else {result.push(-999);}
            
            }
         
    }while(line!="#");
    while(!result.empty()){
        int c =result.front();
        if(c!=-999)cout<<c <<endl;
        else cout<<"NULL"<<endl;
        result.pop();
    }
    return 0;
}