#include <iostream>
#include <string>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    char field[N][M];
    for(int a=0; a<N; a++){
        for(int b=0; b<M; b++){
            cin >> field[a][b];
        }
    }
    void dfs(int i, int j){
        field[i][j] = '.';
        for(int rx=-1; rx<=1; rx++){
            for(int ry=-1; ry<=1; ry++){
                int x = i + rx;
                int y = j + ry;
                if(x>=0 && y>=0 && x<N && y<M && field[x][y]=='w')dfs(x,y);
            }
        }
    }

    int count = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(field[i][j]=='w'){
                count++;
                dfs(i,j);
            }
        }
    }
    printf("the number of lake is %d\n",count);
}