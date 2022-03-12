#include <iostream>
#include <vector>
#include <algorithm>
bool arr[2001][2001];
bool check[2001];
int counter = 0;
int N,M;
std::vector<int> V[2001];
bool ans=false;

void DFS(int num, int cnt){
    if (cnt == 4){
        ans=true;
        return;
    }
    for (int i = 0; i < V[num].size(); i++){
        int next = V[num][i];
        if (!check[next]){
            check[next] = true;
            DFS(next, cnt+1);
            check[next] = false;
        }
    }
}

int main(){
    using namespace std;
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i=0; i<M; i++){
        int A,B;
        cin >> A >> B;
        V[A].push_back(B); //2차원 배열을 사용하면, 주어진 모든 사람들을 조사해야한다. 그래서 벡터를 사용하는 것이다.
        V[B].push_back(A);
    }
    for (int i=0; i<N; i++){
        for (int i=0; i<N; i++){
            check[i] = false;
        }
        check[i] = true;
        DFS(i,0);
        if (ans) break;
    }
    if (ans) cout << 1 << '\n';
    else cout << 0 << '\n';
}
