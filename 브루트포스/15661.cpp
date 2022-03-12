#include <iostream>
#include <vector>
#include <algorithm>

int arr[21][21];
bool Select1[21];
bool Select2[21];

std::vector<int> v;

void DFS(int Idx, int cnt, int N, int M){
    if (cnt == M){
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (Select1[i] && Select2[j]){
                    sum1 += arr[i][j];
                }
            }
        }
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (Select1[i]==false && Select2[j]==false){
                    sum2 += arr[i][j];
                }
            }
        }
        v.push_back(abs(sum1 - sum2));
        return;
    }
    for (int i = Idx; i < N; i++){
        if (Select1[i] == true) continue;
        Select1[i] = true;
        Select2[i] = true;
        DFS(i, cnt + 1, N, M);
        Select1[i] = false;
        Select2[i] = false;
    }
}

int main(){
    using namespace std;
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    DFS(0, 0, N, N/2);
    int minor = INT16_MAX;
    for (int i=0; i<=N/2; i++){
        DFS(0, 0, N, i);
    }
    for (int i=0; i<v.size(); i++){
        if (v[i] < minor){
            minor = v[i];
        }
    }
    cout << minor << '\n';
}