#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>> n;
    cin >>m;
    deque<string> d;
    int a;
    string b;
    for(int i=0;i<n;i++){
        cin>>a;
        b = to_string(a);
        int k = m-b.size();
        string str(k,'0');
        str.append(b);
        d.push_back(str);
    }
    for(int i =0;i<n;i++){
        cout<< d.front()<<endl;
        d.pop_front();

    }
    return 0;
}