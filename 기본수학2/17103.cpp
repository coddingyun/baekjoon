#include <iostream>

bool sosu[1000001];

int main(){
    using namespace std;
    int num;
    cin >> num;
    sosu[0] = sosu[1] = true;
    for (int j=2; j*j<1000001; j++){
        if (sosu[j] == false){
            for (int k=j*j; k<1000001; k+=j){
                sosu[k] = true;
            }
        }
    }
    for (int i=0; i<num; i++){
        int input;
        cin >> input;
        int result = 0;
        for (int j=2; j<=input/2; j++){
            if (sosu[j] == false && sosu[input-j] == false){
                result++;
            } else {
                continue;
            }
        }
        cout <<result << "\n";
    }
}