#include<bits/stdc++.h>
using namespace std;
int n;
int A[10][10000];
vector<int> x;
vector<int> y;
int main(){
    cin>>n;
    int a;
    for(int i=1;i<=n;i++){
        for(int j =1;j<=4;j++){
            cin>>a;
            A[j][i]=a;
            if(j==1||j==3) {x.push_back(a);}
            else {y.push_back(a);}
        }
    }
    
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int l = x[2*n-1]-x[0];
    int w = y[2*n-1]-y[0];
    cout <<l*w<<endl;
    return 0;

}