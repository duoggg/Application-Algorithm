#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int n;

long long MaxMid(int lo,int mid, int hi){
    long long s =0;
   long long leftO = -999;
    long long leftE = -999;
    for(int i= mid; i>=lo;i--){
        s+=a[i];
        if(s%2==0) leftE = max(leftE,s);
        else leftO = max(leftO,s);
    }
    
    s =0;
    long long rightO = -999;
    long long rightE = -999;
    for(int i= mid+1; i<=hi;i++){
        s+=a[i];
        if(s%2==0) rightE = max(rightE,s);
        else rightO = max(rightO,s);
    }
    
    return max(rightO+leftO,rightE+leftE);
    
}

long long MaxEvenSub(int lo, int hi){
    if(lo==hi){
        if(a[lo]%2==0) return a[lo];
        else return -999;
    }
    int mid = (lo+hi)/2;
    int wL = MaxEvenSub(lo,mid);
    int wR = MaxEvenSub(mid+1,hi);   
  
    int wM = MaxMid(lo,mid,hi);
    return max(max(wL,wR),wM);


}

int main(){
    cin>>n;
    for(int i =1;i<=n;i++){
        cin>>a[i];
    }
    int b = MaxEvenSub(1,n);
    if(b<-10000) cout<<"NOT_FOUND"<<endl;
    else cout<<MaxEvenSub(1,n)<<endl;
    return 0;

}