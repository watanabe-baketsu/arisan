// 以下の4つの命令を受け付ける双方向連結リストを実装せよ。
// insert x : 連結リストの先頭にキーxを持つ要素を継ぎ足す。
// delete x : キーxを持つ最初の要素を連結リストから削除する。
// deleteFirst : 連結リストの先頭要素を削除する。
// deleteLast : 連結リストの末尾の要素を削除する。

// input
// 1行目：命令数n
// 2行目以降：各命令

// output
// すべての命令が終了した時点での連結リスト内のキーを順番に出力。空白区切り。

// 1 <= n <= 2000000
// delete x の回数は20回を超えない
// 0 <= x <= 10**9
// リストの要素数は命令の過程で10**6を超えない。

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
using namespace std;

int main(){
    int key, n;
    printf("Please enter the number of instructions.\n");
    scanf("%d",&n);
    list<int> L;
    printf("Please enter the instructions.\n");
    char com[20];
    for (int i=0;i<n;i++){
        scanf("%s%d",com,&key);
        if (com[0] == 'i') L.push_front(key);
        else if (com[0] == 'd'){
            if (strlen(com) > 6){
                if (com[6] == 'F') L.pop_front();
                else L.pop_back();
            }else{
                for (list<int>::iterator it = L.begin();it != L.end(); it++){
                    if (*it == key){
                        L.erase(it);
                        break;
                    }
                }
            }
        }
    }
    printf("\nThe followings are the result of the program.\n");
    for (list<int>::iterator it = L.begin(); it != L.end(); it++){
        printf("%d ", *it);
    }
    printf("\n");
    system("pause");

    return 0;
}

