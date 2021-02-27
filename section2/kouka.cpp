#include <iostream>
using namespace std;

int main(){
    int C[6] = {500, 100, 50, 10, 5, 1};
    int P[6];
    int A;
    cin >> A;
    for(int j=0;j<6;j++){
        cin >> P[j];
    }
    int count = 0;
    for(int i=0;i<6;i++){
        int t = min(A/C[i], P[i]);
        A = A - t*C[i];
        count += t;
        printf("%d円玉%d枚\n",C[i],t);
    }
    printf("硬貨合計%d枚\n",count);
}