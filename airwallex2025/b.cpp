#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);  
    int n, k; 
    cin >> n >> k;
    vector<int> v(2000001, 0);

    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        v[k]++;
    }
    vector<pair<int, int>> thing;

    for(int i = 0; i < 2000001; i++) {
        if(v[i] > 0) {
            thing.push_back({i, v[i]});
        }
    }

    int tot = 0;
    int val = -1;
    for(int i = 0; i < n; i++) {
        tot += thing[i].second;
        if(2 * tot - n > k) {
            val = thing[i].first - 1;
            break;
        }
    }
    cout << val << endl;
    return 0;
}