#include <iostream>
#include <set>

using namespace std;

set<int> answer_set;
set<int> all_set = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        string s;
        cin >> s;
        if (s=="add"){
            int a;
            cin >> a;
            answer_set.insert(a);
        }
        else if (s=="remove"){
            int a;
            cin >> a;
            answer_set.erase(a);
        }
        else if (s=="check"){
            int a;
            cin >> a;
            cout << answer_set.count(a) << "\n";
        }
        else if (s=="toggle"){
            int a;
            cin >> a;
            if (answer_set.count(a)) answer_set.erase(a);
            else answer_set.insert(a);
        }
        else if (s=="all"){
            answer_set = all_set;
        }
        else if (s=="empty"){
            answer_set.clear();
        }
    }
}