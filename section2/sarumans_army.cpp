#include <iostream>
using namespace std;

int main(){
    int n,r;
    cin >> n >> r;
    int x[n];
    for(int i=0;i<n;i++)cin >> x[i];
    int count=0,mark=0,i=1;
    while(i<n && x[mark]+r>=x[i])i++;
    mark = i-1;
    count++;
    while(i<n){
        if(x[mark]+r<x[i]){
            mark = i;
            count++;
        }
        i++;
    }
    printf("%d",count);
}