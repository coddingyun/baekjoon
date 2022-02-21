#include <iostream>
#include <cmath>

int main(){
    using namespace std;
    string input;
    int num;
    cin >> input >> num;
    long long result=0;
    for (int i=input.size()-1; i>=0; i--){
        if (input[i]-'0' <10){
            result += (input[i]-'0')*pow(num, input.size()-i-1);
        }
        else{
            result += ((int)input[i]-55)*pow(num, input.size()-i-1);
        }
    }
    cout << result << endl;
}