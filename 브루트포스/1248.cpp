#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

bool Select[10];
std::vector<int> V;
std::vector<int> result;
std::string A;



bool check(){
    int index = 0;
    for (long unsigned int i = 0; i < V.size(); i++)
    {
        for (long unsigned int j = i; j < V.size(); j++)
        {
            int sum = accumulate(V.begin()+i , V.begin()+j+1,0);
            if(A[index] == '-') {
                if(sum>=0) return false;
            }else if(A[index] == '0') {
                if(sum !=0) return false;
            } else {
                if(sum <= 0) return false;
            }
            index++;
        }
    }
    return true;
}

void Print(){
    for (long unsigned int i=0; i<V.size(); i++) {
        std::cout << V[i] << " ";
    }
}

void DFS(int cnt, int N){
    if (cnt==N) {
        Print();
        exit(0);
    }
    for (int i = -10; i <= 10; i++){
        V.push_back(i);
        if (check()) {
            DFS(cnt + 1, N);
        }
        V.pop_back();
    }
}

int main(){
    using namespace std;
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int N;
    cin >> N;
    cin >> A;
    DFS(0, N);
}