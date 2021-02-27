#include <iostream>
#include <queue>
using namespace std;

const int INF = 1000000;
typedef pair<int, int> P;

char meiro[100][100];
int N, M;
int sx, sy; //startの座標
int gx, gy; //goalの座標

int dist[100][100]; //各点までの座標
//移動方向の4ベクトル
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int solver(){
    queue<P> que;
    //distanceを全てをinfで初期化
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dist[i][j] = INF;
        }
    }
    //キューにスタート地点を入れて、距離を0にする。
    que.push(P(sx,sy));
    dist[sx][sy] = 0;

    //キューが空になるまで繰り返す。
    while(que.size()){
        //キューの先頭を取り出す。
        P p = que.front();
        que.pop();
        //4方向ループ
        for(int i=0;i<4;i++){
            //移動した点を(nx,ny)として、移動可能な座標であればキューに追加する
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M && meiro[nx][ny]!='#' && dist[nx][ny]==INF){
                que.push(P(nx,ny));
                dist[nx][ny] = dist[p.first][p.second] + 1;
            }
            if(nx==gx && ny==gy)return dist[gx][gy];
        }
    }
    return dist[gx][gy];
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> meiro[i][j];
            if(meiro[i][j]=='S'){
                sx = i;
                sy = j;
            }else if(meiro[i][j]=='G'){
                gx = i;
                gy = j;
            }
        }
    }
    int answer = solver();
    if(answer==INF){
        printf("ゴールに辿り着くことはできません。\n");
    }else{
        printf("ゴールまでの最短距離　＝　%d\n",answer);
    }
}