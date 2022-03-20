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
#include <string>
#include <typeinfo>
using namespace std;

int top, stack[1000];

void push(int x){
    top++;
    stack[top] = x;
}

int pop(){
    int value = stack[top];
    top--;
    return value;
}

int main(){
    cout << "Hello, Please enter the RPN formula.\n";
    char s[100];
    while (cin >> s){
        if (s[0] == '*'){
            int a = pop();
            int b = pop();
            push(a*b);
        }else if (s[0] == '+'){
            int a = pop();
            int b = pop();
            push(a+b);
        }else if (s[0] == '-'){
            int a = pop();
            int b = pop();
            push(b-a);
        }else{
            push(atoi(s));
        }
    }
    int ans = pop();
    cout << "Answer : " << ans << "\n";
    system("pause");
    return 0;
}