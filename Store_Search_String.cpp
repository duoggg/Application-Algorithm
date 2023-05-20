#include<bits/stdc++.h>
using namespace std;

int main(){
    string type;
    map<string, int> myMap;
    
    do{
        cin>> type;
        if(type=="*") continue;
        myMap[type]= 1;
    }while(type!="*");

    string item;
    queue<int> q;
    do{
        cin>>type;
        if(type=="***") continue;
        else if(type=="find"){
            cin>> item;
            if(myMap.find(item)!=myMap.end()) q.push(1);
            else q.push(0);
        }
        else if (type=="insert"){
            cin>> item;
            if(myMap.find(item)!=myMap.end()) {q.push(0);}
            else{
                myMap[item]=1;
                q.push(1);
            } 
        }
    }while(type!="***");
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;

}