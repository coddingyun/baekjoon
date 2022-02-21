#include <iostream>

long long fibonacci(int n) {
    if (n<=1) {
        return 1;
    }
    int first = 1;
    int second = 1;
    int result = 0;
    for (int i=0; i<n-1; i++) {
        result = (first + second) % 10007;
        first = second;
        second = result;
    }
    return result;
}

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
}