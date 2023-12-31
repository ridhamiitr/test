#include<bits/stdc++.h>
using namespace std;
string print_lcs(string x, string y, int m, int n){
    int t[m+1][n+1];
    for(int i=0; i<m+1; ++i){
        for(int j=0; j<n+1; ++j){
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }

    for(int i=1; i<m+1; ++i){
        for(int j=1; j<n+1; ++j){
            if(x[m-1]==y[n-1]){
                t[i][j] = 1+t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    string lcs;
    int i = m;
    int j = n;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            lcs.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i-1][j]>t[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    return lcs;
    //hello
}    
int main(){
    string x,y;
    cin>>x>>y;
    int m = x.length();
    int n = y.length();
    string lcs = print_lcs(x,y,m,n);

    reverse(lcs.begin(),lcs.end());
    cout<<lcs;
}