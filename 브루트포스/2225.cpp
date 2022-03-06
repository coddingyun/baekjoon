#include <iostream>

long long arr[201][201];

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N,K;
    cin >> N >> K;
    
    for (int i=0; i<=N; i++){
        arr[1][i] = 1;
    }

    for (int i=2; i<=K; i++){
        for (int j=0; j<=N; j++){
            for (int k=0; k<=j; k++){
                arr[i][j] += arr[i-1][k];
            }
            arr[i][j] %= 1000000000;
        }
    }
    cout << arr[K][N] << '\n';
}