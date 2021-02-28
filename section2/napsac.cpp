#include <iostream>
#include <cstring>
using namespace std;

int solve(int i, int j, int dp[][5], int n, int w[], int v[]){
    if(dp[i][j] >= 0){
        return dp[i][j];
    }
    int res;
    if(i==n){
        res = 0;
    }else if(j<w[i]){
        res = solve(i+1,j,dp,n,w,v);
    }else{
        res = max(solve(i+1,j,dp,n,w,v), solve(i+1,j-w[i],dp,n,w,v)+v[i]);
    }
    return dp[i][j] = res;
}

int main(){
    int n,weight;
    cin >> n;
    cin >> weight;
    int w[n], v[n];

    for(int i=0;i<n;i++)cin >> w[i];
    for(int i=0;i<n;i++)cin >> v[i];

    int dp[5][5];
    //dpの初期化
    memset(dp, -1, sizeof(dp));
    printf("sum of value = %d\n",solve(0,weight,dp,n,w,v));
}