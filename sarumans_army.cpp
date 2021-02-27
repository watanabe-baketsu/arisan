#include <iostream>
using namespace std;

int main(){
    int N,R;
    cin >> N >> R;
    int x[N];
    for(int i=0;i<N;i++)cin >> x[i];
    int count = 0, mark = 0, i = 1;
    while(x[0]+R<x[i] && i<N)i++;
    mark = i;
    printf("mark : %d\n",x[mark]);
    count++;
    while(i<N){
        if(x[mark]+R<x[i]){
            mark = i;
            printf("mark : %d\n",x[mark]);
            count++;
            i++;
        }else i++;
    }
    printf("num of mark : %d\n",count);
}