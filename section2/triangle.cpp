#include <iostream>
using namespace std;

int MAX_N = 100;
int n;
int a[100];

void solve(){
    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                int len = a[i] + a[j] + a[k];
                int max_bar_len = max(a[i],max(a[j],a[k])); //一番長い棒の長さ
                int rest_len = len - max_bar_len;//残りの棒の長さの和

                if(max_bar_len<rest_len){
                    ans = max(len, ans);
                }
            }
        }
    }
    if(ans != 0){
        printf("最大長　%d",ans);
    }else{
        printf("-1");
    }

}

int main(){
    int i = 0;
    cin >> n;
    int l;
    while(cin>>l){
        a[i] = l;
        i++;
    }
    solve();
}
