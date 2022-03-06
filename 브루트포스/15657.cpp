#include <iostream>
#include <vector>
#include <algorithm>

int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
bool Select[9] = {false, false, false, false, false, false, false, false, false};
std::vector<int> V;

void Print(){
    for (long unsigned int i = 0; i < V.size(); i++)
    {
        std::cout << V[i] << " ";
    }
    std::cout<<"\n";
}

void DFS(int Idx, int cnt, int N, int M){
    if (cnt == M){
        Print();
        return;
    }
    for (int i = Idx; i < N; i++){
        // if (Select[i]) continue;
        // Select[i] = true;
        V.push_back(arr[i]);
        DFS(i, cnt + 1, N, M);
        V.pop_back();
        //Select[i] = false;
    }
}

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    DFS(0, 0, N, M);
}