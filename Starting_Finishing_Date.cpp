#include<bits/stdc++.h>
using namespace std;
vector<string> Date;
queue<int> Qhour; 
queue<int> Qmin; 
queue<int> Qsec;
queue<int> DataOut; 
queue<int> Qi;
queue<string> QDay;
int i;
void Input(){
    string type;
    
    
    do{
        cin>> type;
        if(type=="*") continue;
       // sscanf(type,"%d-%d-%d",year,mon,day);
        Date.push_back(type);

    }while(type!="*");

    int secPeriod, h,m,s ;
    char l;
    do{
        cin>>type;
        if(type=="***") continue;
        
       cin>>h;
       cin>>l;
       cin>>m;
       cin>>l;
       cin>>s;
       cin>>secPeriod;
       
        
        auto it = lower_bound(Date.begin(), Date.end(), type);

      
        int i = distance(Date.begin(), it);
        
        
        int toSecond = h*60*60+m*60+s;

        /// GET PERIOD
        int total_Second = toSecond+ secPeriod; 
        
        /// SOLVE
        int day = total_Second / 86400;
        int hour = (total_Second - day*86400)/3600;
        int min = (total_Second - day*86400-hour*3600)/60 ;
        int sec = total_Second - day*86400-hour*3600 - min *60;
       
        QDay.push(Date[i+day]);
        Qhour.push(hour);
        Qmin.push(min);
        Qsec.push(sec);
        //Qi.push(i);
        // DataOut.push(day);
        //DataIn.push(day);
        
        
        
    }while(type!="***");

    
}


int main(){
    Input();
    
    
    while(!QDay.empty()){
        cout<<QDay.front()<<" "  ;
        printf("%02d:%02d:%02d\n",Qhour.front(),Qmin.front(),Qsec.front());
        //cout<<QDay.front()<<" "<<Qhour.front()<<":"<<Qmin.front()<<":"<<Qsec.front()<<endl;
        
        QDay.pop();
        Qhour.pop();
         Qmin.pop();
        Qsec.pop();
        //DataOut.pop();
       
        //Qi.pop();
        
    }
    return 0;
}