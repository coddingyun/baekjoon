#include <iostream>
#include <cmath>

#define NUMBER 100001

int dp[NUMBER+1];

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;

    dp[0] = 0;
    for (int i=1; i*i<=NUMBER; i++){
        dp[i*i] = 1;
    }
    
    for (int i=2; i<NUMBER; i++){
        if (dp[i] == 1) continue;
        dp[i] = dp[i-1]+1;
        // int check = floor(sqrt(i));
        // dp[i] = min(dp[i], 1+dp[i-check*check]);
        for (int j=0; j*j<=i; j++){
            dp[i] = min(dp[i], dp[i-j*j]+dp[j*j]);
        }
    }

    cout << dp[N] << "\n";

}