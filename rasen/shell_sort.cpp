// N個の要素を含む数列Aを読み込み、シェルソートで昇順に並び替え出力するプログラムを作成せよ。
// また、シェルソートで行われた要素の交換回数も出力せよ。
// 1<=N<=100, 0<=Ai<=100

// input
// 1行目：数列の長さN
// 2行目：N個の整数、空白区切り

#include <iostream>
#include <vector>
using namespace std;

long long count;
vector<int> G;

// 配列の要素を順番に出力
void trace(int A[],int N){
    int i;
    for(i=0;i<N;i++){
       cout << A[i];
       cout << " ";
    }
    cout << "\n";
}

// 間隔"g"を指定した挿入ソート
void insertion_sort(int A[], int N, int g){
    int i,j,v;
    for(i=g;i<N;i++){
        v = A[i];
        j = i-g;
        while(j>= 0 && A[j]>v){
            A[j+g] = A[j];
            j -= g;
            count++;
        }
        A[j+g] = v;
    }
}

void shell_sort(int A[], int N){
    // 間隔"g"のパターンを格納する数列Gを生成
    for(int i=1; ;){
        if(i>N) break;
        G.push_back(i);
        i = 3*i+1;
    }
    for(int i=G.size()-1; i>=0; i--) insertion_sort(A, N, G[i]);
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
    shell_sort(A,N);
    cout << "The number of swap : " << count << "\n";
    system("pause");

    return 0;
}