// 整数nを入力し、深さnの再起呼び出しによって作成されるコッホ曲線の頂点の座標を出力せよ。

// input:n
// コッホ曲線の各頂点の座標を1行ずつ出力。

// 0 <= n <= 6

#include <iostream>
#include <math.h>
using namespace std;

struct Point {double x, y;};

void koch(int n, Point a, Point b){
    if (n == 0) return;

    Point s, t, u;
    double th = M_PI * 60.0 / 180.0;

    s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
    s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
    t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
    t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) - (t.y - s.y) * cos(th) + s.y;
    
    koch(n-1, a, s);
    cout << s.x << " " << s.y << endl;
    koch(n-1, s, u);
    cout << u.x << " " << u.y << endl;
    koch(n-1, u, t);
    cout << t.x << " " << t.y << endl;
    koch(n-1, t, b);
}

main(){
    Point a, b;
    int n;
    cout << "Please enter the value of n.\n";
    cin >> n;

    a.x = 0;
    a.y = 0;
    b.x = 100;
    b.y = 0;

    cout << "The followings are the answers.\n";
    cout << a.x << " " << a.y << endl;
    koch(n, a, b);
    cout << b.x << " " << b.y << endl;

    system("pause");
    return 0;    
}
