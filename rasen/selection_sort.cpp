// N個の要素を含む数列Aを読み込み、選択ソートで昇順に並び替え出力するプログラムを作成せよ。
// また、選択ソートで行われた要素の交換回数も出力せよ。
// 1<=N<=100, 0<=Ai<=100

// input
// 1行目：数列の長さN
// 2行目：N個の整数、空白区切り
#include <iostream>
using namespace std;

// 配列の要素を順番に出力
void trace(int A[],int N){
    int i;
    for(i=0;i<N;i++){
       cout << A[i];
       cout << " ";
    }
    cout << "\n";
}

void swap(int A[], int a, int b){
    int c = A[a];
    A[a] = A[b];
    A[b] = c;
}

// 選択ソート
int selection_sort(int A[], int N){
    int count = 0;
    int i, j;
    for(i=0;i<N-1;i++){
        int minj = i;
        for(j=i+1;j<N;j++){
            if(A[minj] > A[j]) minj = j;
        }
        if(i != minj){
            swap(A,i,minj);
            count++;
        }
    }
    trace(A,N);

    return count;
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
    trace(A,N);
    int count;
    count = selection_sort(A,N);
    cout << "The number of swap : " << count << "\n";

    system("pause");

    return 0;
}