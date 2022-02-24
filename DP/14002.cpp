#include <iostream>

int arr[1005];
int dp[1005][1005];

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> arr[i];
    }

    dp[1][0] = 1;
    dp[1][1] = arr[1];
    int answer = 1;
    int check = 1;
    for (int i=2; i<=N; i++){
        dp[i][0] = 1;
        dp[i][1] = arr[i];
        for (int j=1; j<i; j++){
            if (arr[j] < arr[i]){
                if (dp[i][0] < dp[j][0]+1){
                    dp[i][0] = dp[j][0]+1;
                    for (int k=1; k<=1005; k++){
                        if (dp[j][k] == 0) {
                            dp[i][k] = arr[i];
                            break;
                        }
                        dp[i][k] = dp[j][k];
                    }
                }
                //dp[i][0] = max(dp[i][0], dp[j][0]+1);
            }
        }
        if (answer < dp[i][0]){
            answer = dp[i][0];
            check = i;
        }
        //answer = max(answer, dp[i][0]);
    }
    cout << answer << "\n";
    for (int i=1; i<=1004; i++){
        if (dp[check][i] == 0) break;
        cout << dp[check][i] << " ";
    }

    
}