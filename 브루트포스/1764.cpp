#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

string listen_list[500001];
set<string> see_list;

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int no_listen, no_see;
    cin >> no_listen >> no_see;

    for (int i=0; i<no_listen; i++){
        cin >> listen_list[i];
    }
    for (int i=0; i<no_see; i++){
        string a;
        cin >> a;
        see_list.insert(a);
    }
    vector<string> answer_list;
    for (int i=0; i<no_see; i++){
        if (see_list.count(listen_list[i])){
            answer_list.push_back(listen_list[i]);
        }
    }
    sort(answer_list.begin(), answer_list.end());
    cout << answer_list.size() << "\n";
    for (int i=0; i<answer_list.size(); i++){
        cout << answer_list[i] << "\n";
    }
}