#include <iostream>
#include <cmath>
#include <string>

using namespace std;
bool broken_num_array[11];

bool check(int x){
    string s = to_string(x);
    int len = s.length();
    for (int i=0; i<len; i++){
        if (broken_num_array[s[i]-48]) return false;
    }
    return true;

}

int main(){
    int target_num, broken_total_num;
    cin >> target_num >> broken_total_num;
    for (int i=0; i<broken_total_num; i++){
        int broken_num;
        cin >> broken_num;
        broken_num_array[broken_num] = true;
    }

    int min = abs(target_num-100);

    for (int i=0; i<=1000000; i++){
        if (check(i)){
            int diff = abs(target_num-i)+to_string(i).length();
            if (diff<min){
                min = diff;
            }
        }
    }

    cout << min << "\n";


}