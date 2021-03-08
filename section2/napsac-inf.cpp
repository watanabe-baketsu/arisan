#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n, weight;
    cin >> n >> weight;
    int w[n], v[n];
    for(int i=0;i<n;i++)cin >> w[i];
    for(int i=0;i<n;i++)cin >> v[i];

    int dp[n+1][weight+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<=weight;j++){
            if(j<w[i]){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = max(dp[i][j],dp[i+1][j-w[i]]+v[i]);
            }
        }
    }
    printf("sum of value : %d\n",dp[n][weight]);
}