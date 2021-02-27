#include <iostream>
using namespace std;

int main(){
    int max_n = 10^6;
    int l, n, x[max_n];
    cin >> l >> n;
    int i = 0;
    int distance;
    while(cin>>distance){
        x[i] = distance;
        i++;
    }
    int minT = 0;
    int maxT = 0;
    for(int i=0; i<n; i++){
        minT = max(minT,min(x[i], l-x[i]));
        maxT = max(maxT,max(x[i], l-x[i]));
    }
    printf("最小：%d\n",minT);
    printf("最大：%d",maxT);
    return 0;
}