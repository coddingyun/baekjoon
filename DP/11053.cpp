#include <iostream>

int arr[1005];
int dp[1005];

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> arr[i];
    }

    dp[1] = 1;
    int answer = 1;
    for (int i=2; i<=N; i++){
        dp[i] = 1; // 이거 넣으니까 맞음
        for (int j=1; j<i; j++){
            if (arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        answer = max(answer, dp[i]);
    }
    cout << answer << "\n";
}