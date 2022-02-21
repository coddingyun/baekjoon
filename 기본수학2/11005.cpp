#include <iostream>
#include <string>
#include <algorithm>


int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    long long input, num;
    cin >> input >> num;
    string result;
    while (input>0) {
        if (input%num<10){
            result += to_string(input%num);
        }
        else {
            result += char((input%num)+55);
        }
        input /= num;
    }
    reverse(result.begin(), result.end());
    cout << result << "\n";
}