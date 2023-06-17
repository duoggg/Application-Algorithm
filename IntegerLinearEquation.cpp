#include<bits/stdc++.h>
using namespace std;

int M;
int n;
int f = 0;
int c = 0;
int sum=0;
int a[20];
int t[20];

void Solution(){
    if(f==M) c++;
}
void Try(int k){
for ( int i =1; i <= (M-f-t[n]+t[k])/a[k] ; i ++) {
    f = f+ a[k]*i;
    if ( k == n) Solution();
    else Try(k +1);
    f = f -a[k]*i ;
 }
}

int main(){
    
    cin>>n;
    cin>>M;
    
    for(int i =1;i<=n;i++){
        cin>>a[i];
        if(i>1) t[i] = t[i-1]+a[i]; 
        else t[i] = a[i];
    }
    
    Try(1);
    cout<<c<<endl;
    return 0;

}