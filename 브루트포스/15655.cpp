#include <iostream>
#include <queue>

int arr[9];
bool Select[9] = {false, false, false, false, false, false, false, false, false};

void Print(){
    for (int i = 0; i < 9; i++)
    {
        if (Select[i])
            std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void DFS(int Idx, int cnt, int N, int M){
    if (cnt == M){
        Print();
        return;
    }
    for (int i = Idx; i < N; i++){
        if (Select[i]) continue;
        Select[i] = true;
        DFS(i, cnt + 1, N, M);
        Select[i] = false;
    }
}

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    priority_queue<int> q;
    for (int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }
    for (int i=N-1; i>=0; i--){
        arr[i] = q.top();
        q.pop();
    }
    DFS(0, 0, N, M);
}