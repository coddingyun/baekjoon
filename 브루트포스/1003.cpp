#include <iostream>

int memo[41];
int memo2[41];

int fibonacci_0(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (memo[n] != 0) return memo[n];
    else {
        memo[n]=fibonacci_0(n-1)+fibonacci_0(n-2);
        return memo[n];
    }
}

int fibonacci_1(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (memo2[n] != 0) return memo2[n];
    else {
        memo2[n]=fibonacci_1(n-1)+fibonacci_1(n-2);
        return memo2[n];
    }
}

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        int a;
        cin >> a;
        cout << fibonacci_0(a) << " " << fibonacci_1(a) << "\n";
    }
}