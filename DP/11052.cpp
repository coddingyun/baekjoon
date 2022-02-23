#include <iostream>

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int *dp = new int[N+1];
    for (int i=1; i<=N; i++){
        int P;
        cin >> P;
        if (i==1) dp[i] = P;
        else {
            for (int k=0; k<=i/2; k++){
                if (k==0) dp[i] = P;
                else dp[i] = max(dp[i-k]+dp[k], dp[i]);
            }
        }
    }
    cout << dp[N] << endl;
    delete [] dp;
}