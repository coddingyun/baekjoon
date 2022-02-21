#include <iostream>

int number(int x){
    if (x==1) return 1;
    if (x==2) return 2;
    if (x==3) return 4;
    int first = 1;
    int second = 2;
    int third = 4;
    int result = 0;
    for (int i=0; i<x-3; i++) {
        result = first + second + third;
        first = second;
        second = third;
        third = result;
    }
    return result;
}

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i=0; i<T; i++){
        int n;
        cin >> n;
        cout << number(n) << endl;
    }
}