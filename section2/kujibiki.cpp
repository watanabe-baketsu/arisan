#include <iostream>
using namespace std;

int main(){
    int max_n = 50;
    int n, m;
    int k[max_n];
    cin >> n >> m;
    int i = 0;
    int l;
    while(cin>>l){
        k[i] = l;
        printf("%d\n",k[i]);
        i++;
    }
    int a[n*n];
    int b = 0;
    for(i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[b] = k[i]+k[j];
            b++;
        }
    }
    int buff;
    for(i=0;i<n*n;i++){
        for(int j=(n*n)-1;j>i;j--){
            buff = a[j];
            if(a[j]<a[j-1]){
                a[j] = a[j-1];
                a[j-1] = buff;
            }
        }
    }
    l =0;
    int r = n*n;
    for(i=0;i<(n*n)-1;i++){
        
        while(r-1>=1){
            int c = (l+r)/2;
            if(a[c] == m-a[i]){
                printf("True\n");
                return 0;
            }else if(a[c] < m-a[i]){
                l = c + 1;
            }else{
                r = c;
            }
        }
    }
    printf("False");

}