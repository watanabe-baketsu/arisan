#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int a[n], m[n];
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> m[i];

    int dp[k];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            if(dp[j]>=0){
                dp[j] = m[i];
            }else if(j<a[i] || dp[j-a[i]]<=0){
                dp[j] = -1;
            }else{
                dp[j] = dp[j-a[i]] - 1;
            }
        }
    }
    if(dp[k]>=0)printf("Yes, we can make the number.\n");
    else printf("No, we cannot make the number.\n");
}