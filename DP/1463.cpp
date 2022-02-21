#include <iostream>
#include <algorithm>

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int *dp = new int[N+1];

    dp[1] = 0;
    for (int i=2; i<=N; i++){
        dp[i] = dp[i-1] + 1;
        if(!(i%3)) {
            dp[i] = min(dp[i], dp[i/3]+1);
        }
        if(!(i%2)){
            dp[i] = min(dp[i], dp[i/2]+1);
        }
    }
    cout << dp[N] << endl;  
    delete [] dp;
}
