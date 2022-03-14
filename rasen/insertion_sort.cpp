// N個の要素を含む数列Aを昇順に並び替える挿入ソートのプログラムを作成せよ。
// 1<=N<=100
// 0<=Ai<=1000

// input
// 1行目：数列の長さN
// 2行目：N個の整数、空白区切り

#include <iostream>
using namespace std;

// 配列の要素を順番に出力
void trace(int A[],int N){
    int i;
    for(i=0;i<N;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

// 挿入ソート
void insertion_sort(int A[], int N){
    int i,j,v;
    for(i=1;i<N;i++){
        v = A[i];
        for(j=i-1;A[j]>v;j--){
            A[j]= A[j+1];
        }
        A[j+1] = v;
    }
    trace(A,N);
}

int main(){
    int A[100];
    int N,j;
    cin >> N;
    int i = 0;
    int Ai;
    while(cin>>Ai){
        A[i] == Ai;
        i++;
    }
    trace(A,N);
    insertion_sort(A,N);

    return 0;
}