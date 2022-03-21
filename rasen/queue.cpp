// ラウンドロビンスケジューリングをシミュレートするプログラムを作成せよ。

// input
// 最初の行でプロセス数を表す整数nとクオンタムを表す整数qが空白区切りで与えられる。
// 続くn行で各プロセスの名前nameと整数timeが空白区切りで与えられる。

// output
//プロセスが完了した順に各プロセスの名前と終了時刻を空白で区切って1行ごとに出力してください。

// 1 <= n <= 100000
// 1 <= q <= 1000
// 1 <= time <= 50000
// 1 <= nameの長さ <= 10
// 1 <= timeの合計 <= 1000000

#include <iostream>
#include <cstdlib>
#include <string>
#include <typeinfo>
using namespace std;

int head, tail, n, q;

struct Pinfo{
    char name[15];
    int t;
};

void enqueue(Pinfo Q[], Pinfo x){
    Q[tail] = x;
    tail = (tail+1) % (2*n);
}

Pinfo dequeue(Pinfo Q[]){
    Pinfo x = Q[head];
    head = (head+1) % (2*n);
    return x;
}

int main(){
    cout << "Hello, Please enter the number of process and quantum. ex) 3 100\n";
    cin >> n >> q;
    Pinfo *Q = new Pinfo[2*n];
    cout << "Please enter information f each process.\n";
    for (int i=0; i<n; i++) cin >> Q[i].name >> Q[i].t;
    head = 0;
    tail = n;

    cout << "\nResult of simulation is as follows:\n";
    int finish_time = 0;
    while (head != tail){
        Pinfo process = dequeue(Q);
        if (process.t - q <= 0){
            cout << process.name << " " << process.t + finish_time << "sec\n";
            finish_time += process.t;
        }else{
            process.t -= q;
            enqueue(Q, process);
            finish_time += q;
        }
    }
    system("pause");
    return 0;
}