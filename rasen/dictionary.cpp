// 以下の命令を実行する簡易的な「辞書」を実装せよ。
// insert str ：辞書に文字列strを追加する。
// find str ：その時点で辞書にstrが含まれる場合'yes'、含まれない場合'no'と出力する。

// input
// 1行目：命令数n
// 2行目以降：各命令

// output : yes or no

// 与えられる文字列は'A','C','G','T'の4種類の文字から構成される。
// 1 <= 文字列の長さ <= 12
// n <= 1000000

#include <iostream>
#include <cstring>
using namespace std;

#define M 1046527
#define NIL -1
#define L 14

char H[M][L];

int getchar(char ch){
    if (ch == 'A') return 1;
    else if (ch== 'C') return 2;
    else if (ch== 'G') return 3;
    else if (ch== 'T') return 4;
    else return 0;
}

long long getkey(char str[]){
    long long sum = 0, p = 1, i;
    for (i=0; i<strlen(str); i++){
        sum += p*(getchar(str[i]));
        p *= 5;
    }
    return sum;
}

int h1(int key){ return key % M; }
int h2(int key){ return 1 + (key % M-1); }

int find(char str[]){
    long long key, i, h;
    key = getkey(str);
    for (i = 0; ; i++){
        h = (h1(key) + i * h2(key)) % M;
        if (strcmp(H[h], str) == 0) return 1;
        else if (strlen(H[h]) == 0) return 0;
    }
    return 0;
}

void insert(char str[]){
    long long key, i, h;
    key = getkey(str);
    for (i=0; ; i++){
        h = (h1(key) + i * h2(key)) % M;
        if (strlen(H[h]) == 0){
            strcpy(H[h], str);
            break;
        }
    }
}

int main(){
    int n;
    cout << "Please enter the n.\n";
    cin >> n;
    cout << "Please enter the instructions.\n";
    char str[L];
    char inst[9];
    for (int i=0; i<n; i++){
        cin >> inst >> str;
        if (inst[0] == 'i') insert(str);
        else if (inst[0] == 'f'){
            if (find(str) == 1) cout << "yes\n";
            else cout << "no\n";
        }
        else cout << "\nAn error occured.\n";
    }

    system("pause");
    return 0;
}