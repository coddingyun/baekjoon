#include <iostream>

int find_max_number(char **arr, int N){
    int max = 0;
    char c;
    for (int i=0; i<N; i++){
        int cnt = 1;
        c=arr[i][0];
        for (int j=1; j<N; j++){
            if (arr[i][j]==c){
                cnt++;
            }
            else{
                c=arr[i][j];
                cnt=1;
            }
            if (cnt>max){
                max=cnt;
            }
        }
    }

    for (int i=0; i<N; i++){
        int cnt = 1;
        c=arr[0][i];
        for (int j=1; j<N; j++){
            if (arr[j][i]==c){
                cnt++;
            }
            else{
                c=arr[j][i];
                cnt=1;
            }
            if (cnt>max){
                max=cnt;
            }
        }
    }

    return max;
}

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    char **arr = new char *[N];
    for (int i=0; i<N; i++){
        arr[i] = new char[N];
    }
    
    for (int i=0; i<N; i++){
        string a;
        cin >> a;
        for (int j=0; j<N; j++){
            arr[i][j] = a[j];
        }
    }
    int max = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<N-1; j++){
            int tmp = arr[i][j];
            arr[i][j] = arr[i][j+1];
            arr[i][j+1] = tmp;
            max = max > find_max_number(arr, N) ? max : find_max_number(arr, N);
            int tmp2 = arr[i][j];
            arr[i][j] = arr[i][j+1];
            arr[i][j+1] = tmp2;
        }
    }

    for (int i=0; i<N-1; i++){
        for (int j=0; j<N; j++){
            int tmp = arr[i][j];
            arr[i][j] = arr[i+1][j];
            arr[i+1][j] = tmp;
            max = max > find_max_number(arr, N) ? max : find_max_number(arr, N);
            int tmp2 = arr[i][j];
            arr[i][j] = arr[i+1][j];
            arr[i+1][j] = tmp2;
        }
    }

    cout << max << '\n';

    for (int i=0; i<N; i++){
        delete [] arr[i];
    }
    delete [] arr;
}