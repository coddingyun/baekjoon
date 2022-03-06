#include <iostream>

#include <iostream>
#include<vector>

int Arr[9]={1,2,3,4,5,6,7,8,9};
//bool Select[9]={false,false,false,false,false,false,false,false,false};
std::vector<int> V;

void Print(){
    //std::cout << V.size() << "\n";
    for (long unsigned int i = 0; i < V.size(); i++)
    {
        std::cout << V[i] << " ";
    }
    std::cout<<"\n";
}

void DFS(int Cnt, int N, int M){
    if(Cnt == M){
        Print();
        return;
    }
    for(int i=0; i<N; i++){
        //if(Select[i]) continue;
        //Select[i]=true;
        V.push_back(Arr[i]);
        DFS(Cnt+1, N, M);
        //Select[i]=false;
        V.pop_back();
    }
}

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    DFS(0, N, M);
}