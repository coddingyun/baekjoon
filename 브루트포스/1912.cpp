#include <iostream>
#include <climits>

int arr[100001];
int dp[100001];

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }
    //long long answer = LLONG_MIN;
    dp[0] = arr[0];
    long long answer = dp[0];
    for (int i=1; i<N; i++){
        dp[i]=arr[i];
        dp[i]=max(dp[i],dp[i-1]+arr[i]);
        if (answer<dp[i]){
            answer=dp[i];
        }
        //answer=max(answer,dp[i]);
    }
    cout << answer << "\n";
}