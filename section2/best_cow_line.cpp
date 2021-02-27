#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    char s[N];
    for(int i=0;i<N;i++)cin >> s[i];
    int l = 0;
    int r = N-1;
    while(l<=r){
        bool h = false;
        for(int j=0;l+j<r-j;j++){
            if(s[l+j]<s[r-j]){
                h = true;
                break;
            }else if(s[l+j]>s[r-j]){
                break;
            }
        }
        if(h)putchar(s[l++]);
        else putchar(s[r--]);
    }
}