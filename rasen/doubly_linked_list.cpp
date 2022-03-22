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

struct Node{
    int key;
    Node *next, *prev;
};

Node *nil;

Node* listSearch(int key){
    Node *cur = nil->next;
    while (cur != nil && cur->key != key) cur = cur->next;
    return cur; 
}

void init(){
    nil = (Node *)malloc(sizeof(Node));
    nil->next = nil;
    nil->prev = nil;
}

void printList(){
    Node *cur = nil->next;
    printf("\nThis is a result.\n");
    while (1){
        if (cur == nil) break;
        printf("%d ",cur->key);
        cur = cur->next;
    }
    printf("\n");
}

void deleteNode(Node *target){
    if (target == nil) return;
    target->prev->next = target->next;
    target->next->prev = target->prev;
    free(target);
}

void deleteFirst(){
    deleteNode(nil->next);
}

void deleteLast(){
    deleteNode(nil->prev);
}

void deleteKey(int key){ // delete x
    deleteNode(listSearch(key));
}

void insert(int key){
    Node *x = new Node[sizeof(Node)];
    x->key = key;
    x->next = nil->next;
    x->prev = nil;
    nil->next->prev = x;
    nil->next = x;
}

int main(){
    int key, n;
    printf("Please enter the number of instructions.\n");
    scanf("%d",&n);
    init();
    printf("Please enter the instructions.\n");
    char com[20];
    for (int i=0;i<n;i++){
        scanf("%s%d",com,&key);
        if (com[0] == 'i') insert(key);
        else if (com[0] == 'd'){
            if (strlen(com) > 6){
                if (com[6] == 'F') deleteFirst();
                else deleteLast();
            }else deleteKey(key);
        }
    }
    printList();
    system("pause");

    return 0;
}