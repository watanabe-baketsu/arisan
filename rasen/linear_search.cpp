// n個の整数を含む数列Sとq個の誠意数を含む数列Tにおいて
// Tに含まれる整数の中でSに含まれるものの個数Cを出力せよ。

// input 
// 1行目:n
// 2行目:n個の整数空白区切り
// 3行目:q
// 4行目:q個の整数空白区切り

// output:C

// n<=10000
// q <= 500, Tの要素は互いに異なる。

#include <iostream>
using namespace std;

bool search(int A[], int n, int key){
    for (int i=0;i<n;i++){
        if (A[i] == key) return true;
    }
    return false;
}

int main(){
    int n, q;
    cout << "Please enter the n.\n";
    cin >> n;
    int *S = new int[n];
    cout << "Please enter the contents of S.\n";
    for (int i=0;i<n;i++) cin >> S[i];
    cout << "Please enter the q.\n";
    cin >> q;
    int *T = new int[q];
    cout << "Please enter the contents of T.\n";
    for (int i=0;i<n;i++) cin >> T[i];

    int sum = 0;
    for (int i=0;i<n;i++){
        if (search(S, n, T[i]) == true) sum++;
    }

    cout << "The number of the match is " << sum << ".\n";
    system("pause");
    return 0;
}