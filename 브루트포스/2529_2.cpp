#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

std::string arr[10];
bool Select[10];
std::vector<int> V;
std::vector<std::string> result;

void Print(){
    bool check = true;
    for (long unsigned int i = 0; i < V.size(); i++)
    {
        if (i>=1){
            if (arr[i]==">" && V[i-1] < V[i]){
                check = false;
                break;
            }
            else if (arr[i]=="<" && V[i-1] > V[i]){
                check = false;
                break;
            }
        }
    }
    if (check) {
        std::string sum = "";
        for (long unsigned int i = 0; i < V.size(); i++)
        {
            sum+=std::to_string(V[i]);
        }
        result.push_back(sum);
    }
    
}

void DFS(int cnt, int N){
    if (cnt == N){
        Print();
        return;
    }
    for (int i = 0; i < 10; i++){
        if (Select[i]) continue;
        Select[i] = true;
        V.push_back(i);
        DFS(cnt + 1, N);
        V.pop_back();
        Select[i] = false;
    }
}

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int k;
    cin >> k;
    for (int i=1; i<=k; i++){
        cin >> arr[i];
    }
    DFS(0, k+1);
    sort(result.begin(), result.end());
    cout << result[result.size()-1] << '\n';
    cout << result[0] << '\n';
}