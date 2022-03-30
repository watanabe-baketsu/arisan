// n個の整数を含む数列Sとq個の誠意数を含む数列Tにおいて
// Tに含まれる整数の中でSに含まれるものの個数Cを出力せよ。

// input 
// 1行目:n
// 2行目:n個の整数空白区切り
// 3行目:q
// 4行目:q個の整数空白区切り

// output:C

// Sの要素は昇順に整列されている。
// n<=100000
// q <= 50000, Tの要素は互いに異なる。

#include <iostream>
using namespace std;

bool binarySearch(int S[], int n, int key){
    int left = 0;
    int right = n;
    int mid;

    while (left < right){
        mid = (left+right)/2;
        if (S[mid] < key) left = mid + 1;
        else if (S[mid] > key) right = mid;
        else if (S[mid] == key) return true;
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
    for (int i=0;i<q;i++) cin >> T[i];

    int sum = 0;
    for (int i=0;i<q;i++){
        if (binarySearch(S, n, T[i]) == true) sum++;
    }
    
    cout << "The number of the match is " << sum << ".\n";

    system("pause");
    return 0;
}