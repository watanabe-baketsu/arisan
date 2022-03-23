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
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    string name;
    int n, quantum, t;
    queue<pair<string, int>> Q; //プロセス格納用キュー

    cout << "Hello, Please enter the number of process and quantum. ex) 3 100\n";
    cin >> n >> quantum;
    cout << "Please enter information f each process.\n";
    for (int i=0;i<n;i++){
        cin >> name >> t;
        Q.push(make_pair(name, t));
    }

    cout << "\nResult of simulation is as follows:\n";
    int finish_time = 0;
    pair<string, int> u;
    while (!Q.empty()){
        u = Q.front();
        Q.pop();
        if (u.second - quantum <= 0){
            cout << u.first << " " << u.second + finish_time << "sec\n";
            finish_time += u.second;
        }else{
            u.second -= quantum;
            Q.push(u);
            finish_time += quantum;
        }
    }
    system("pause");
    return 0;
}