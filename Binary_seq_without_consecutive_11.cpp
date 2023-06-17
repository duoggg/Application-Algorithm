#include<bits/stdc++.h>
using namespace std;
int A[100];
int n;

int check(int i,int k){
    
    if(i==1&&A[k-1]==1) return 0;
    return 1;
}
void solution(){
    for(int i =1;i<=n;i++){
        cout<<A[i];
    }
    cout<<endl;
}
void Try(int k){
    for(int i=0;i<=1;i++){
        if(check(i,k)){
            A[k] =i;
            if(k==n) solution();
            else Try(k+1);
        }
    }
}
int main(){
    cin>>n;
    A[0]=0;
    Try(1);
    return 0;
}
