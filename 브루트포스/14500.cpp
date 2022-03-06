#include <iostream>
#include <cmath>

int array[502][502];

bool check(int x, int y){
    if (x<1 || y<1 || x>500 || y>500) return false;
    return true;
}

int max=0;

void dfs(int x, int y, int N){
    if (N==0){
        return;
    }
    max=
    if (check(x, y)){
        dfs(x+1, y, N-1);
        dfs(x, y+1, N-1);
        dfs(x-1, y, N-1);
        dfs(x, y-1, N-1);   
    }
}

void functions(int cal){
    if (check(i-1,j)){
        cal += array[i-1][j];
        max = max(max,cal);
        cal -= array[i-1][j];
    }
    if (check(i+1,j)){
        cal += array[i+1][j];
        max = max(max,cal);
        cal -= array[i+1][j];
    }
    if (check(i,j-1)){
        cal += array[i][j-1];
        max = max(max,cal);
        cal -= array[i][j-1];
    }
    if (check(i,j+1)){
        cal += array[i][j+1];
        max = max(max,cal);
        cal -= array[i][j+1];
    }
}

void functions2(int cal){
    if (check(i-1,j)){
        cal += array[i-1][j];
        functions(cal);
        cal -= array[i-1][j];
    }
    if (check(i+1,j)){
        cal += array[i+1][j];
        functions(cal);
        cal -= array[i+1][j];
    }
    if (check(i,j-1)){
        cal += array[i][j-1];
        functions(cal);
        cal -= array[i][j-1];
    }
    if (check(i,j+1)){
        cal += array[i][j+1];
        functions(cal);
        cal -= array[i][j+1];
    }
}

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;
    for (int i=0; i<a; i++){
        for (int j=0; j<b; j++){
            cin >> array[i][j];
        }
    }
    int max = 0;
    for (int i=0; i<a; i++){
        for (int j=0; j<b; j++){
            int cal = array[i][j];
            if (check(i-1,j)){
                cal += array[i-1][j];
                functions2(cal);
                cal -= array[i-1][j];
            }
            if (check(i+1,j)){
                cal += array[i+1][j];
                functions2(cal);
                cal -= array[i+1][j];
            }
            if (check(i,j-1)){
                cal += array[i][j-1];
                functions2(cal);
                cal -= array[i][j-1];
            }
            if (check(i,j+1)){
                cal += array[i][j+1];
                functions2(cal);
                cal -= array[i][j+1];
            }            
        }
    }
    cout << max << "\n";
}