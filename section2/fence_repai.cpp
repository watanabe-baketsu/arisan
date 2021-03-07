#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int l[N];
    for(int i=0;i<N;i++)cin >> l[i];
    int ans=0;
    while(N>1){
        int min1=0, min2=1;
        if(l[min1]>l[min2])swap(min1,min2);
        for(int i=2;i<N;i++){
            if(l[min1]>l[i]){
                min2 = min1;
                min1 = i;
            }else if(l[min2]>l[i]){
                min2 = i;
            }
        }
        int total = l[min1]+l[min2];
        ans += total;
        l[min1] = total;
        l[min2] = l[N-1];
        N--;
    }
    printf("sum of cost : %d\n",ans);
}