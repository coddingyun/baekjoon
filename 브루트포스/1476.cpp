#include <iostream>
#include <climits>

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int E, S, M;
    cin >> E >> S >> M;
    if (E==15) E-=15;
    if (S==28) S-=28;
    if (M==19) M-=19;
    for (long long i=1; i<LLONG_MAX; i++){
        if (i%15==E && i%28==S && i%19==M){
            cout << i << "\n";
            return 0;
        } 
    }
}