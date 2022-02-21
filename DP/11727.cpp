#include <iostream>

long long fibonacci(int n) {
    if (n==1) {
        return 1;
    }
    if (n==2) {
        return 3;
    }
    int first = 1;
    int second = 3;
    int result = 0;
    for (int i=0; i<n-2; i++) {
        result = (first*2 + second) % 10007;
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