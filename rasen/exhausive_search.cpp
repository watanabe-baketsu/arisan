// 長さnの数列Aと整数mに対してAの要素の中のいくつかの要素を足し合わせてmが作れるかどうか判定するプログラムを実装せよ。
// Aの各要素は1度だけ使用することができる。
// 数列Aが与えられたうえで質問としてq個のmiが与えられるためそれぞれについてyesかnoを出力せよ。

// input
// 1行目：n
// 2行目：Aの要素（空白区切り）
// 3行目：q
// 4行目：q個の整数mi

// n <= 20
// q <= 200
// 1 <= Aの要素 <= 2000
// 1 <= mi <= 2000

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> A;

bool solve(int i, int m){
    if (m == 0) return true;
    if (i >= n) return false;
    bool ans = solve(i+1, m-A[i]) || solve(i+1, m);
    return ans;
}

main(){
    cout << "Please enter the n.\n";
    cin >> n;
    cout << "Please enter the contents of A.\n";
    int x;
    for (int i=0;i<n;i++){
        cin >> x;
        A.push_back(x);
    }
    cout << "Please enter the q.\n";
    int q;
    cin >> q;
    vector<int> M;
    cout << "Please enter the contents of M.\n";
    for (int i=0;i<q;i++){
        cin >> x;
        M.push_back(x);
    }

    cout << "The followings are the answers.\n";
    for (int i=0;i<q;i++){
        if (solve(0, M[i]) == true) cout << M[i] << " : yes\n";
        else cout << M[i] << " : no\n";
    }

    system("pause");

}