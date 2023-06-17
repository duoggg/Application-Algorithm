#include<bits/stdc++.h>
using namespace std;
int n,L;
int A[100000];
int t = 0;

int check(int k,int i){
    if(t+i<=n) return 1;
    return 0;
}
void Solution(){
    for(int i =1;i<=L;i++){
        cout<<A[i]<<' ';
    }
    cout<<endl;
}
void Try(int k){
    for(int i =A[k-1];i<=n-t;i++){
        if(check(k,i)==1){
            t = t+ i;
            A[k]=i;
            if(k==L){
                if(t==n) Solution();
            }
            else Try(k+1);
            t = t-i;
        }
    }
}
int main(){
    cin >>L;
    cin>>n;
    A[0] = 1;
    Try(1);
    return 0;
}