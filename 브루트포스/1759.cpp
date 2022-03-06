#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

char arr[16];
bool Select[27];
std::vector<char> V;

bool check(std::vector<char> v){
    int num1=0;
    int num2=0;
    for (long unsigned int i = 0; i < v.size(); i++){
        if (v[i] == 'a'||v[i] == 'e'||v[i] == 'i' || v[i] =='o' || v[i]=='u') num1++;
        else num2++;
    }
    if (num1>=1 && num2>=2) return true;
    return false;
}

void DFS(int Idx, int cnt, int N, int M){
    if (cnt == M){
        if (check(V)){
            for (long unsigned int i = 0; i < V.size(); i++)
            {
                std::cout << V[i];
            }
            std::cout<<"\n";
        }
        return;
    }
    for (int i = Idx; i < N; i++){
        if (Select[i]) continue;
        Select[i] = true;
        V.push_back(arr[i]);
        DFS(i, cnt + 1, N, M);
        V.pop_back();
        Select[i] = false;
    }
}

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i=0; i<M; i++){
        cin >> arr[i];
    }
    sort(arr, arr+M);
    DFS(0, 0, M, N);
}