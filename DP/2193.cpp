#include <iostream>

long long dp[91][2];
int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    dp[1][1] = 1;
    for (int i=2; i<=90; i++){
        dp[i][0] = dp[i-1][1] + dp[i-1][0];
        dp[i][1] = dp[i-1][0];
    }
    cout << dp[N][0]+dp[N][1] << "\n";
}