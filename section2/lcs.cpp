#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    char s[n], t[m];
    for(int i=0;i<n;i++)cin >> s[i];
    for(int i=0;i<m;i++)cin >> t[i];

    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i]==t[j]){
                dp[i+1][j+1] = dp[i][j]+1;
            }else{
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    printf("lcs : %d\n",dp[n][m]);
}