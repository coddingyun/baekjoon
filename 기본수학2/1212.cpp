#include <iostream>

void eight_to_two(int n){
    using namespace std;
    int temp;
    if ((n)/4>=1){
        cout << "1";
        temp = (n)%4;
    }
    else {
        cout << "0";
        temp = (n)%4;
    }
    if (temp/2==1){
        cout << "1";
        temp = temp%2;
    }
    else cout << "0";
    if (temp==1){
        cout << "1";
    }
    else cout << "0";
}

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string input;
    cin >> input;
    int arr_first = input[0]-'0';
    int remain;
    if (arr_first/4>=1) {
        eight_to_two(arr_first);
    }
    else {
        remain = arr_first;
        if (remain /2>=1) {
            cout << "1";
            remain = remain%2;
            if (remain==1) {
                cout << "1";
            }
            else cout << "0";
        }
        else {
            if (remain==1) {
                cout << "1";
            }
            else cout << "0";
        }
    }
    for (int i=1; i<input.size(); i++){
        eight_to_two(input[i]-'0');
    }
    cout << "\n";
}