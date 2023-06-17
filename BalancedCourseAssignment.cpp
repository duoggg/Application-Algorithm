#include<bits/stdc++.h>
using namespace std;
int m ; /* Giáo viên*/
int n; /* Courses*/
vector<int> A[31];
int conflict[50][50];
int load[20];
int course[30];
int res=50;

int check(int t, int k){
    for(int i =1;i<k;i++){
        if(course[i]==t){
            if(conflict[i][k]==1) return 0;
            
        }
    }
    return 1;
}

void solution(){
    int max = 0;
    for(int i=1;i<=m;i++){
        if(load[i]>max) max = load[i];
    }
    if(max<res) res = max;
}

void Try(int k){
    for(int i =0;i<A[k].size();i++){
        int t = A[k][i];
        if(check(t,k)){      /*if course k can be assigned to teacher t*/
            course[k] = t;
            load[t]+=1;
            if(k==n){solution();}
            else if(load[t]<res)
                Try(k+1);
            load[t]-=1;
            course[k]=0;
        }
    }
}


int main(){
    
    cin>>m;
    cin>>n;
    int a,b;
    for(int i =1;i<=m;i++){
        load[i] = 0;
        cin>>a;
        for(int j =0;j<a;j++){
            cin>>b;
            A[b].push_back(i);
        }
    }
    int c ;
    cin>>c;
    for(int i =1;i<=n;i++)
        for(int j =1;j<=n;j++)
            conflict[i][j] = 0;
    for(int i =0; i < c;i++){
        cin >>a ;
        cin>>b;
        conflict[a][b] = conflict[b][a] = 1;

    }
    Try(1);
    cout<<res<<endl;
    return 0;
}