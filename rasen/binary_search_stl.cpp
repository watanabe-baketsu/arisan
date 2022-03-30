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
#include <algorithm>
using namespace std;

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
        if (*lower_bound(S, S+n, T[i]) == T[i]) sum++;
    }
    
    cout << "The number of the match is " << sum << ".\n";

    system("pause");
    return 0;
}