#include <iostream>

long long dp[100001][4];

long long card (int n){
    if (n==1) {
        return 1;
    }
    if (n==2) {
        return 1;
    }
    if (n==3) {
        return 3;
    }
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;
    dp[2][1] = 0;
    dp[2][2] = 1;
    dp[2][3] = 0;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for (long long k=4; k<=n; k++){
        dp[k][1] = (dp[k-1][2] +dp[k-1][3])% 1000000009;
        dp[k][2] = (dp[k-2][1] +dp[k-2][3])% 1000000009;
        dp[k][3] = (dp[k-3][1] +dp[k-3][2])% 1000000009;
    }
    return (dp[n][1]+dp[n][2]+dp[n][3])%1000000009; //더한게 10000000009 넘을 수 있다!!!
}

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int test_case;
    cin >> test_case;
    for (int i=0; i<test_case; i++){
        int n;
        cin >> n;  
        cout << card(n) << endl;
    }
}