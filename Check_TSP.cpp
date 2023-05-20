#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<int,int> m;
    map<int,int> M;
    int a;
    
    for(int i =1;i<=n;i++){
        cin>>a;
        m[a] =i;
        M[i] =a;
    }
    int A[10000][10000];
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            cin>>a;
            A[i][j]=a;
        }
    }
    int b,c;
    int k =1;
    for(int i =1;i<=n;i++){
        cin>>b; cin>>c;
        if(m[b]>m[c]) k =0;
    }
    if(k==0) cout << -1 << endl;
    else{
        int sum =0;
        for(int i =1;i<=n;i++){
            if(i!=n)  sum += A[M[i]][M[i+1]];
            else sum += A[M[n]][M[1]];
        }
        cout<<sum<<endl;
    }
    return 0;
}