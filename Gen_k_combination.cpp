#include<bits/stdc++.h>
using namespace std;
int n,m;
int A[1000];

int check(int i, int k){
    if(A[k-1]<i) return 1;
    return 0;
}
void Solution(){
    for(int i =1;i<=m;i++)
        cout<<A[i]<<' ';
    
}

void Try(int k){
    for(int i = A[k-1]+1;i<=n;i++){
        if(check(i,k)){
            A[k]=i;
            if(k==m) {Solution(); cout<<endl;}
            else Try(k+1);
            A[k] =A[k-1];
        }
    }

}

int main(){
    cin>>m;
    cin>>n;
    A[0]= 0;
    Try(1);
    return 0;

}