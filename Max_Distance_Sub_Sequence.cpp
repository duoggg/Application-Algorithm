#include<bits/stdc++.h>
using namespace std;
int test;
int A[100005];
int n;
int k;

int check(int d){
    int s1=1;
    int i=1, j=2;
    while(i<n){
        while(j<=n && A[j]-A[i]<d) ++j;
    if(j<=n) s1++;
    if(s1>=k) return 1;
    i=j;
    j++;
    }
    return 0;
}


int main(){
    cin>>test;
    for(int i =1;i<=test;i++){
        cin >> n;
        cin>> k;
        for(int j=1;j<=n;j++) cin>>A[j];
        sort(A+1,A+n+1);
        int max_d = A[n]-A[1];
        int min_d =0;
        int d;
        while(max_d>=min_d){
             d = (max_d+min_d)/2;
            if(check(d)){ min_d = d+1;}
            else{max_d =d-1;}
        }
        cout<<max_d<<endl;
    }
    
    return 0;
}