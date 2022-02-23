#include <iostream>

#define MOD 1000000000
#define endl "\n"

long long dp[101][10];

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[1][4] = 1;
    dp[1][5] = 1;
    dp[1][6] = 1;
    dp[1][7] = 1;
    dp[1][8] = 1;
    dp[1][9] = 1;
    for (int i=2; i<=100; i++){
        dp[i][0] = (dp[i-1][1])%MOD;
        dp[i][1] = (dp[i-1][0]+dp[i-1][2])%MOD;
        dp[i][2] = (dp[i-1][1]+dp[i-1][3])%MOD;
        dp[i][3] = (dp[i-1][2]+dp[i-1][4])%MOD;
        dp[i][4] = (dp[i-1][3]+dp[i-1][5])%MOD;
        dp[i][5] = (dp[i-1][4]+dp[i-1][6])%MOD;
        dp[i][6] = (dp[i-1][5]+dp[i-1][7])%MOD;
        dp[i][7] = (dp[i-1][6]+dp[i-1][8])%MOD;
        dp[i][8] = (dp[i-1][7]+dp[i-1][9])%MOD;
        dp[i][9] = (dp[i-1][8])%MOD;
    }
    cout << (dp[N][0]+dp[N][1]+dp[N][2]+dp[N][3]+dp[N][4]+dp[N][5]+dp[N][6]+dp[N][7]+dp[N][8]+dp[N][9])%MOD << endl;
}