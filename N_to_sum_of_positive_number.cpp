#include<bits/stdc++.h>
using namespace std;
int N;
int A[100];
int cot =0,c=0;
int check(int i,int k){
    if(cot+i<=N) return 1;
    return 0;
}
void Try(int k){
    for(int i=A[k-1];i<=N;i++){
        if(check(i,k)){
            A[k] = i;
            cot = cot+i;
            if(cot==N) c++;
            else Try(k+1);
            cot = cot -i;
        }
    }
}

int main(){
    cin>>N;
    A[0]=1;
    Try(1);
    cout<<c<<endl;
    return 0;
}