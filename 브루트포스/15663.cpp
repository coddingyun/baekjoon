#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int arr[9];
bool Select[9] = {false, false, false, false, false, false, false, false, false};
std::vector<int> V;

void Print(){
    for (long unsigned int i = 0; i < V.size(); i++)
    {
        std::cout << V[i] << " ";
    }
    std::cout<<"\n";
}

void DFS(int cnt, int N, int M){
    if (cnt == M){
        Print();
        return;
    }
    int xx = 0;
    for (int i = 0; i < N; i++){
        if (Select[i] || arr[i]==xx) continue;
        Select[i] = true;
        V.push_back(arr[i]);
        xx = arr[i];
        DFS(cnt + 1, N, M);
        V.pop_back();
        Select[i] = false;
    }
}
std::set<int> s;
int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    DFS(0, N, M);
}