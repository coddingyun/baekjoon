#include <iostream>
#include <algorithm>

int height[9];

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int sum=0;
    for (int i=0; i<9; i++){
        cin >> height[i];
        sum+=height[i];
    }
    int arr[7];
    for (int i=0; i<9; i++){
        for (int j=i+1; j<9; j++){
            if (sum-height[i]-height[j]==100){
                int cnt=0;
                for (int k=0; k<9; k++){
                    if (k!=i && k!=j){
                        arr[cnt]=height[k];
                        cnt++;
                    }
                }
                break;
            }
        }
    }
    sort(arr,arr+7);
    for (int i=0; i<7; i++){
        cout << arr[i] << '\n';
    }
}