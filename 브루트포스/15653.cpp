#include <iostream>
#include<vector>
#include <queue>

using namespace std;
int Arr[9];
bool Select[9]={false,false,false,false,false,false,false,false,false};
std::vector<int> V;

void Print(int N){
    for (long unsigned int i = 0; i < V.size(); i++)
    {
        std::cout << V[i] << " ";
    }
    std::cout<<"\n";
}

void DFS(int Cnt, int N, int M){
    if(Cnt == M){
        Print(N);
        return;
    }
    for(int i=0; i<N; i++){
        if(Select[i]) continue;
        Select[i]=true;
        V.push_back(Arr[i]);
        DFS(Cnt+1, N, M);
        Select[i]=false;
        V.pop_back();
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
        Arr[i] = q.top();
        q.pop();
    }
    DFS(0, N, M);
}