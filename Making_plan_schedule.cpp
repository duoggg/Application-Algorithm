#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    map<int,int> duration,min;
     // After
    for(int i =1;i<=n;i++) {
        int a;
        cin>>a;
        duration[i]=a;
        min[i]=a;
    }
    int d,e;
    map<int, vector<int>> L;
   map<int, vector<int>> A;
    for(int i =0;i<n;i++) L[i+1]={}; 
    for(int i =0;i<m;i++){
        cin>>d;
        cin>>e;
        L[e].push_back(d); 
        A[d].push_back(e);
    }
    
    deque<int> St;
    
        for(int i =1;i<=n;i++){
            if(L[i].empty()) {St.push_back(i);
            L.erase(i);}
        }
       
        int max =0;
    
    while(!L.empty()){
        
       
            // Xoa cac phan tu cua it->second có trong St
          //  int a = min[it->first];  // Khoi tao thoi gian lau nhat cua CV hoan thanh trc no
          
          while(!St.empty()) {   
             int it1 = St.front();
            vector<int> y = A[it1];
                for(auto it2= y.begin(); it2 != y.end();++it2){
              
                     auto x = find(L[*it2].begin(), L[*it2].end(), it1);
                     L[*it2].erase(x);
                     
                     if(duration[*it2]+min[it1]>min[*it2]) min[*it2] = duration[*it2]+min[it1];
                     if(max<min[*it2]) max = min[*it2];
                     if(L[*it2].empty()) {L.erase(*it2);St.push_back(*it2);continue;}
          
                //cout << it->first<<' '<< *it1<< ' '<<a<<endl;
                }
                St.pop_front();
            
        }
         
        //cout << it->first <<' ' << a<< ' '<<duration[it->first]<<endl;

        
    }


    cout << max <<endl;
    return 0;

}
