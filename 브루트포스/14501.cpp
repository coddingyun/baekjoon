#include <iostream>
#include <vector>

int arr_time[21];
int arr_money[21];
bool Select[21];

std::vector<int> v;

void DFS(int Idx, int N){
    if (Idx >= N){
        int sum = 0;
        for (int i = 0; i < N; i++){
            if (Select[i]){
                sum += arr_money[i];
            }
        }
        v.push_back(sum);
        return;
    }
    for (int i = Idx; i < N; i++){
        int time = arr_time[i];
        if (i + time > N) ;
        else Select[i] = true;
        DFS(i + time, N);
        Select[i] = false;
    }
}


int main(){
    using namespace std;
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int total_num;
    cin >> total_num;
    for (int i=0; i<total_num; i++){
        cin >> arr_time[i] >> arr_money[i];
    }
    DFS(0, total_num);
    int max = 0;
    for (int i=0; i<v.size(); i++){
        if (v[i] > max){
            max = v[i];
        }
    }
    cout << max << '\n';
}