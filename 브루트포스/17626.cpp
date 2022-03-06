#include <iostream>
#include <algorithm>

int dp[50001];

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i=0; i*i<N+1; i++){
        dp[i*i]=1;
    }
    for (int i=0; i<N+1; i++){
        if (dp[i]==0){
            int minn = dp[i-1]+1;
            for (int j=1; j*j<i; j+=1){
                minn = min(minn, dp[j*j]+dp[i-j*j]);
            }
            dp[i]=minn;
        }
    }
    cout << dp[N] << "\n";
}