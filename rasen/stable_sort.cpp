// N枚のトランプを読み込み、バブルソート及び選択ソートで昇順に並び替え出力するプログラムを作成せよ。
// また、それぞれで行われた要素の交換回数も出力せよ。
// 数字が基準。同じ数字で記号が異なる場合、入力順と同じ順番で出力される場合を「stable」という。
// 各アルゴリズムの出力がstableかどうかも出力せよ。

// input
// 1行目：トランプの枚数N
// 2行目：トランプの種類、空白区切り

// output
// 1行目：バブルソートによる並び替え後の結果
// 2行目：バブルソートがstableかnot stableか
// 3行目：要素の入れ替え回数
// 4行目：選択ソートによる並び替え後の結果
// 5行目：選択ソートがstableかnot stableか
// 6行目：要素の入れ替え回数

#include <iostream>
using namespace std;

struct Card{char mark, value;};//カード入力受付用構造体

// 配列の要素を順番に出力
void trace(struct Card A[],int N){
    int i;
    for(i=0;i<N;i++){
       cout << A[i].mark << A[i].value;
       cout << " ";
    }
    cout << "\n";
}

void swap(struct Card A[], int a, int b){
    Card c = A[a];
    A[a] = A[b];
    A[b] = c;
}

bool isStable(struct Card A1[], struct Card A2[], int N){
    for(int i=0;i<N;i++){
        if(A1[i].mark != A2[i].mark)return false;
    }
    return true;
}

int bubble_sort(struct Card A[], int N){
    int i = 0; // ソート済み部分列のインデックス
    int j;
    int count = 0;
    bool flag = 1;
    while(flag){
        for(j=N-1;j>=i+1;j--){
            if(A[j].value<A[j-1].value){
                swap(A, j, j-1);
                count++;
            }
        }
        i++;
        if(i==N-1) flag = 0;
    }
    cout << "The contents after the bubble_sort is as follows:\n";
    trace(A,N);
    return count;
}

int selection_sort(struct Card A[], int N){
    int count = 0;
    int i, j;
    for(i=0;i<N-1;i++){
        int minj = i;
        for(j=i+1;j<N;j++){
            if(A[minj].value > A[j].value) minj = j;
        }
        if(i != minj){
            swap(A,i,minj);
            count++;
        }
    }
    cout << "The contents after the selection_sort is as follows:\n";
    trace(A,N);
    return count;
}

int main(){
    cout << "Hello, Please enter the N.\n";
    int N;
    cin >> N;
    Card *bubble = new Card[N];
    Card *selection = new Card[N];
    cout << "Please enter the array contents. ex)D1 C2 S3 H4 C5\n";
    cout << "and, enter 'ctrl + Z' at the end of array.\n";
    for(int i=0;i<N;i++)cin >> bubble[i].mark >> bubble[i].value;
    for(int i=0;i<N;i++)selection[i] = bubble[i];

    int count_bubble, count_selection;
    count_bubble = bubble_sort(bubble, N);
    cout << "The bubble_sort output is always stable.\n";
    cout << "The number of swap : " << count_bubble << "\n\n";
    
    count_selection = selection_sort(selection, N);
    if(isStable(bubble, selection, N)){
        cout << "The selection_sort output is stable.\n";
    }else{
        cout << "The selection_sort output is not stable.\n";
    }
    cout << "The number of swap : " << count_selection << "\n";
    system("pause");

    return 0;
}