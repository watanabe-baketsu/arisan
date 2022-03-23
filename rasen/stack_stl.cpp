// 逆ポーランド記法で与えられた数式の計算結果を出力せよ。

// 1つの数式が一行で与えられる。空白区切り。
// ex) 1 2 + 3 4 - *
// ans: -3 : (1+2)*(3-4) = -3

// 演算子は +, -, *　のみ
// 2 <= 式に含まれるオペランドの数 <= 100
// 1 <= 式に含まれる演算子の数 <= 99
// オペランドは正の整数、10**6以下

#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

int main(){
    stack<int> S;
    int a, b, x;
    cout << "Hello, Please enter the RPN formula.\n";
    string s;

    while (cin >> s){
        if (s[0] == '*'){
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            S.push(a*b);
        }else if (s[0] == '+'){
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            S.push(a+b);
        }else if (s[0] == '-'){
            a = S.top();
            S.pop();
            b = S.top();
            S.pop();
            S.push(b-a);
        }else{
            S.push(atoi(s.c_str()));
        }
    }
    int ans = S.top();
    cout << "Answer : " << ans << "\n";
    system("pause");
    return 0;
}