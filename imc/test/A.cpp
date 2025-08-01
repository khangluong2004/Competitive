#include <bits/stdc++.h>

#define fast_cin()                                                                                                     \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)

using namespace std;

int main(){
    fast_cin();
    int n_ropes, time_int;
    cin >> n_ropes;
    cin >> time_int;

    unordered_set<int> seen;

    int cur_rope = -1;
    for (int i=0; i < n_ropes; i++){
        cin >> cur_rope;
        if (seen.empty()){
            seen.insert(cur_rope);
            continue;
        }
        
        if (seen.count(time_int - cur_rope) == 1){
            cout << "YES" << endl;
            cout << cur_rope << " " << time_int - cur_rope << endl;
            return 0;
        }

        seen.insert(cur_rope);
    }

    cout << "NO" << endl;
    return 0;
}