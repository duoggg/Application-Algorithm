#include<bits/stdc++.h>
using namespace std;
int n;
int A[1000000];
int MaxLeft(int lo, int mi){
    int s =0;
    int maxi=A[mi];
    for(int i = mi;i>=lo;i--){
        s+=A[i];
        maxi= max(s,maxi);
    }
    return maxi;
}

int MaxRight(int mi, int hi){
    int maxi=A[mi];
    int s=0;
    for(int i=mi;i<=hi;i++){
        s+=A[i];
        maxi= max(s,maxi);

    }
    return maxi;
}
int MaxSub(int low, int high){
    if(low==high) return A[low];
    int mid = (low+high)/2;
    int wL = MaxSub(low,mid);
    int wR = MaxSub(mid+1,high);
    int maxLM = MaxLeft(low,mid);
    int maxRM = MaxRight(mid+1,high);
    int wM = maxLM+maxRM;
    return max(max(wL,wR),wM);
}
int main(){
    cin>>n;
    for(int i= 0;i<n;i++ ){
        cin>>A[i+1];
    }
    cout<<MaxSub(1,n)<<endl;
    return 0;
}

