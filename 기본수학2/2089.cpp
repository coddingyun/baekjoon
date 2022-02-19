#include <iostream>
#include <algorithm>
int main(){
    using namespace std;
    int n;
    cin >> n;
    if (n==0) {
        cout << 0 << "\n";
        return 0;
    }
    string i;
    while(n!=0) {
        if(n%-2 == 0)
        {   
            i += "0";
            n /= -2;
        }else
        {
            i+= "1";
            n = (n-1) / -2;
        }
    }
    reverse(i.begin(), i.end());
    cout << i << "\n";
}