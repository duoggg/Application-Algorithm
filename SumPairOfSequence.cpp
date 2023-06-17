#include<bits/stdc++.h>
using namespace std;
int N[1000000];
int M;
int n;
int cot = 0;

int main(){
    cin>> n;
    cin>> M;
    int a;
    for(int i =0;i<n;i++){
        cin>>a;

        if(a<=M/2){
            if(N[a]==1) cot++;
            else N[a] = 1;
        } 
        else {
            if(N[M-a]==1) cot++;
            else N[M-a]=1;
        }
    }

    cout<<cot<<endl;
    return 0;


}