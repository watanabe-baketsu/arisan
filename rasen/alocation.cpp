// 重さがそれぞれwi(i=0,1,2...n-1)のn個の荷物を順番にk台のトラックに積む。
// 各トラックには連続する0個以上の荷物を積むことができるが最大積載量Pを超えてはならない。
// 最大積載量Pはすべてのトラックで共通。
// n, k, wiが与えられるとき、すべての荷物を積むために必要なPの最小値を出力せよ。

// input
// １行目：n k(空白区切り)
// ２行目：ni(空白区切り)

// 1 <= n <= 100000
// 1 <= k <= 100000
// 1 <= wi <= 10000

#include <iostream>
using namespace std;

int n, k;

int check(long long P, int W[]){
    int j = 0;
    for (int i=0;i<k;i++){
        long long sum = 0;
        while (sum + W[j] <= P){
            sum += W[j];
            j++;
            if (j == n) return n;
        }
    }
    return j;
}

int solve(int W[]){
    long long left = 0;
    long long right = 10000 * n; // 荷物の最大重量*個数
    long long mid;
    while (right - left > 1){
        mid = (left + right) / 2;
        int a = check(mid, W);
        if (a >= n) right = mid;
        else if (a < n) left = mid;
    }
    return right;
}

main(){
    cout << "Please enter the n and k.\n";
    cin >> n >> k;
    cout << "Please input each value of w.\n";
    int *W = new int[n];
    for (int i=0;i<n;i++)cin >> W[i];

    long long ans = solve(W);
    cout << "This is the minimum value of P : " << ans << endl;

    system("pause");
}
