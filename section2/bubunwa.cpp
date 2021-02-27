#include <iostream>
using namespace std;

int n,k;
int a[100];
bool dfs(int i, int sum){
    if(i==n)return sum==k;

    //a[i]を使う場合
    if(dfs(i+1, sum+a[i]))return true;
    //a[i]を使わない場合
    if(dfs(i+1, sum))return true;

    return false;
}

int main(){
    cin >> n >> k;
    int l;
    int i = 0;
    while(cin>>l){
        a[i] = l;
        i++;
    }
    if(dfs(0,0))printf("Yes\n");
    else printf("No\n");
}
