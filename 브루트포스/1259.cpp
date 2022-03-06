#include <iostream>

int main(){
    using namespace std;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    bool flag = true;
    while (s!="0"){
        for (long unsigned int i=0; i<=s.length()/2; i++){
            if (s[i] != s[s.length()-1-i]){
                cout << "no" << endl;
                flag=false;
                break;
            }
        }
        if (flag) cout << "yes" << endl;
        flag = true;
        cin >> s;
    }
}