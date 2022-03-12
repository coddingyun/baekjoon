#include <iostream>
bool arr[1001][1001];
bool check[1001];
int counter = 0;
int N,M;

void DFS(int num){
    check[num] = true;
    for (int i = 1; i <= N; i++){
        if (arr[num][i] && !check[i]){
            DFS(i);
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
        arr[A][B] = true;
        arr[B][A] = true;
    }
    for (int i=1; i<=N; i++){
        if (!check[i]){
            counter++;
            DFS(i);
        }
    }
    cout << counter << '\n';
}