#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    cin>>n;
    cin>>m;
    string a;
    int l = 256%m;
    for(int i=1;i<=n;i++){
        cin>>a;
        int k = a.size();
        long long t =0;
        for(int i =0;i<k;i++){
             //cout<<a[i]*1<<' ';
            t+=(long long)a[i]*pow(l,k-i-1);
        }
         //cout<<t<<' ';
        cout<<t%m<<endl;
    }
    return 0;
}