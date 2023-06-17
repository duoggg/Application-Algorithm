#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> Adj[10000];
vector<int> bVisited(10000,0);
stack<int> check;
vector<int> popcout(10000,0);
int t =0;
void DFS(){
    while(t<n){
      if(!check.empty()){
        int a = check.top();
        if(popcout[a]==0){cout<<a<<' ';popcout[a]=1;t++;}
        check.pop();
        int n = Adj[a].size();
        if(n>0){
            for(int i =n-1;i>=0;i--){
                int b = Adj[a][i];
                if(bVisited[b]==0) {check.push(b); bVisited[b]=1;}
                else if(bVisited[b]==1&&popcout[b]==0) {check.push(b);}
            }
        }
        }
       else{
        int i =1;
        while(i<=n&&bVisited[i]==1){
            i++;
        }
        check.push(i);

       }
       

    }
}

int main(){
    cin>>n;
    cin>>m;
    int a,b;
    for(int i =1;i<=m;i++){
        cin>>a;
        cin>>b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(Adj[i].begin(),Adj[i].end());
    }
    check.push(1);
    bVisited[1]=1;
    DFS();
    return 0;
}