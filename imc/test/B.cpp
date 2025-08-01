#include <bits/stdc++.h>
using namespace std;

#define fast_cin()                                                                                                     \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)

int main(){
    fast_cin();
    int n;
    cin >> n;
    unordered_map<int, int> countVect;
    int maxCharm = 0;

    int cur;
    for (int i=0; i < n; i++){
        cin >> cur;
        countVect[cur] += 1;
    }

    for (auto& pair: countVect){
        if (pair.first == pair.second){
            maxCharm = max(maxCharm, pair.first);
        }
    }

    cout << maxCharm << endl;
    return 0;
}