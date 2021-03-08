#include <iostream>
using namespace std;

int INF = 1000;

int main(){
    int n, weight;
    cin >> n >> weight;
    int w[n], v[n];
    for(int i=0;i<n;i++)cin >> w[i];
    int max_v = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(max_v<v[i])max_v = v[i];
    }
    int dp[n+1][n*max_v+1];
    fill(dp[0],dp[0]+n*max_v+1,INF);
    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=n*max_v+1;j++){
            if(j<v[i]){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = min(dp[i][j],dp[i][j-v[i]]+w[i]);
            }
        }
    }
    int res = 0;
    for(int i=0;i<=n*max_v;i++)if(dp[n][i]<=weight)res = i;
    printf("sum of value : %d\n",res);
}