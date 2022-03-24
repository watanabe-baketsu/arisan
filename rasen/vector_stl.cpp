#include <iostream>
#include <vector>
using namespace std;

void print(vector<double> V){
    for (int i=0;i<V.size();i++) cout << V[i] << " ";
    cout << endl;
}

int main(){
    vector<double> V;

    V.push_back(0.1);
    V.push_back(0.2);
    V.push_back(0.3);

    cout << "This is a first V\n";
    print(V);
    cout << "\n";

    V.insert(V.begin()+2, 0.25);
    cout << "This is a second V\n";
    print(V);
    cout << "\n";

    V.erase(V.begin()+2);
    cout << "This is a third V\n";
    print(V);
    cout << "\n";

    return 0;
}