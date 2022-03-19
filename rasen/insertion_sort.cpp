// N個の要素を含む数列Aを昇順に並び替える挿入ソートのプログラムを作成せよ。
// 1<=N<=100
// 0<=Ai<=1000

// input
// 1行目：数列の長さN
// 2行目：N個の整数、空白区切り

#include <iostream>
using namespace std;

int count;

// 配列の要素を順番に出力
void trace(int A[],int N){
    int i;
    for(i=0;i<N;i++){
       cout << A[i];
       cout << " ";
    }
    cout << "\n";
}

// 挿入ソート
void insertion_sort(int A[], int N){
    int i,j,v;
    for(i=1;i<N;i++){
        v = A[i];
        j = i-1;
        while(j>= 0 && A[j]>v){
            A[j+1] = A[j];
            j--;
            count++;
        }
        A[j+1] = v;
    }
    trace(A,N);
}

int main(){
    cout << "Hello, Please enter the N.\n";
    int N;
    cin >> N;
    int *A = new int[N];
    int i = 0;
    cout << "Please enter the array contents. ex)1 2 3 4 5\n";
    cout << "and, enter 'ctrl + Z' at the end of array.\n";
    int k;
    while(cin >> k){
        A[i] = k;
        i++;
    }
    count = 0;
    insertion_sort(A,N);
    cout << "The number of swap : " << count << "\n";

    system("pause");

    return 0;
}