#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
int lcs(string x, string y, int n, int m){
    if(n==0 || m==0) return 0;
    else if(t[n][m]!=-1) return t[n][m];
    else if(x[n-1]==y[m-1]){
        return t[n][m] = 1 + lcs(x,y,n-1,m-1);
    }
    else {
        return t[n][m] = max(lcs(x,y,n-1,m), lcs(x,y,n,m-1));
    }
}
int main(){
    memset(t,-1,sizeof(t));
    string x,y;
    cin>>x>>y;
    int n = x.length();
    int m = y.length();

    int mx = lcs(x,y,n,m);
    cout<<mx;
}